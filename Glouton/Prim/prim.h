#ifndef LOCATION_H_INCLUDED
#define LOCATION_H_INCLUDED

using namespace std;

int **creerMatrice(int n, int m);
vector<int> adj_noeud( int i, int **mat_adj, bool *visited, int n );
int dmin( int *pere, int **mat_adj, int n );
int *prim( int **mat_adj, int n );

#endif // LOCATION_H_INCLUDED
