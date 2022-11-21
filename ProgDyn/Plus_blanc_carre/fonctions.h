#ifndef FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED

class Pixel {

    private:
        int x;
        int y;
        int valPixel;
        int pgcb;

    public:
        Pixel(int valPixel);
        Pixel(int x, int y, int valPixel, int pgcb);
        void setX(int x);
        int getX();
        void setY(int y);
        int getY();
        void setValPixel(int valPixel);
        int getValPixel();
        void setPGCB(int pgcb);
        int getPGCB();
        int couleur();
};

class Carre {

    private:
        int taille;
        Pixel*** M;

    public:
        Carre(int taille);
        Carre(char *nom_fichier);
        void setTaille(int taille);
        int getTaille();
        void setPixel(int x, int y, Pixel *pixel);
        Pixel *getPixel(int x, int y);
        Pixel pgcb();
        void remplir(char *nom_fichier);
        void createImg();
        void genererAleatoire(int n);
        void afficherCarre();
        void afficherPGCB();
};

int **creerMatrice(int n, int m);
Pixel ***creerMatricePixel(int n, int m);

#endif // FONCTIONS_H_INCLUDED
