#include <iostream>
#include <vector>
#include "location.h"

using namespace std;

int main()
//Bonjour Blaise
{
    vector<Reservation> reservations = {}, res = {}, reservations_triees = {};
    reservations.insert(reservations.begin(), {4, 5});
    reservations.insert(reservations.begin()+1, {1, 1});
    reservations.insert(reservations.begin()+2, {9, 19});
    reservations.insert(reservations.begin()+3, {2, 7});
    reservations.insert(reservations.begin()+4, {0, 17});
    reservations.insert(reservations.begin()+5, {5, 6});
    cout << endl << "Ensemble des demandes de location : " << endl << endl << "\t";
    for ( int i = 0 ; i < (int)reservations.size() ; i++ )

        cout << "Client" << i+1 << " [ " << reservations[i].debut << " - " << reservations[i].fin << " ] ";
    cout << endl << endl << "Tri dans l'ordre croissant de date de fin : " << endl << endl << "\t";
    reservations_triees = tri_fusion(reservations);
    for ( int i = 0 ; i < (int)reservations_triees.size() ; i++ )
        cout << " [ " << reservations_triees[i].debut << " - " << reservations_triees[i].fin << " ] ";
    cout << endl << endl << "La distribution de plages qui satisfait le plus de clients est : " << endl << endl << "\t";
    res = location_vehicules( reservations );
    for ( int i = 0 ; i < (int)res.size() ; i++ )
        cout << "[ " << res[i].debut << " - " << res[i].fin << " ] ";
    cout << "---------------------->> ( " << res.size() << " ) clients" << endl;
    return 0;
}


vector<Reservation> location_vehicules( vector<Reservation> reservations ) {

    int n = reservations.size(), j = 0;
    reservations = tri_fusion(reservations);
    vector<Reservation> res = {reservations[0]};

    for(int i = 1 ; i < n ; i++)
    {
        if (reservations[i].debut >= reservations[j].fin) { // S'ils sont compatibles.
            res.insert(res.end(), reservations[i]);
            j = i;
        }
    }
    return res;
}


vector<Reservation> fusion( vector<Reservation> res1, vector<Reservation> res2) {

    unsigned int i = 0, j = 0;

    while(i < res2.size())
    {
        while(j < res1.size() && res2[i].fin > res1[j].fin)
        {
            j++;
        }
        res1.insert(res1.begin()+j, res2[i]);
        i++;
        j++;
    }
    return res1;
}

vector<Reservation> tri_fusion(vector<Reservation> R)
{
    int n = R.size();
    if(n == 1)
        return R;
    else {
        // On divise en 2 vectors de tailles n/2. Vectors de réservation (R1 et R2) et vectors des clients (C1 et C2).
        vector<Reservation> R1 = {R.begin(), R.begin()+n/2};
        vector<Reservation> R2 = {R.begin()+n/2, R.end()};
        vector<Reservation> res1 = tri_fusion(R1);
        vector<Reservation> res2 = tri_fusion(R2);
        return fusion(res1, res2);
    }
}
