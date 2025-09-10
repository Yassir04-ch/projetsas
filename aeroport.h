#ifndef AEROPORT_H
#define AEROPORT_H
#include <stdio.h>
#include <string.h>

#define max 100

struct date {
    int jour;
    int  mois;
    int annee;
};
struct avion {
    int idavion;
    char modele[50];
    int capacite;
    char statut[20];
    struct date dateentree;
    
};
struct Aeroport {
char nom[50];
struct avion flotte[max];
int nbavions;
};



#endif