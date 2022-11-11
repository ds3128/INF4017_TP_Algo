#include <iostream>
#include "fonction2.h"
using namespace std;

int main()
{

    int n,i;
    int W;

    cout << "Entrez la taille du poids et des valeurs : ";
    cin >> n;

    cout << endl;

    int w[100];
    int v[100];
    //Remplissage des differents poids
    for(i = 0; i < n; i++){
        cout << "Entrez le poids " << i+1 << " : ";
        cin >> w[i];
    }

    cout << endl;
    //Remplissages des differentes valeurs
    for(i = 0; i < n; i++){
        cout << "Entrez la valeur " << i+1 << " : ";
        cin >> v[i];
    }

    cout << endl;
    cout << "Entrez la valeur du poids maximal : ";
    cin >> W;
    cout << endl;

    int **S = snapBag(w,v,W,4);
    cout << "\nLa valeur maximale obtenue  : " << objets_pri(w,v, S, n, W, n).length();
    cout << "\nLes objets obtenus sont : " << objets_pri(w,v, S, n, W, n);
return 0;
}

std::string objets_pri(int w[], int v[], int **S, int i, int j, int n) {
    if(i == 0 || j == 0) {
        return "";
    }
   else {
        if(S[i][j] == 1)
            return objets_pri(w, v, S, i-1, j, n);
        if(S[i][j] == 2)
            return objets_pri(w, v, S, i-1, j, n);
        if(S[i][j] == 3)
            return objets_pri(w, v, S, i-1, j-w[i-1], n) + to_string(i);
    }
    return 0;
}


int **snapBag(int w[], int v[], int W , int n) {
     int **P = creerMatrice(n+1, W+1);
     int **S = creerMatrice(n+1, W+1);

     for(int j = 0 ; j < W+1 ; j++) {
        P[0][j] = 0;
        S[0][j] = 0;
     }

     for(int i = 0 ; i < n+1 ; i++) {
        P[i][0] = 0;
        S[i][0] = 0;
     }

     for(int i = 1 ; i < n+1 ; i++) {

         for(int j = 1 ; j < W+1 ; j++) {
            if(j < w[i-1] && i>0) {
                P[i][j] = P[i-1][j];
                S[i][j] = 1;
            }
            else if(P[i-1][j] >= P[i-1][j-w[i-1]]+v[i-1]) {
                P[i][j] = P[i-1][j];
                S[i][j] = 2;
            }
            else {
                P[i][j] = P[i-1][j-w[i-1]]+v[i-1];
                S[i][j] = 3;
            }
         }
     }

    cout << endl << endl;
    cout << " \t";
    for(int i = 0 ; i < W+1 ; i++) {
        cout << i << " \t";
    }
    cout << endl;
    cout << 0 << " \t";

    for(int i = 0 ; i < n+1 ; i++) {
        if(i != 0)
            cout << i << " \t";
        for(int j = 0 ; j < W+1 ; j++) {
            cout << P[i][j] << " \t";
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
