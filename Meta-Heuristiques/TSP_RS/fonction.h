#ifndef FONCTION_H_INCLUDED
#define FONCTION_H_INCLUDED

float nombre_random();
int random(int limit);
struct point{
int x;
int y;
};
int square(int x);
int distance_euclidienne(point p1,point p2);
int chemin_cout(int g[100][100],int S[100]);
double exp_f(double T,double a,double b);


#endif // FONCTION_H_INCLUDED
