#include <iostream>
#include "edition.h"

using namespace std;

int main()
{
    int i, n, m;
    string X;
    string Y;
    string edit;
    int **C;

    cout << "Entrer le mot X >> ";
    cin >> X;

    cout << endl;

    cout << "Entrer le mot Y >> ";
    cin >> Y;

    C = distance(X, Y);
    edit = edition(X, Y, C, "", "", X.length(), Y.length());

    cout << "Le score de la meilleure edition est : " << distance2(X, Y) << endl;
    cout << "\n\nMeilleure edition : \n\n" << edit;

    return 0;
}

string edition(string X, string Y, int **C, string A, string B, int i, int j)
{

    if(i == 0 && j == 0){
        return B + "\n" + A;
    }
    else {
        if(C[i][j] == 1)
            return edition(X, Y, C,  X[i-1] + A, "-" + B, i-1, j);
        if(C[i][j] == 2)
            return edition(X, Y, C, "-" + A, Y[j-1] + B, i, j - 1);
        if(C[i][j] == 3)
            return edition(X, Y, C, X[i-1] + A, Y[j-1] + B, i-1, j-1);
    }
    return 0;
}

int **distance(string X, string Y){

    int n = X.length(), m = Y.length();
    int **S = creerMatrice(n+1, m+1);
    int **C = creerMatrice(n+1, m+1);
    S[0][0] = 0;
    for(int i = 1; i < n+1; i++){ // distance qui descent
        S[i][0] = S[i-1][0] + 1;
        C[i][0] = 1;
    }
    for(int j = 1; j < m+1; j++){ // distance qui part de la gauche vers la droite
        S[0][j] = S[0][j-1] + 1;
        C[0][j] = 2;
    }
    for(int i = 1; i < n + 1; i++){
        for(int j = 1; j < m + 1; j++){
            S[i][j] = S[i-1][j] + 1; // distance qui descent
            C[i][j] = 1;

            if(S[i][j] > S[i][j-1]){  // distance qui part de la gauche vers la droite
                S[i][j] = S[i][j-1] + 1;
                C[i][j] = 2;
            }

            if(X[i-1] == Y[j-1]){
                if(S[i][j] > S[i-1][j-1] + 0){
                    S[i][j] = S[i-1][j-1] + 0;
                    C[i][j] = 3;
                }
            }
            else {
                if(S[i][j] > S[i-1][j-1] + 2){
                    S[i][j] = S[i-1][j-1] + 2;
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

int distance2(string X, string Y){

    int n = X.length(), m = Y.length();
    int **S = creerMatrice(n+1, m+1);
    int **delta = creerMatrice(n+1, m+1);
    S[0][0] = 0;
    for(int i = 1; i < n+1; i++){
        S[i][0] = S[i-1][0] + 1;
    }
    for(int j = 1; j < m+1; j++){
        S[0][j] = S[0][j-1] + 1;
    }
    for(int i = 1; i < n + 1; i++){
        for(int j = 1; j < m + 1; j++){

            if(X[i-1] == Y[j-1]){
                delta[i][j] = 0;
            }
            else {
                delta[i][j] = 2;
            }
            S[i][j] = min(S[i-1][j-1] + 2*delta[i][j], min(S[i-1][j] + 1, S[i][j-1] + 1));
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
