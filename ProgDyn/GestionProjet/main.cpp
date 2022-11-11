#include <iostream>
#include <limits.h>
#include "fonction.h"

using namespace std;

int main()
{
    int nj = 0, np = 0;
    //int G[5][3] = { {0, 0, 0}, {1, 3, 2}, {3, 4, 2}, {5, 6, 3}, {5, 6, 4}, {6, 8, 7} };
    //int G[3][3] = { {0, 0, 0}, {1, 3, 2}, {3, 4, 2} };
    cout << "Entrer le nombre de jour disponible >> ";
    cin >> nj;
    cout << "Entrer le nombre de projet disponible >> ";
    cin >> np;
    int **G = creerMatrice(nj+1, np);
    cout << "Entrer les elements de la matrice : " << endl;
    for(int i = 0; i < nj + 1; i++){
        for(int j = 0; j < np; j++){
            cout << "Entrer l'element G( " << i << ", " << j + 1 << " ) >> ";
            cin >> G[i][j];
        }
    }
    cout << endl;
    cout << "Le gain optimal est : " << projet(G, nj, np) << endl;
    cout << endl;
    int *A = strategie(G, nj, np);
    cout << "La strategie correspondante consiste a repartir de la maniere suivante : " << endl;
    for(int p = 0; p < np; p++)
        cout << "Projet " << p + 1 << " -> " << A[p] << " jour(s)." << endl;
    return 0;
}



int projet(int **G, int nj, int np){

    int **SG = creerMatrice(nj+1, np);
    for(int x = 0; x < nj + 1; x++){
        SG[x][np - 1] = G[x][np - 1];
    }
    for(int y = 0; y < np; y++){
        SG[0][y] = 0;
    }

    for(int x = 1; x < nj + 1; x++){
        for(int y = np - 2; y >= 0; y--){
        SG[x][y] = 0;
            for(int xp = 0; xp <= x; xp++){
                if(SG[x][y] < SG[xp][y + 1] + G[x - xp][y]){
                    SG[x][y] = SG[xp][y + 1] + G[x - xp][y];
                }
            }
        }
    }
    return SG[nj][0];
}

int *strategie(int **G, int nj, int np){

    int **SG = creerMatrice(nj + 1, np);
    int **C = creerMatrice(nj + 1, np);
    int *A = new int[np];
    int x = 0, xp = 0;
    for(int x = 0; x < nj + 1; x++){
        SG[x][np - 1] = G[x][np - 1];
        C[x][np - 1] = 0;
    }
    for(int y = 0; y < np; y++){
        SG[0][y] = 0;
        C[0][y] = 0;
    }

    for(x = 1; x < nj + 1; x++){
        for(int y = np - 2; y >= 0; y--){
            SG[x][y] = 0;

            for(xp = 0; xp <= x; xp++){
                if(SG[x][y] < SG[xp][y + 1] + G[x - xp][y]){
                    SG[x][y] = SG[xp][y + 1] + G[x - xp][y];
                    C[x][y] = xp;
                }
            }
        }
    }

    x = nj;
    for(int p = 0; p < np; p++){
        xp = C[x][p];
        A[p] = x - xp;
        x = xp;
    }
    return A;
}

int **creerMatrice(int n, int m) {
    int **M = (int **)malloc(n*sizeof(M));
    for(int i = 0; i<n ; i++)
    {
        M[i] = (int *)malloc(m*sizeof(int *));
    }
    return M;
}
