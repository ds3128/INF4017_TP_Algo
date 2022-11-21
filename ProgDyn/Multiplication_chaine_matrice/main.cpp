#include <iostream>
#include "solut.h"
#include <vector>
#include "limits.h"

using namespace std;

int main()
{

    int n = 4;
    cout << "solution optimale retournee sous forme de chaine de caractere.. " << endl;
    cout << "Entrez le nombre de matrices a multiplier: ";
    cin >>n;
    int *p = new int[n+1];

    cout  << "contenu du tableau en parametre: ";

    for(int i = 0; i < n+1; i++)
    {
        cout <<"Donnez la dimension de n"<<i<< endl;
        cin >> p[i];

    }

    for(int i = 0; i < n; i++)
    {
        cout << " A" << i+1;

    }
    cout  << endl;

    unsigned int **s = chaine(p, n+1);
    cout  << "retour de la suite: ";
    cout << s[1][n] << endl;
    cout << endl;

    cout << endl << parenthesage(s, 1, n) << endl;

    return 0;
}

unsigned int **creerMatrice(int n) {
    unsigned int **m = (unsigned int **)malloc(n*sizeof(m));
    for(int i = 0; i<n ; i++)
    {
        m[i] = (unsigned int *)malloc(n*sizeof(m));
    }
    return m;
}

unsigned int **chaine( int p[], int n )
{
    unsigned int q, j;
    unsigned int **m = creerMatrice(n), **s = creerMatrice(n);
    for(int i = 0; i < n; i++)
        m[i][i] = 0;
    for(int l = 2; l <= n; l++)
    {
        for(int i = 0; i < n-l+1; i++)
        {
            j = i+l-1;
            m[i][j] = UINT_MAX;
            for(unsigned int k = i; k < j; k++)
            {
                q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if( q < m[i][j])
                {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }

    return s;
}

string parenthesage(unsigned int **s, int i, int j)
{
    int k;
    if( i == j )
        return  " A" + std::to_string(i);
    else
    {
        k = s[i][j];
        return " ( " + parenthesage(s, i, k) + parenthesage(s, k+1, j) + " ) ";
    }
}
