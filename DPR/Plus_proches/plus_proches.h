#ifndef PLUS_PROCHES_H_INCLUDED
#define PLUS_PROCHES_H_INCLUDED

using namespace std;

typedef struct Point {
    double x;
    double y;
} Point;

vector<Point> plus_proche(vector<Point> P);
vector<Point> tri_fusion(vector<Point> T);
vector<Point> fusion(vector<Point> P, vector<Point> Q);
double distance(Point P1, Point P2);

#endif // PLUS_PROCHES_H_INCLUDED
