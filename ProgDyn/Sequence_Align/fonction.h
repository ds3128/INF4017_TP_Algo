#ifndef FONCTION_H_INCLUDED
#define FONCTION_H_INCLUDED

int **creerMatrice(int n, int m);
int **sequences(char X[], char Y[], int n, int m);
std::string alignement(char X[], char Y[], int **C, std::string A, std::string B, int i, int j);

#endif // FONCTION_H_INCLUDED
