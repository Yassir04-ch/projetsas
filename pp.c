#include <stdio.h>
#include <string.h>

#define MAX 100
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
};

struct Aeroport aeroport;
int idCounter = 1;

void ajouterAvion() {
    if(aeroport.nbAvions >= MAX) {
        printf("Flotte pleine!\n");
        return;
    }
    struct Avion a;
    a.idAvion = idCounter++;
    printf("Entrez le modele: ");
    scanf(" %[^\n]", a.modele);
    printf("Entrez la capacite: ");
    scanf("%d", &a.capacite);
    printf("Entrez le statut (Disponible/En maintenance/En vol): ");
    scanf(" %[^\n]", a.statut);


    aeroport.flotte[aeroport.nbAvions++] = a;
    printf("Avion ajoute avec ID %d\n", a.idAvion);
}

void afficherAvion(struct Avion a) {
    printf("ID:%d | Modele:%s | Cap:%d | Statut:%s ",
           a.idAvion, a.modele, a.capacite, a.statut);
}

void afficherFlotte() {
    if(aeroport.nbAvions == 0) {
        printf("Aucun avion.\n");
        return;
    }
    for(int i=0;i<aeroport.nbAvions;i++) {
        afficherAvion(aeroport.flotte[i]);
    }
}
void trierparmodele(){
    for (int i = 0; i < aeroport.nbAvions-1; i++)
    {
     for (int j = 0; j < aeroport.nbAvions-i-1; j++)
     {
        if (strcasecmp(aeroport.flotte[j].modele,aeroport.flotte[j+1].modele)>0)
        {
        struct Avion tmp = aeroport.flotte[j];
        aeroport.flotte[j]=aeroport.flotte[j+1];
        aeroport.flotte[j+1]=tmp;
        } 
     } 
    } 
}
    int rechercheBinaireId(int id) {
    int gauche=0, droite=aeroport.nbAvions-1;
    while(gauche<=droite) {
        int milieu = (gauche+droite)/2;
        if(aeroport.flotte[milieu].idAvion == id) return milieu;
        else if(aeroport.flotte[milieu].idAvion < id) gauche=milieu+1;
        else droite=milieu-1;
    }
    return -1;
}

void modifierAvion() {
    int id;
    printf("Entrez ID de l'avion a modifier: ");
    scanf("%d",&id);
    int pos = rechercheBinaireId(id);
    if(pos == -1) { printf("Avion non trouve!\n"); return; }

    printf("Modifier modele: ");
    scanf(" %[^\n]",aeroport.flotte[pos].modele);
    printf("Modifier capacite: ");
    scanf("%d",&aeroport.flotte[pos].capacite);
    printf("Modifier statut: ");
    scanf(" %[^\n]",aeroport.flotte[pos].statut);
    printf("Avion modifie.\n");
}

void supprimerAvion() {
    int id;
    printf("Entrez ID de l'avion a supprimer: ");
    scanf("%d",&id);
    int pos = rechercheBinaireId(id);
    if(pos==-1) { printf("Avion non trouve!\n"); return; }
    for(int i=pos;i<aeroport.nbAvions-1;i++) {
        aeroport.flotte[i] = aeroport.flotte[i+1];
    }
    aeroport.nbAvions--;
    printf("Avion supprime.\n");
}

void calculCoeffOccupation() {
    int dispo=0;
    for(int i=0;i<aeroport.nbAvions;i++)
        if(strcmp(aeroport.flotte[i].statut,"Disponible")==0) dispo++;
    if(aeroport.nbAvions==0){printf("Aucun avion.\n"); return;}
    float coeff = ((float)dispo/aeroport.nbAvions)*100;
    printf("Coeff. occupation: %.2f%%\n",coeff);
}

void statistiques() {
    if(aeroport.nbAvions==0){printf("Aucun avion.\n"); return;}
    int dispo=0, maintenance=0, enVol=0, minCap=aeroport.flotte[0].capacite, maxCap=aeroport.flotte[0].capacite, totalCap=0;
    for(int i=0;i<aeroport.nbAvions;i++){
        totalCap+=aeroport.flotte[i].capacite;
        if(strcasecmp(aeroport.flotte[i].statut,"Disponible")==0) dispo++;
        else if(strcasecmp(aeroport.flotte[i].statut,"En maintenance")==0) maintenance++;
        else if(strcasecmp(aeroport.flotte[i].statut,"En vol")==0) enVol++;
        if(aeroport.flotte[i].capacite>maxCap) maxCap=aeroport.flotte[i].capacite;
        if(aeroport.flotte[i].capacite<minCap) minCap=aeroport.flotte[i].capacite;
    }
    printf("Total avions: %d\n",aeroport.nbAvions);
    printf("Disponible:%d | En maintenance:%d | En vol:%d\n",dispo,maintenance,enVol);
    printf("Cap totale:%d | Min:%d | Max:%d\n",totalCap,minCap,maxCap);
}


void menuAvions() {
    int choix;
    do{
        printf("\n------------ Gestion Avions---------------\n");
        printf("p1-Ajouter un avion\n");
        printf("2-Modifier un avion\n");
        printf("3-Supprimer un avion\n");
        printf("4-Afficher les avions\n");
        printf("5-Coeff Occupation\n") ;
        printf("6-Statistiques\n") ;
        printf("0-Retour\nVotre choix:");
        scanf("%d",&choix);
        switch(choix){
            case 1: ajouterAvion(); break;
            case 2: modifierAvion(); break;
            case 3: supprimerAvion(); break;
            case 4: afficherFlotte(); break;
            case 5: calculCoeffOccupation(); break;
            case 6: statistiques(); break;
        }
    }while(choix!=0);
}

void menuAeroportGestion() {
    printf("\nNom aeroport: %s\nTotal avions:%d\n",aeroport.nom,aeroport.nbAvions);
    int dispo=0, maintenance=0, enVol=0;
    for(int i=0;i<aeroport.nbAvions;i++){
        if(strcmp(aeroport.flotte[i].statut,"Disponible")==0) dispo++;
        else if(strcmp(aeroport.flotte[i].statut,"En maintenance")==0) maintenance++;
        else if(strcmp(aeroport.flotte[i].statut,"En vol")==0) enVol++;
    }
    printf("Disponible:%d | Maintenance:%d | En vol:%d\n",dispo,maintenance,enVol);
}


void menuAeroport() {
    printf("Entrez nom aeroport: ");
    scanf(" %[^\n]",aeroport.nom);
    aeroport.nbAvions=0;
}

int main() {
    menuAeroport();
    int choix;
    do{
       printf("\n======== Menu Principal =======\n");
       printf("1-Gestion Avions\n");
       printf("2-Gestion Aeroport\n");
       printf("0-Quitter\n");
       printf("Votre choix:");
       scanf("%d",&choix);
        switch(choix){
            case 1: menuAvions(); break;
            case 2: menuAeroportGestion(); break;
        }
    }while(choix!=0);
    printf("Au revoir!\n");
    return 0;
}