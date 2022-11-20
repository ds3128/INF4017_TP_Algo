#ifndef EDITION_H_INCLUDED
#define EDITION_H_INCLUDED

int **creerMatrice(int n, int m);
int **distance(char X[], char Y[], int n, int m);
std::string edition(char X[], char Y[], int **C, std::string A, std::string B, int i, int j);


#endif // EDITION_H_INCLUDED
