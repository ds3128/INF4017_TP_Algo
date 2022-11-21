#ifndef EDITION_H_INCLUDED
#define EDITION_H_INCLUDED

using namespace std;

int **creerMatrice(int n, int m);
int **distance(string X, string Y);
int distance2(string X, string Y);
string edition(string X, string Y, int **C, string A, string B, int i, int j);


#endif // EDITION_H_INCLUDED
