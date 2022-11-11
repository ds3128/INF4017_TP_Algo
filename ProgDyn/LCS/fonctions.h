#ifndef FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED
#include <string.h>

int **creerMatrice(int n, int m);
int **lcs(char x[], char y[], int n, int m);
std::string plus_longue(char x[], char y[], int **S, int i, int j);
#endif // FONCTIONS_H_INCLUDED
