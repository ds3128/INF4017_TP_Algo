#include <iostream>
#include "fonctions.h"

using namespace std;

int main()
{
    int i, n, m;
    char x[100];
    char y[100];


    cout << "Entrez la taille de la suite X : ";
    cin >> n;
    cout << endl;

    cout << "Entrez la taille de la suite Y : ";
    cin >> m;
    cout << endl;

    //remplissage des elements de la suite
    for(i = 0; i < n; i++){
        cout << "Entrer l'element " << i+1 << " de la suite X : ";
        cin >> x[i];
    }

    cout << endl;

    for(i = 0; i < m; i++){
        cout << "Entrer l'element " << i+1 << " de la suite Y : ";
        cin >> y[i];
    }

    int **K =lcs(x, y, n, m);

    cout << endl;

    cout << "x = ";
    for(int i = 0 ; i < n ; i++)
        cout << (char) toupper(x[i]) << " ";

    cout << "\ny = ";
    for(int i = 0 ; i < m ; i++)
        cout << (char) toupper(y[i]) << " ";

    string Sous_suite = plus_longue(x, y, K, n, m);
    cout << "\nLongueur de la plus longue sous suite commune : " <<Sous_suite.length();
    cout << "\nLa plus longue sous suite commune : " << Sous_suite;


    return 0;
}

std::string plus_longue(char x[], char y[], int **S, int i, int j) {
    if(i == 0 || j == 0) {
        return "";
    }
   else {
        if(S[i][j] == 1)
            return plus_longue(x, y, S, i, j-1);
        if(S[i][j] == 2)
            return plus_longue(x, y, S, i-1, j);
        if(S[i][j] == 3)
            return plus_longue(x, y, S, i-1, j-1)+x[i-1];
    }
return 0;
}


int **lcs(char x[], char y[], int n, int m) {
     int **C = creerMatrice(n+1, m+1);
     int **S = creerMatrice(n+1, m+1);

     for(int j = 0 ; j < m+1 ; j++) {
        C[0][j] = 0;
        S[0][j] = -1;
     }

     for(int i = 0 ; i < n+1 ; i++) {
        C[i][0] = 0;
        S[i][0] = -1;
     }

     for(int i = 1 ; i < n+1 ; i++) {

         for(int j = 1 ; j < m+1 ; j++) {
            if(x[i-1] == y[j-1]) {
                C[i][j] = C[i-1][j-1]+1;
                S[i][j] = 3;
            }
            else if(C[i-1][j] >= C[i][j-1]) {
                C[i][j] = C[i-1][j];
                S[i][j] = 2;
            }
            else {
                C[i][j] = C[i][j-1];
                S[i][j] = 1;
            }
         }
     }

    cout << endl << endl;
    cout << " \t" << 0 << " \t";
    for(int i = 0 ; i < m ; i++) {
        cout << y[i] << " \t";
    }
    cout << endl;
    cout << 0 << " \t";

    for(int i = 0 ; i < n+1 ; i++) {
        if(i != 0)
            cout << x[i-1] << " \t";
        for(int j = 0 ; j < m+1 ; j++) {
            cout << C[i][j] << " \t";
        }
        cout << endl;
    }
    cout << endl << endl;



     return S;

}

int **creerMatrice(int n, int m) {
    int **M = (int **)malloc(n*sizeof(M));
    for(int i = 0; i<n ; i++)
    {
        M[i] = (int *)malloc(m*sizeof(int *));
    }
    return M;
}
