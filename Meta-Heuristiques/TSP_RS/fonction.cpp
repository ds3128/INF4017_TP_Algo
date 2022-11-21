#include <iostream>
#include <cstdlib>
#include <ctime>
#include <math.h>
#include "fonction.h"

using std::cout;
using std::endl;

//nombre aléatoire entre 0 et 1
float nombre_random(){
     //srand(time(NULL));
     return (float)rand()/(float)RAND_MAX;
}

//nombre entier aléatoire entre 0 et limit
int random(int limit){
     //srand(time(NULL));
     return rand()%limit;
}

//type point


//calcule du carré
int square(int x){
return x*x;
}

//distance entre deux points
int distance_euclidienne(point p1,point p2){
return sqrt((square(p1.x - p2.x))+(square(p1.y - p2.y)));
}

//calcule du cout du chemin
int chemin_cout(int g[100][100],int S[100]){
        int cost=0;
        for(int i=0;i<100;i++){
        cost=cost+g[S[i]][S[i+1]];
       // cout << S[i] << "<--";
        if(i==99){cost=cost+g[S[0]][S[i]];cout << "cout i=" <<cost << endl;}
    }
    return cost;
}

double exp_f(double T,double a,double b){
    double ex;
    ex=exp((b-a)/T);
return ex;
}
