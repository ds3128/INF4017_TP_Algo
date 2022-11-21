#ifndef FONCTION_H_INCLUDED
#define FONCTION_H_INCLUDED

using namespace std;

int **creerMatrice(int n, int m);
int **sequences(string X, string Y);
int *score_alignement(string X, string Y);
string alignement(string X, string Y, int **C, string A, string B, int i, int j);

#endif // FONCTION_H_INCLUDED
