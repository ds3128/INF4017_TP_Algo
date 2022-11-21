#include <iostream>
#include <cstdlib>
#include <ctime>
#include <math.h>
#include "fonction.h"

using std::cout;
using std::endl;

int main()
{
    srand(time(NULL));
    int graphe[100][100];//graphe des distances entre les points
    point p[100];//ensemble des points
    float T=0.5;//température
    float COOL=0.9;//facteur de refroidissement


    //generation aleatoire de point
    for(int i=0; i<100;i++){
        p[i].x=random(100);
        p[i].y=random(100);
        cout << "P["<<i<<"]" << "=(" << p[i].x << ";" << p[i].y << ")" << endl;
    }

    //graphe des distances entre les points
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
          graphe[i][j]=distance_euclidienne(p[i],p[j]);
        }
    }
    int S[100];int cost=0;
    //initialisation solution initiale
    for(int i=0;i<100;i++){
        S[i]=i;
    }
    //calcule du cout et affichage du chemin
    cost=chemin_cout(graphe,S);

    //recruit simulé test et echange
    while(T>0.01)
        {
        int ncost=0;
        int aux;
        int a;
        int b;
        //prenons deux points aléatoire dans la boucle
        do{
            a=random(100);
            b=random(100);
        }while(a==0||b==0);

        //echanger les positions entre les points a et b dans la boucle
        aux=S[a];
        S[a]=S[b];
        S[b]=aux;
        cout << " a="<<S[a] << " b="<< S[b] << endl;

        //affichage de la nouvelle route
        for(int i=0;i<100;i++){
        ncost=ncost+graphe[S[i]][S[i+1]];
        cout << S[i] << "<--";
        if(i==99){
        ncost=ncost+graphe[S[0]][S[i]];
        cout << S[0] <<endl;
        //vérifions si la nouvelle route est meilleur
                //si nouveau < ancien on prend comme nouveau meilleur chemin
                if(ncost<cost){
                cout << "nouveau cout=" <<ncost << " inferieur a ancient cout=" << cost << endl;
                cost=ncost;
                //sinon on teste la qualité de la nouvelle valeur
                }else if(ncost>cost){
                    cout << "nouveau cout=" <<ncost << " superieur a ancient cout=" << cost << endl;
                    //on calcule la valeur exponentielle et on compare avec la solution
                    float rd=nombre_random();//probabilité d'acceptation d'erreur
                    cout << "T=" << T << " rd=" << rd << " exp(T,nouveau,ancien)="<< exp_f(T,ncost,cost) <<  endl;
                    if(rd<exp_f(T,ncost,cost)){

                         cost=ncost;
                    }else{
                    //si rien de donne on annule l'échange
                        aux=S[a];
                        S[a]=S[b];
                        S[b]=aux;
                    }}
                }

               }
             T=T*COOL;
            //clear console
            //system("cls");
            }
    cout << endl;
    cout << "Meilleur cout final " << cost <<endl;
    return EXIT_SUCCESS;
}
