#ifndef LOCATION_H_INCLUDED
#define LOCATION_H_INCLUDED

using namespace std;

typedef struct Reservation {
    double debut;
    double fin;
} Reservation;

vector<Reservation> fusion(vector<Reservation> res1, vector<Reservation> res2);
vector<Reservation> tri_fusion(vector<Reservation> reservations);
vector<Reservation> location_vehicules( vector<Reservation> reservations );

#endif // LOCATION_H_INCLUDED
