#ifndef LIBRARY_H
#define LIBRARY_H
#include <stdio.h>
#include <string.h>
#define MAX 200
struct Avion {
    int idAvion;
    char modele[50];
    int capacite;
    char statut[20];
};

struct Aeroport {
    char nom[50];
    struct Avion flotte[MAX];
    int nbAvions;
}aeroport;
 void ajouterAvion();
 void afficherAvion(struct Avion a);
 void afficherFlotte();
 void trierparmodele();
 void trierparcapacite();
 int recherchemodele(char modele[]);
 int recherchecapacite(int capacite);
 void trierparid();
 int rechercheId(int id);
 void modifierAvion() ;
 void supprimerAvion() ;
 void calculCoeffOccupation();
 void menuAvions();
 void menuAeroport();
#endif