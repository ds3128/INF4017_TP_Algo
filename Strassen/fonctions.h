#ifndef FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED

int **strassen(int **A, int **B, int n);
int **addition(int **A, int **B, int n);
int **soustraction(int **A, int **B, int n);
int **creerMatrice(int n);
int **sousMatrice(int **M, int n,  int numX, int numY);
void combinerMatrices(int **C, int n, int **M,  int numX, int numY);
void affichage(int **M, int n);

#endif // FONCTIONS_H_INCLUDED
