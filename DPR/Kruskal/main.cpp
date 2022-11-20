#include <iostream>
#include <vector>
#include "kruskal.h"
#include "limits.h"

using namespace std;

int main()
{
    int n = 3, **mat_adj;
    vector<Arete> arbre = {}, graphe = {};
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

    for(int i = 1 ; i < n ; i++)
    {
        for(int j = 0 ; j < i ; j++)
        {
            if ( mat_adj[i][j] != INT_MAX )
                graphe.insert(graphe.end(), {i, j, mat_adj[i][j]});
        }
    }

    arbre = kruskal( graphe );
    cout << endl << "L'arbre couvrant de poids minimal est l'arbre constitue des liens suivants : " << endl << endl;
    cout << endl << "N.B : La notation a --- b signifie qu'il y a une arete entre a et b." << endl << endl;
    for(int i = 0 ; i < (int)arbre.size() ; i++) {
        cout << arbre[i].sommet1 << "\t---\t" << arbre[i].sommet2 << endl;
    }
    cout << endl << endl << "Cet arbre couvrant est de poids : " << dmin(arbre) << endl << endl;
    return 0;
}


vector<Arete> kruskal( vector<Arete> aretes ) {

    int n = aretes.size();
    vector<Arete> arbre = {};
    aretes = tri_fusion(aretes);
    arbre = {aretes[0]};

    for(int i = 1 ; i < n ; i++)
    {
        if ( !cyclic( arbre, aretes[i] ) )
            arbre.insert(arbre.end(), aretes[i]);
    }
    return arbre;
}


int dmin( vector<Arete> arbre ) {

    int n = arbre.size(), somme_poids = 0;

    for(int i = 0 ; i < n ; i++)
        somme_poids += arbre[i].poids;
    return somme_poids;
}

bool cyclic( vector<Arete> arbre, Arete arete ) { // Si le graphe obtenu par ajout de l'arête arete est cyclique.

    int n = arbre.size();
    bool cycle = true, already_used[2] = {false, false};

    for(int i = 0 ; i < n ; i++)
    {
        if (arbre[i].sommet1 == arete.sommet1 || arbre[i].sommet1 == arete.sommet2)
            already_used[0] = true;
        if (arbre[i].sommet1 == arete.sommet1 || arbre[i].sommet2 == arete.sommet2)
            already_used[1] = true;
    }
    cycle = already_used[0] && already_used[1];
    return cycle;
}

vector<Arete> fusion(vector<Arete> aretes1, vector<Arete> aretes2) {

    unsigned int i = 0, j = 0;

    while(i < aretes2.size())
    {
        while(j < aretes1.size() && aretes2[i].poids > aretes1[j].poids)
        {
            j++;
        }
        aretes1.insert(aretes1.begin()+j, aretes2[i]);
        i++;
        j++;
    }
    return aretes1;
}

vector<Arete> tri_fusion(vector<Arete> T)
{
    int n = T.size();
    if(n == 1)
        return T;
    else {
        // On divise en 2 vectors de tailles n/2. Vectors d'arêtes (T1 et T2).
        vector<Arete> T1 = {T.begin(), T.begin()+n/2};
        vector<Arete> T2 = {T.begin()+n/2, T.end()};
        vector<Arete> T1_trie = tri_fusion(T1);
        vector<Arete> T2_trie = tri_fusion(T2);
        return fusion(T1_trie, T2_trie);
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
