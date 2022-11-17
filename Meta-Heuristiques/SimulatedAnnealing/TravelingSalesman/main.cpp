#include <iostream>
#include <time.h>
#include "fonctions.h"
#include <math.h>
#define TAILLE_MAX 100

using namespace std;

int n;


int main()
{
    float temperature, epsilon;
    cout << "Entrer le nombre de points a evaluer >> ";
    cin >> n;
    cout << "\nEntrer la Temperature autorisee >> ";
    cin >> temperature;
    cout << "\nEntrer le critere d'arret de variation de T >> ";
    cin >> epsilon;
    Point *x = new Point[n], *xp = new Point[n], *res;
    srand(time(NULL));
    for(int i = 0; i < n; i++){
        x[i].x = rand() % n;
        x[i].y = rand() % n;
    }
    cout << toString(x);
    xp = voisin(x);
    cout << endl << toString(xp);
    res = recuitS(temperature, epsilon, x);
    cout << endl << "Le chemin approximatif est : " << toString(res) << " de distance minimale : " << f(res);
    cout << endl;
    return 0;
}

float distance(Point P1, Point P2){
    return sqrt( pow((P1.x - P2.x), 2) + pow((P1.y - P2.y), 2) );
}

float genarateReal(){

    float generatedNumber = (float) rand()/RAND_MAX;

    return generatedNumber;
}

int genarateInteger(int n){

    return int(rand()) % n;
}

float g(float T, float alpha){
    return alpha * T;
}

float f(Point *x){

	float sommeDistance = 0;
    for(int i = 0; i < n-1; i++)
        sommeDistance += distance(x[i], x[i+1]);
    return sommeDistance + distance(x[0], x[n-1]);
}

float p( float T, Point *x, Point *xp ){
    return exp((f(x)-f(xp))/T);
}

Point *recuitS(float T, float epsilon, Point *x){
    Point *xp;
    float r;
    float alpha;
    cout << "\n\nEntrer le facteur de refroidissement >> ";
    cin >> alpha;
    cout << endl;
    cout << endl << "Temperature " << T << " " << toString(x) << " de distance minimale : " << f(x);
    while(T > epsilon){
        xp = voisin(x);
        if(f(xp) < f(x)){
            x = xp;
        }
        else {
            r = genarateReal();
            if(r < p(T, x, xp))
                x = xp;
        }
        T = g(T, alpha);
        cout << endl << "Temperature T =  " << T << " tournee : " << toString(xp) << " de distance minimale : " << f(xp);
    }
    return x;
}

Point *voisin(Point *x) {
    Point *xp = new Point[n];
    int indiceAleatoire1 = 0, indiceAleatoire2 = 0;
    Point tmp;
    indiceAleatoire1 = int(rand()) % n;  // Nombre aléatoire entre 0 et n
    for(int i = 0; i < n ; i++) {
        xp[i] = x[i];
    }
    do {
        indiceAleatoire2 = int(rand()) % n;
    } while (indiceAleatoire2 == indiceAleatoire1);
    tmp = xp[indiceAleatoire1];
    xp[indiceAleatoire1] = x[indiceAleatoire2];
    xp[indiceAleatoire2] = tmp;
    return xp;
}

string toString(Point *x) {
    string str = "-->> ";
    for(int i = 0; i < n ; i++) {
        str = str + "P" + to_string(i) + "( " + to_string(x[i].x) + ", " + to_string(x[i].y) + " ) ";
    }
    str = str + "P0 ( " + to_string(x[0].x) + ", " + to_string(x[0].y) + " )";
    return str;
}
