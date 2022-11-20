#ifndef LOCATION_H_INCLUDED
#define LOCATION_H_INCLUDED

using namespace std;

typedef struct Arete {
    int sommet1;
    int sommet2;
    int poids;
} Arete;

vector<Arete> fusion(vector<Arete> aretes1, vector<Arete> aretes2);
vector<Arete> tri_fusion(vector<Arete> aretes);
vector<Arete> kruskal( vector<Arete> aretes );
int dmin( vector<Arete> arbre );
bool cyclic( vector<Arete> arbre, Arete arete );
int **creerMatrice(int n, int m);

#endif // LOCATION_H_INCLUDED
