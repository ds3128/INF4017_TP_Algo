#include <iostream>
#include <vector>
#include "prim.h"
#include "limits.h"

using namespace std;

int main(){

    int n, **mat_adj, *pere;
    cout << "Entrer le nombre de sommet du graphe >> ";
    cin >> n;
    mat_adj = creerMatrice(n, n);
    cout << endl;
    //remplissage de la matrice
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){

            cout << "Entrer le poids de l'arrete " << i+1 << " --- " << j+1 << " >> ";
            cin >> mat_adj[i][j];
            if(mat_adj[i][j] == -1){
                mat_adj[i][j] = INT_MAX;
            }
            mat_adj[j][i] = mat_adj[i][j];
        }
        mat_adj[i][i] = INT_MAX;
    }

    //Affichage de la matrice
    cout << "La matrice resultante est : " << endl;
    for(int i = 0; i < n; i++){
        cout << endl;
        for(int j = 0; j < n; j++){
            if(mat_adj[i][j] == INT_MAX){
                cout << "\too";
            }
            else
                cout << "\t" << mat_adj[i][j];
        }
    }
    bool *visited = new bool[n];
    for(int i = 0 ; i < n ; i++)
        visited[i] = false;
    pere = prim( mat_adj, n );
    cout << endl << "L'arbre couvrant de poids minimal est l'arbre constitue des liens suivants : " << endl << endl;
    cout << endl << "N.B : La notation a <--- b signifie que a est le pere de b." << endl << endl;
    for(int i = 0 ; i < n ; i++) {
        cout << (pere[i] == -1 ? "NULL" : to_string(pere[i]+1)) << "\t<<---\t" << i+1 << endl;
    }
    cout << endl << "Cet arbre couvrant est de poids : " << dmin(pere , mat_adj, n ) << endl;
    return 0;
}

vector<int> adj_noeud( int i, int **mat_adj, bool *visited, int n ) {
    // Conna�tre les noeuds adjacents � un noeud i et pas encore visit�s.

    vector<int> res = {};
    for(int j = 0 ; j < n ; j++)
    {
        if ( mat_adj[i][j] != INT_MAX && !visited[j] )
            res.insert(res.end(), j);
    }
    return res;
}

int *prim( int **mat_adj, int n )
{
    int i = 0, j = 0, min_poids_j = INT_MAX, dmin = 0, indice_min_poids_j = 0, pere_min_poids_j = 0, *pere = new int[n];
    vector<int> noeuds_visites = {0}, noeuds_adj = {};
    bool visite = true, *visited = new bool[n];  // On a visit� un noeud ou pas.
    for(i = 0 ; i < n ; i++) visited[i] = false; // Initialisation.
    visited[0] = true;  // On a d�j� visit� le noeud 0.
    pere[0] = -1; // Le noeud 0 est la racine.
    while(visite)
    {
        visite = false; // On suppose qu'on ne va visiter aucun.
        min_poids_j = INT_MAX; //Infini.
        for ( int l = 0 ; l < noeuds_visites.size() ; l++ ) { // Pour chaque noeud i d�j� visit�.
            i = noeuds_visites[l];
            noeuds_adj = adj_noeud(i, mat_adj, visited, n);
            for ( int k = 0 ; k < noeuds_adj.size() ; k++ ) { // On regarde dans l'ensemble de ses sommets adjacents � i, celui qui a le plus petit poids et on compare avec le plus petit jusqu'� pr�sent.
                j = noeuds_adj[k];
                if( mat_adj[i][j] < min_poids_j ) {
                    min_poids_j = mat_adj[i][j];
                    pere_min_poids_j = i;
                    indice_min_poids_j = j;
                }
                visite = true; // On a visit� un nouveau noeud.
            }
        }
        if ( visite ) {
            dmin += min_poids_j;
            visited[indice_min_poids_j] = true;
            noeuds_visites.insert(noeuds_visites.end(), indice_min_poids_j);
            pere[indice_min_poids_j] = pere_min_poids_j;
        }
    }
    return pere; // On retourne l'ensemble des parents des noeuds.
}

int dmin( int *pere, int **mat_adj, int n )
{
    // Calcul du poids de l'arbre.
    if (n == 1)
        return 0; // S'il n'y a qu'un seul noeud le poids c'est 0.
    else {
        return mat_adj[pere[n-1]][n-1] + dmin(pere, mat_adj, n - 1);
    }
}

int **creerMatrice(int n, int m) {
    int **M = (int **)malloc(n*sizeof(M));
    for(int i = 0; i<n ; i++)
    {
        M[i] = (int *)malloc(m*sizeof(int *));
    }
    return M;
}
