#include <iostream>
#include "fonctions.h"

using namespace std;

int main()
{
    int n = 4;
    Carre C(1);
    int a = 1, b = 7;
    cout << "Entrer la taille de l'image matrice a generer >> ";
    cin >> n;
    C.genererAleatoire(n);
    C.createImg();
    Pixel pixel = C.pgcb();
    cout << "Taille du plus grand carre blanc : " << pixel.getPGCB() << endl;
    cout << "Le pixel associe est : (" << pixel.getX()+1 << ", " << pixel.getY()+1 << ")" << endl;
    return 0;
}

int **creerMatrice(int n, int m) {
    int **M = (int **)malloc(n*sizeof(M));
    for(int i = 0; i < n ; i++)
    {
        M[i] = (int *)malloc(m*sizeof(int *));
    }
    return M;
}

Pixel ***creerMatricePixel(int n, int m) {
    Pixel ***M = (Pixel ***)malloc(n * sizeof(M));
    for(int i = 0; i < n ; i++)
    {
        M[i] = (Pixel **)malloc(m * sizeof(Pixel **));
    }
    return M;
}
