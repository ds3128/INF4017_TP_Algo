#include <iostream>
#include "fonctions.h"

using namespace std;

int main()
{
    int n = 0;
    cout << "Entrez la taille de la matrice comme puissance de 2.\n";
    cin >> n;
    int **A = creerMatrice(n);

    int **B = creerMatrice(n);

    cout << "Remplissage de la matrice A.\n\n";
    for(int i=0; i<n ; i++) {
        for(int j=0; j<n ; j++) {
            cout << "Entrez la composante " << i << "," << j << ".>>\n";
            cin >> A[i][j];
        }
    }

    cout << "\nRemplissage de la matrice B.\n\n";
    for(int i=0; i<n ; i++) {
        for(int j=0; j<n ; j++) {
            cout << "Entrez la composante " << i << "," << j << ".>>\n";
            cin >> B[i][j];
        }
    }
    int **C = strassen(A, B, n);
    affichage(A, n);
    cout << "\n X \n";
    affichage(B, n);
    cout << "\n = \n";
    affichage(C, n);
    return 0;
}

int **strassen(int **A, int **B, int n) {
    int **C;
    if(n == 1) {
        C = creerMatrice(1);
        C[0][0] = A[0][0]*B[0][0];
        return C;
    }
    else {
        // Diviser
        int **A11 = sousMatrice(A, n, 1, 1);
        int **A12 = sousMatrice(A, n, 1, 2);
        int **A21 = sousMatrice(A, n, 2, 1);
        int **A22 = sousMatrice(A, n, 2, 2);
        int **B11 = sousMatrice(B, n, 1, 1);
        int **B12 = sousMatrice(B, n, 1, 2);
        int **B21 = sousMatrice(B, n, 2, 1);
        int **B22 = sousMatrice(B, n, 2, 2);

        int **X1 = strassen(soustraction(A12, A22, n/2), addition(B21, B22, n/2), n/2);
        int **X2 = strassen(addition(A11, A22, n/2), addition(B11, B22, n/2), n/2);
        int **X3 = strassen(soustraction(A11, A21, n/2), addition(B11, B12, n/2), n/2);
        int **X4 = strassen(addition(A11, A12, n/2), B22, n/2);
        int **X5 = strassen(A11, soustraction(B12, B22, n/2), n/2);
        int **X6 = strassen(A22, soustraction(B21, B11, n/2), n/2);
        int **X7 = strassen(addition(A21, A22, n/2), B11, n/2);

        // Régner
        int **C11 = addition(soustraction(addition(X1, X2, n/2), X4, n/2), X6, n/2);    //X1+X2-X4+X6
        int **C12 = addition(X4, X5, n/2);  //X4+X5
        int **C21 = addition(X6, X7, n/2);  //X6+X7
        int **C22 = soustraction(addition(soustraction(X2, X3, n/2), X5, n/2), X7, n/2);    //X1-X2+X3+X6

        cout << "\n";
        // Combiner
        C = creerMatrice(n);
        combinerMatrices(C, n, C11, 1, 1);  // On met C11 dans C.
        combinerMatrices(C, n, C12, 1, 2);  // On met C12 dans C.
        combinerMatrices(C, n, C21, 2, 1);  // On met C21 dans C.
        combinerMatrices(C, n, C22, 2, 2);  // On met C22 dans C.
        return C;
    }
}

int **addition(int **A, int **B, int n) {
    int **C = creerMatrice(n);
    for(int i=0; i<n ; i++) {
        for(int j=0; j<n ; j++) {
            C[i][j] = A[i][j]+B[i][j];
        }
    }
    return C;
}

int **soustraction(int **A, int **B, int n) {
    int **C = creerMatrice(n);
    for(int i=0; i<n ; i++) {
        for(int j=0; j<n ; j++) {
            C[i][j] = A[i][j]-B[i][j];
        }
    }
    return C;
}

int **creerMatrice(int n) {
    int **M = (int **)malloc(n*sizeof(M));
    for(int i = 0; i<n ; i++)
    {
        M[i] = (int *)malloc(n*sizeof(int *));
    }
    return M;
}

int **sousMatrice(int **M, int n,  int numX, int numY) {
    int **C = creerMatrice(n/2);
    int ligne = 0 , col = 0;
    if(numX == 1)
        ligne  = 0;
    if(numX == 2)
        ligne  = n/2;
    if(numY == 1)
        col  = 0;
    if(numY == 2)
        col  = n/2;

    for(int i = ligne; i<ligne+n/2 ; i++)
    {
        for(int j = col; j<col+n/2 ; j++)
        {
            C[i-ligne][j-col] = M[i][j];
        }
    }
    return C;
}

void combinerMatrices(int **C, int n, int **M,  int numX, int numY) {
    int ligne = 0 , col = 0;
    if(numX == 1)
        ligne  = 0;
    if(numX == 2)
        ligne  = n/2;
    if(numY == 1)
        col  = 0;
    if(numY == 2)
        col  = n/2;

    for(int i = ligne; i<ligne+n/2 ; i++)
    {
        for(int j = col; j<col+n/2 ; j++)
        {
            C[i][j] = M[i-ligne][j-col];
        }
    }
}

void affichage(int **M, int n) {
    for(int i=0; i<n ; i++) {
        for(int j=0; j<n ; j++) {
            cout << M[i][j] << " ";
        }
        cout << "\n";
    }
}
