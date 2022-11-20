#include <iostream>
#include "fonction.h"

using namespace std;

int main()
{
    int i, n, m;
    char X[100];
    char Y[100];


    cout << "Entrez la taille de la suite X : ";
    cin >> n;
    cout << endl;

    cout << "Entrez la taille de la suite Y : ";
    cin >> m;
    cout << endl;

    //remplissage des elements de la suite
    for(i = 0; i < n; i++){
        cout << "Entrer l'element " << i+1 << " de la sequence X : ";
        cin >> X[i];
    }

    cout << endl;

    for(i = 0; i < m; i++){
        cout << "Entrer l'element " << i+1 << " de la sequence Y : ";
        cin >> Y[i];
    }

    int **C = sequences(X,Y,n,m);
    std::string align = alignement(X, Y, C, "", "", n, m);

    cout << "Le score du meilleur alignement : " << sequences2(X,Y,n,m) << endl;
    cout << "\n\nMeilleur alignement : \n\n" << align;

    return 0;
}

std::string alignement(char X[], char Y[], int **C, std::string A, std::string B, int i, int j){

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

int **sequences(char X[], char Y[], int n, int m){

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
            C[i][j]=1;

            if(S[i][j] < S[i][j-1]){  // gap qui part de la gauche vers la droite
                S[i][j] = S[i][j-1] + score_gap;
                C[i][j]=2;
            }

            if(S[i][j] < S[i-1][j-1]){

                if(X[i-1] == Y[j-1]){
                    S[i][j] = S[i-1][j-1] + score_match;
                    C[i][j]=3;
                }
                else {
                    S[i][j] = S[i-1][j-1] + score_missmatch;
                    C[i][j]=3;
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

int sequences2(char X[], char Y[], int n, int m){

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

            if(S[i][j] < S[i][j-1]){  // gap qui part de la gauche vers la droite
                S[i][j] = S[i][j-1] + score_gap;
            }

            if(S[i][j] < S[i-1][j-1]){

                if(X[i-1] == Y[j-1]){
                    S[i][j] = S[i-1][j-1] + score_match;
                }
                else {
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

