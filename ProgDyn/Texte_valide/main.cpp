#include <iostream>
#include "fonctions.h"

using namespace std;

int main(){
    cout << endl;
    string chaine = "iletaitunefoismangeprincesseprincesseetaitilmange";
    int *C = posEspaces(chaine);

    cout << chaine << " est une chaine " << (isValid(chaine) == true ? "valide" : "non valide") << endl;
    cout << endl << "La chaine espacee est : " << chaineEspacee(chaine, C, chaine.length());

    return 0;
}

string chaineEspacee(string chaine, int C[], int i){
    if(!isValid(chaine))
        return chaine;
    else {
        if(i == 0)
            return "";
        else {
            cout << endl << C[i] << " ";
            return chaineEspacee(chaine, C, C[i]) + " " + chaine.substr(C[i], i-C[i]);
        }
    }
}

int *posEspaces(string chaine){

    int n = chaine.length();
    bool *S = new bool[n+1];
    int *C = new int[n+1];

    S[0] = true;
    //cout << endl << S[0] << " ";
    for(int i = 1; i < n+1 ; i++){
        S[i] = false;
        for(int j = i-1; j >= 0; j--){
            S[i] = S[i] | (S[j] & dict(chaine.substr(j, i-j))); // chaine.substr(j, i-j) signifie de j+1 a i.
            if(S[i] == (S[j] & dict(chaine.substr(j, i-j))) && S[i] == true) {
               C[i] = j;
               break;
            }
            else
                C[i] = -1;
        }
    }
    return C;
}

bool isValid(string chaine){

    int n = chaine.length();
    bool *S = new bool[n+1];
    int *C = new int[n+1];

    S[0] = true;
    //cout << endl << S[0] << " ";
    for(int i = 1; i < n+1 ; i++){
        S[i] = false;
        for(int j = i-1; j >= 0; j--){
            S[i] = S[i] | (S[j] & dict(chaine.substr(j, i-j))); // chaine.substr(j, i-j) signifie de j+1 a i.
            if(S[i] == (S[j] & dict(chaine.substr(j, i-j))))
               C[i] = j;
            else
                C[i] = -1;
        }
    }
    return S[n];
}

bool dict(string chaine) {
    int n = 7;
    string dico[] = {"il", "etait", "une", "fois", "princesse", "je", "mange"};
    for(int i = 0 ; i < n ; i++) {
        if (chaine == dico[i])
            return true;
    }
    return false;
}
