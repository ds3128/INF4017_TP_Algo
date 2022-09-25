#include <iostream>
#include <math.h>
#include "karatsubaheader.h"

using namespace std;

long multiplie(long x, long y)
{
    int longueurX = longueur(x);
    int longueurY= longueur(y);

    int nbreMax = (int)(fmax(longueurX,longueurY));

    if(nbreMax < 10)
        return x*y;
    nbreMax=(nbreMax/2) + (nbreMax%2);

    long multi = pow(10, nbreMax);

    long b = x/multi;
    long a = x-(b*multi);
    long d = y/multi;
    long c = y -(d*nbreMax);
    long A0 = multiplie(a,c);
    long A1 = multiplie(a+b,c+d);
    long A2 = multiplie(b,d);

    return A0 + ((A1-A0-A2)*multi)+(A2*(long)(pow(10, 2*nbreMax)));
}


int longueur(long valeur)
{
    int compteur = 0;
    while(valeur != 0)
    {
        compteur++;
        valeur /=10;
    }
    return compteur;
}


int main()
{
    cout << "Hello world!" << endl;
    long a = 12345678966;
    long b = 12256636987;

    cout << multiplie(a,b) << endl;

    return 0;
}
