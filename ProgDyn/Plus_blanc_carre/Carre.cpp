#include <iostream>
#include <cstdlib>
#include <time.h>
#include "fonctions.h"
#define TAILLE_MAX 100

using namespace std;

Carre::Carre(int taille) {
    this->taille = taille;
    this->M = creerMatricePixel(taille+1, taille+1);
}

void Carre::setTaille(int taille) {
    this->taille = taille;
    this->M = creerMatricePixel(taille+1, taille+1);
}

int Carre::getTaille() {
    return this->taille;
}

void Carre::setPixel(int x, int y, Pixel *pixel) {
    M[x][y] = pixel;
}

Pixel *Carre::getPixel(int x, int y) {
    return M[x][y];
}

void Carre::remplir(char *nom_fichier) {
    FILE* fich = fopen(nom_fichier, "r");
    int taille, valPixel;
    Pixel *pixel(0);
    char str[100];
    fgets(str, TAILLE_MAX, fich);
    fscanf(fich, "%d", &taille);
    fgets(str, TAILLE_MAX, fich);
    fgets(str, TAILLE_MAX, fich);

    setTaille(taille);

    for(int i = 0; i < taille ; i++) {
        for(int j = 0; j < taille ; j++) {
            pixel = new Pixel(0);
            fscanf(fich, "%d", &valPixel);
            pixel->setX(i);
            pixel->setY(j);
            pixel->setValPixel(valPixel);
            setPixel(i, j, pixel);
        }
    }
    fclose(fich);
}

Pixel Carre::pgcb() {
    int n = getTaille(), max_pgcb = 0;
    Pixel *max_pixel(0);

    for(int i = 0; i < n ; i++) {
        for(int j = 0; j < n ; j++) {
            if(getPixel(i, j)->couleur() == 1)
                getPixel(i, j)->setPGCB(0);
            else if(i == 0 || j == 0)
                getPixel(i, j)->setPGCB(1);
            else
                getPixel(i, j)->setPGCB(1 + min(min(getPixel(i-1, j)->getPGCB(), getPixel(i, j-1)->getPGCB()), getPixel(i-1, j-1)->getPGCB()));
            if(max_pgcb < getPixel(i, j)->getPGCB()) {
                max_pgcb = getPixel(i, j)->getPGCB();
                max_pixel = getPixel(i, j);
            }
        }
    }
    afficherCarre();
    cout << "\n\n";
    afficherPGCB();
    cout << "\n";
    return *max_pixel;
}

void Carre::createImg() {
    FILE* fich = fopen("pgcb_image.pgm", "w+");
    fprintf(fich, "%s\n", "P2");
    fprintf(fich, "%d %d\n", taille, taille);
    fprintf(fich, "%d\n", 255);

    for(int i = 0; i < taille ; i++) {
        for(int j = 0; j < taille ; j++) {
            fprintf(fich, "%d\n", getPixel(i, j)->getValPixel());
        }
    }
    fprintf(fich, "%d\n", 255);
    fclose(fich);
}

void Carre::genererAleatoire(int n) {

    setTaille(n);
    Pixel* pixel(0);
    int a = 0, b = 255;
    srand(time(NULL));
    for(int i = 0; i < taille ; i++) {
        for(int j = 0; j < taille ; j++) {
            pixel = new Pixel(0);
            pixel->setX(i);
            pixel->setY(j);
            pixel->setValPixel(int(rand()) % 256); //a + (int)((float)rand() * (b - a + 1) / (RAND_MAX-1))
            if(pixel->getValPixel() <= 255 && pixel->getValPixel() >= 70){
                pixel->setValPixel(255);
            }
            else{
                pixel->setValPixel(0);
            }
            setPixel(i, j, pixel);
        }
    }
}

void Carre::afficherCarre() {

    for(int i = 0; i < taille ; i++) {
        for(int j = 0; j < taille ; j++) {
            cout << ((getPixel(i, j)->couleur() == 1) ? "N" : "B") << " ";
        }
        cout << "\n";
    }
}

void Carre::afficherPGCB() {

    for(int i = 0; i < taille ; i++) {
        for(int j = 0; j < taille ; j++) {
            cout << getPixel(i, j)->getPGCB() << " ";
        }
        cout << "\n";
    }
}
