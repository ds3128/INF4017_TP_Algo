#include <iostream>
#include "fonction.h"

using namespace std;

int main()
{
    string X, Y, align;
    int **C;

    cout << endl;

    cout << endl;

    cout << "\t\t########### Alignement de Sequences ########## " << endl << endl;
    cout << "Entrer la sequence X >> ";
    cin >> X;

    cout << endl;

    cout << "Entrer la sequence Y >> ";
    cin >> Y;

    C = sequences(X,Y)
    align = alignement(X, Y, C, "", "", X.length(), Y.length());

    cout << "Le score du meilleur alignement : " << score_alignement(X,Y) << endl;
    cout << "\n\nMeilleur alignement : \n\n" << align;

    return 0;
}

string alignement(string X, string Y, int **C, string A, string B, int i, int j){

    if(i == 0 && j == 0){
        return B + "\n" + A;
    }
    else {
        if(C[i][j] == 1)
            return alignement(X, Y, C,  X[i-1] + A, "-" + B, i-1, j);
        if(C[i][j] == 2)
            return alignement(X, Y, C, "-" + A, Y[j-1] + B, i, j - 1);
        if(C[i][j] == 3)
            return alignement(X, Y, C, X[i-1] + A, Y[j-1] + B, i-1, j-1);
    }
    return 0;
}

int **sequences(string X, string Y){

    int n = X.length(), m = Y.length();
    int **S = creerMatrice(n+1, m+1);
    int **C = creerMatrice(n+1, m+1);
    int score_gap = -4 , score_match = 4 , score_missmatch = -4;
    S[0][0] = 0;
    for(int i = 1; i < n+1; i++){ // gap qui descent
        S[i][0] = S[i-1][0] + score_gap;
        C[i][0]=1;
    }
    for(int j = 1; j < m+1; j++){ // gap qui part de la gauche vers la droite
        S[0][j] = S[0][j-1] + score_gap;
        C[0][j]=2;
    }
    for(int i = 1; i < n + 1; i++){
        for(int j = 1; j < m + 1; j++){
            S[i][j] = S[i-1][j] + score_gap; // gap qui descent
            C[i][j] = 1;

            if(S[i][j] < S[i][j-1] + score_gap){  // gap qui part de la gauche vers la droite
                S[i][j] = S[i][j-1] + score_gap;
                C[i][j] = 2;
            }


            if(X[i-1] == Y[j-1]){
                if(S[i][j] < S[i-1][j-1] + score_match){
                    S[i][j] = S[i-1][j-1] + score_match;
                    C[i][j] = 3;
                }
            }
            else {
                if(S[i][j] < S[i-1][j-1] + score_missmatch){
                    S[i][j] = S[i-1][j-1] + score_missmatch;
                    C[i][j] = 3;
                }
            }
        }
    }

    cout << endl << endl;
    cout << " \t" << 0 << " \t";
    for(int i = 0 ; i < m ; i++) {
        cout << Y[i] << " \t";
    }
    cout << endl;
    cout << 0 << " \t";

    for(int i = 0 ; i < n+1 ; i++) {
        if(i != 0)
            cout << X[i-1] << " \t";
        for(int j = 0 ; j < m+1 ; j++) {
            cout << S[i][j] << " \t";
        }
        cout << endl;
    }
    cout << endl << endl;


    return C;

}

int score_alignement(string X, string Y){

    int n = X.length(), m = Y.length();
    int **S = creerMatrice(n+1, m+1);
    int score_gap = -4 , score_match =4 , score_missmatch = -4;
    S[0][0] = 0;
    for(int i = 1; i < n+1; i++){ // gap qui descent
        S[i][0] = S[i-1][0] + score_gap;
    }
    for(int j = 1; j < m+1; j++){ // gap qui part de la gauche vers la droite
        S[0][j] = S[0][j-1] + score_gap;
    }
    for(int i = 1; i < n + 1; i++){
        for(int j = 1; j < m + 1; j++){
            S[i][j] = S[i-1][j] + score_gap; // gap qui descent

            if(S[i][j] < S[i][j-1] + score_gap){  // gap qui part de la gauche vers la droite
                S[i][j] = S[i][j-1] + score_gap;
            }


            if(X[i-1] == Y[j-1]){
                if(S[i][j] < S[i-1][j-1] + score_match){
                    S[i][j] = S[i-1][j-1] + score_match;
                }
            }
            else {
                if(S[i][j] < S[i-1][j-1] + score_missmatch){
                    S[i][j] = S[i-1][j-1] + score_missmatch;
                }
            }
        }
    }
    return S[n][m];
}

int **creerMatrice(int n, int m) {
    int **M = (int **)malloc(n*sizeof(M));
    for(int i = 0; i<n ; i++)
    {
        M[i] = (int *)malloc(m*sizeof(int *));
    }
    return M;
}

