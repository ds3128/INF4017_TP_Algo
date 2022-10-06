#include <vector>
#include <iostream>
#include <math.h>
#include <float.h>
#include "plus_proches.h"

using namespace std;

int main()
{
    Point Pi;
    int n = 2;

    cout << "\n\t ``````````````````````````````````````````````````````````````````````````````````````````````````````\n\n\t\t LES 2 POINTS LES PLUS PROCHES \n\n";

    cout << "\t``````````````````````````````````````````````````````````````````````````````````````````````````````\n\n";

    cout << "\n\n\t\t N.B >> MINIMUM 2 POINTS.";
    cout << "\n\n\t Entrez le nombre de points du plan >> ";
    cin >> n;
    vector<Point> P;
    cout << "\n\t\t ############ \t Entrez les coordonnees de chaque point >>\n";
    for(int i = 0 ; i < n ; i++) {
        cout << "\n\t\t\t *************** \t Coordonnees du point P" << i+1 << " >> ";
        cout << "\n\t\t\t\t\t x >> ";
        cin >> Pi.x;
        cout << "\n\t\t\t\t\t y >> ";
        cin >> Pi.y;
        P.insert(P.begin()+i, Pi);
    }

    cout << "\n\n\t ### \t Ensemble de points du plan >>" << endl << "\n\n\t\t";
    for(unsigned int i = 0 ; i < P.size(); i++)
        cout << "(" << P[i].x << " , " << P[i].y << ")\t";

    vector<Point> Pd = plus_proche(P);
    cout << "\n\n\n\t\t *************************** Une solution optimale est >>\t" << "A(" << Pd[0].x << " , " << Pd[0].y << ")" << "\tet\t" << "B(" << Pd[1].x << " , " << Pd[1].y << ")";
    cout << "\n\n\t\t +-+-+-+-+-+-+-+-+-+-+-+-+-+-+ de distance optimale \t delta = \t" << distance(Pd[0], Pd[1]) << "\n\n\n";
    return 0;
}

vector<Point> plus_proche(vector<Point> P) {
    unsigned int n = P.size();
    double d = DBL_MAX;
    Point P1d, P2d;

    if(n <= 3) {
        for(unsigned int i = 0 ; i < 2 ; i++) {
            for(unsigned int j = i+1 ; j < 3 ; j++) {
                if(distance(P[i], P[j]) < d) {
                    d = distance(P[i], P[j]);
                    P1d = P[i];
                    P2d = P[j];
                }
            }
        }
    }
    else {
        vector<Point> X = tri_fusion(P);
        cout << "\n\n\t\t---------------------------------------------------------------------------\n\nTries >> \t";
        for(unsigned int i = 0 ; i < X.size() ; i++) {
            cout << "(" << X[i].x << " , " << X[i].y << ")\t";
        }
        cout << "\n\n\t\t---------------------------------\t XG \t------------------------------------\n\n";
        vector<Point> XG = {X.begin(), X.begin()+n/2};
        for(unsigned int i = 0 ; i < XG.size() ; i++) {
            cout << "(" << XG[i].x << " , " << XG[i].y << ")\t";
        }
        cout << "\n\n\t\t---------------------------------\t XD \t------------------------------------\n\n";
        vector<Point> XD = {X.begin()+n/2, X.end()};
        for(unsigned int i = 0 ; i < XD.size() ; i++) {
            cout << "(" << XD[i].x << " , " << XD[i].y << ")\t";
        }
        cout << "\n\n\t\t----------------------------------------------------------------------------\n\n";
        vector<Point> PminG = plus_proche(XG);
        vector<Point> PminD = plus_proche(XD);
        Point P_prime1d;
        Point P_prime2d;
        P1d = PminG[0];
        P2d = PminG[1];
        double dG = distance(P1d, P2d);
        double dD = distance(PminD[0], PminD[1]);
        if(dD < dG) {
            P1d = PminD[0];
            P2d = PminD[1];
        }
        d = min(dG, dD);
        cout << "\n\n\t\t------------------------------------- delta G, delta D, delta, et A et B --------------------------------------\n\n";
        cout << "\n\n\t\t delta G = " << dG << " delta D = " << dD << " delta = " << d << "\n\n";
        cout << "\n\tLes 2 points les plus proches \t\t (" << P1d.x << " , " << P1d.y << ") et " << "(" << P2d.x << " , " << P2d.y << ")\t\n\n";
        Point droite = XG[n/2-1];

        for(unsigned int i = 0; i < XG.size()-1 ; i++) {
            droite.y = XG[i].y;
            if(distance(XG[i], droite) >= d)
                XG.erase(XG.begin()+i);
        }

        for(unsigned int i = 0; i < XD.size() ; i++) {
            droite.y = XD[i].y;
            if(distance(XD[i], droite) >= d)
                XD.erase(XD.begin()+i);
        }

        double d_prime = DBL_MAX
        ;
        for(unsigned int i = 0; i < XG.size() ; i++) {
            for(unsigned int j = 0; j < XD.size() ; j++) {
                if(distance(XG[i], XD[j]) < d_prime) {
                    d_prime = distance(XG[i], XD[j]);
                    P_prime1d = XG[i];
                    P_prime2d = XD[j];
                }
            }
        }

        cout << "\n\n\t\t------------------------------------- delta' --------------------------------------\n\n";
        cout << "\n\n\t\t delta' = " << d_prime << "\n\n";
        cout << "\n\tLes 2 points les plus proches dans le rectangle \t\t (" << P_prime1d.x << " , " << P_prime1d.y << ") et " << "(" << P_prime2d.x << " , " << P_prime2d.y << ")\t\n\n";

        if(d_prime < d) {
            d = d_prime;
            P1d = P_prime1d;
            P2d = P_prime2d;
        }

        cout << "\n\n\t\t------------------------------------- distance minimale --------------------------------------\n\n";
        cout << "\n\n\t\t delta = " << d << "\n\n";
        cout << "\n\tLes 2 points les plus proches dans le rectangle \t\t (" << P1d.x << " , " << P1d.y << ") et " << "(" << P2d.x << " , " << P2d.y << ")\t\n\n";
    }
    return {P1d, P2d};
}

double distance(Point P1, Point P2) {
    return sqrt(pow(P1.x-P2.x, 2)+pow(P1.y-P2.y, 2));
}

vector<Point> fusion(vector<Point> P, vector<Point> Q) {
    vector<Point> T(P);
    unsigned int i = 0, j = 0;
    while(i < Q.size()) {
        while(j < T.size() && Q[i].x >= T[j].x) {
            j++;
        }
        T.insert(T.begin()+j, Q[i]);
        i++;
        j++;
    }
    return T;
}

vector<Point> tri_fusion(vector<Point> T) {
    int n = T.size();
    if(n == 1)
        return T;
    else
        return fusion(tri_fusion({T.begin(), T.begin()+n/2}), tri_fusion({T.begin()+n/2, T.end()}));
}
