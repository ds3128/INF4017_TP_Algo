#include <iostream>
#include "fonctions.h"

using namespace std;

int main()
{
    int n = 4;
    int *T = new int[n];
    int *ind = new int[2];

    cout << "Entrez la taille du tableau : ";
    cin >> n;
    cout << endl;
    cout << endl;

    cout << endl;

    for(int i = 0; i < n; i++){
        cout << "Entrer l'element " << i+1 << " du tableau : ";
        cin >> T[i];
    }

    ind = somme_max(T, n);
    cout << "Indice de debut = " << ind[0] << " indice de fin = " << ind[1] << endl;

    return 0;
}

int *somme_max(int T[], int n){

    int debut = 0, fin ;
    int *S = new int[n];
    string *C = new string[n];
    int *ind = new int[2];
    int maxi = T[0];

    S[0] = T[0];
    for(int i = 1; i < n; i++){
        if(S[i-1] + T[i] < T[i]) {
            S[i] = T[i];
            C[i] = "";
        }
        else {
            S[i] = S[i-1] + T[i];
            C[i] = "<-";
        }
        if(maxi < S[i]) {
            maxi = S[i];
            fin = i;
        }
    }

    debut = fin;
    while(C[debut] != "") debut--;

    ind[0] = debut;
    ind[1] = fin;
    cout << endl << endl;
    for(int i = 0 ; i < n ; i++) {
        cout << S[i] << " \t";
    }
    cout << endl;


    return ind;
}
