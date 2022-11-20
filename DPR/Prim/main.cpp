#include <iostream>
#include <vector>
#include "prim.h"
#include "limits.h"

using namespace std;

int main()
{
    int n = 3, **mat_adj, *pere;
    mat_adj = creerMatrice(n, n);
    mat_adj[0][0] = INT_MAX;
    mat_adj[0][1] = 7;
    mat_adj[0][2] = 5;
    mat_adj[1][0] = 7;
    mat_adj[1][1] = INT_MAX;
    mat_adj[1][2] = 9;
    mat_adj[2][0] = 5;
    mat_adj[2][1] = 9;
    mat_adj[2][2] = INT_MAX;
    bool *visited = new bool[n];
    for(int i = 0 ; i < n ; i++) visited[i] = false;
    pere = prim( mat_adj, n );
    cout << endl << "L'arbre couvrant de poids minimal est l'arbre constitue des liens suivants : " << endl << endl;
    cout << endl << "N.B : La notation a <--- b signifie que a est le pere de b." << endl << endl;
    for(int i = 0 ; i < n ; i++) {
        cout << (pere[i] == -1 ? "NULL" : to_string(pere[i])) << "\t<<---\t" << i << endl;
    }
    cout << endl << "Cet arbre couvrant est de poids : " << dmin(pere , mat_adj, n ) << endl;
    return 0;
}

vector<int> adj_noeud( int i, int **mat_adj, bool *visited, int n ) {
    // Connaître les noeuds adjacents à un noeud i et pas encore visités.

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
    bool visite = true, *visited = new bool[n];  // On a visité un noeud ou pas.
    for(i = 0 ; i < n ; i++) visited[i] = false; // Initialisation.
    visited[0] = true;  // On a déjà visité le noeud 0.
    pere[0] = -1; // Le noeud 0 est la racine.
    while(visite)
    {
        visite = false; // On suppose qu'on ne va visiter aucun.
        min_poids_j = INT_MAX; //Infini.
        for ( int l = 0 ; l < noeuds_visites.size() ; l++ ) { // Pour chaque noeud i déjà visité.
            i = noeuds_visites[l];
            noeuds_adj = adj_noeud(i, mat_adj, visited, n);
            for ( int k = 0 ; k < noeuds_adj.size() ; k++ ) { // On regarde dans l'ensemble de ses sommets adjacents à i, celui qui a le plus petit poids et on compare avec le plus petit jusqu'à présent.
                j = noeuds_adj[k];
                if( mat_adj[i][j] < min_poids_j ) {
                    min_poids_j = mat_adj[i][j];
                    pere_min_poids_j = i;
                    indice_min_poids_j = j;
                }
                visite = true; // On a visité un nouveau noeud.
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
