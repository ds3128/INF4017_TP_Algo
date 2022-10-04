²²#include <iostream>
#include "karatsuba.h"

using namespace std;

int main()
{
    int taille = 0;
    cout << "\t\t___________________________________________________________________________________________________\n" <<endl;
    cout << "\t\t\t\t\tKARATSUBA MULTILICATION DE POLYNOMES" <<endl;
    cout << "\t\t___________________________________________________________________________________________________\n" <<endl;
    cout << "Entrez le degre des polynomes >> ";
    cin >> taille;
    int* P = (int*)malloc((taille+1)*sizeof(P));
    int* Q = (int*)malloc((taille+1)*sizeof(Q));
    int* R;

    for(int i = 0; i <= taille; i++){
        P[i] = 0;
    }

    for(int i = 0; i <= taille; i++){
        Q[i] = 0;
    }

    int i=0;
    cout << "\n\n  N.B : \t Utiliser des polynomes puissances de 2 uniquement.\n" << endl;
    cout << "\n\n  ************************** Remplir le premier polynome *************************" << endl;

    for(i = 0; i <= taille; i++)
    {
        cout << "\n\tCoefficient de degre " << (i) << " >> ";
        cin >> P[i];
        cout << endl;
    }

    cout << "\n\n  ************************** Remplir le second polynome *************************" << endl;
    for(i = 0; i <= taille; i++){
        cout << "\n\tCoefficient de degre " << (i) << " >> ";
        cin >> Q[i];
        cout << endl;
    }
    cout << " \n\t\t -------- Apercu -------- \n" << endl;
    cout << " P(x) = ";
    affichage(P, taille);
    cout << endl;
    cout << " Q(x) = ";
    affichage(Q, taille);
    cout << endl;

    R = Karatsuba(P, Q, taille);

    cout << "\n\n R(x) = PxQ = ( ";
    affichage(P, taille);
    cout << " ) ";
    cout << " ( ";
    affichage(Q, taille);
    cout << " ) ";
    cout << " = ";
    affichage(R, 2*taille);
}


int *Karatsuba( int P[], int Q[], int n )
{
    int *P1 = div(P, n, 1);
    int *P2 = div(P, n, 2);

    int *Q1 = div(Q, n, 1);
    int *Q2 = div(Q, n, 2);

    int *M = new int[2*n];

    //cout << "OK ici";

    if(n == 0)
    {
        M[0] = P[0]*Q[0];
        return M;
    }
    else if(n == 1)
    {
        M[0] = P[0]*Q[0];
        M[1] = P[1]*Q[0]+P[0]*Q[1];
        M[2] = P[1]*Q[1];
        return M;
    }
    else
    {
        // degre de P1 et Q1 = n/2+n%2-1 degre de P2 et Q2 = n/2

        int degreP1 = n/2+n%2-1;
        int degreP2 = n/2+n%2;

        cout << "\nP1 : ";
        affichage(P1, degreP1);
        cout << "\n";

        cout << "P2 : ";
        affichage(P2, degreP2);
        cout << "\n";

        cout << "Q1 : ";
        affichage(Q1, degreP1);
        cout << "\n";

        cout << "Q2 : ";
        affichage(Q2, degreP2);
        cout << "\n";

        int degreR1 = 2*degreP1;
        int degreR2 = 2*degreP2;
        int degreR3 = 2*degreP2;
        int *R1 = Karatsuba(P1, Q1, degreP1);
        int *R2 = Karatsuba(P2, Q2, degreP2);
        int *R3 = Karatsuba(addition(P1, P2, degreP1, degreP2), addition(Q1, Q2, degreP1, degreP2), degreP2);

        cout << "\nR1\n";
        affichage(R1, degreR1);
        cout << "\nR2\n";
        affichage(R2, degreR2);
        cout << "\nR3\n";
        affichage(R3, degreR3);
        cout << "\n";
        M = addition(R1, addition(produitMonome(soustraction(soustraction(R3, R1, degreR3, degreR1), R2, degreR3, degreR2), degreR3, n/2), produitMonome(R2, degreR2, n), degreR3+n/2, degreR2+n), degreR1, degreR2+n);

        return M;
    }
}

int *produitMonome(int A[], int n, int m)
{
    int *P = new int[n+m+1];

    for(int i = 0; i <= n+m; i++){
        P[i] = 0;
    }

    for(int i = n; i >= 0; i--)
    {
        P[i+m] = A[i];
    }
    return P;
}

int *addition( int P[], int Q[], int m, int p )
{
    int n = max(m,p);
    int *A = new int[n+1]; //polynome resultant

    for(int i = 0; i <= n; i++){
        A[i] = 0;
    }

    for(int i = 0; i <= m; i++)
    {
        A[i] = P[i];
    }

    for(int i = 0; i <= p; i++)
    {
        A[i] += Q[i];
    }

    return A;
}

int *soustraction( int P[], int Q[], int m, int p )
{
    int n = max(m, p);
    int *A = new int[n+1]; //polynome resultant

    for(int i = 0; i <= n; i++){
        A[i] = 0;
    }

    for(int i = 0; i <= p; i++)
    {
        A[i] -= Q[i];
    }
    A = addition(P, A, m, n);

    return A;
}

int *div( int a[], int n, int position )
{
    int *P;

    if (position == 1) {
        P = new int[n/2+n%2];
        for(int i = 0; i < n/2+n%2; i++)
        {
            P[i] = a[i];
        }
    }
    else {
        P = new int[n/2+1];
        for(int i = n/2+n%2; i < n+1; i++)
        {
            P[i-n/2-n%2] = a[i];
        }
        P = produitMonome(P, n/2+1, n%2);
    }

    return P;
}

void affichage(int poly[], int n){

    if( n == 0 ) {
        cout << " " << poly[n];
        return;
    }
    for(int i = n; i > 0; i--){
        if (poly[i] == 1)
            cout << "x^" << i << " + ";
        else if (poly[i] == 0)
            continue;
        else
            cout << poly[i] << "x^" << i << " + ";
    }
    cout << poly[0];
}
