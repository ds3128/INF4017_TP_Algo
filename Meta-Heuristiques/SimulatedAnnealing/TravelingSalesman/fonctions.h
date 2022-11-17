#ifndef FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED

using namespace std;

typedef struct {
    int x;
    int y;
} Point;

Point *voisin(Point *x);
string toString(Point *x);
float genarateReal();
int genarateInteger(int n);
float g(float T, float alpha);
float f(Point *x);
float p( float T, Point *x, Point *xp );
Point *recuitS(float T, float epsilon, Point *x);
float distance(Point P1, Point P2);

#endif // FONCTIONS_H_INCLUDED
