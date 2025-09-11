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
}aeroport;
int idCounter = 1;

void ajouterAvion() {
    if(aeroport.nbAvions >= MAX) {
        printf("Flotte pleine!\n");
        return;
    }
    
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
 void afficheravion(struct avion a){
    printf("ID: %d \t modele: %s \t capacite: %d \t status: %s \n"
        ,a.idavion,a.modele,a.capacite,a.status);
 }
 void afficherflotte(){
    if (aeroport.nbAvions == 0)
    {
     printf("aucun avion.\n");
     return;
    }
    for (int i = 0; i <aeroport.nbAvions; i++)
     afficheravion(aeroport.flotte[i]);
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
void trierparcapacite(){
    for (int i = 0;i< aeroport.nbAvions-1;i++){
        for(int j = 0;j < aeroport.nbAvions-i-1;j++){
            if(aeroport.flotte[j].capacite>aeroport.flotte[j+1].capacite){
             struct Avion tmp = aeroport.flotte[j];
             aeroport.flotte[j]=aeroport.flotte[j+1];
             aeroport.flotte[j+1]= tmp;
            }
        }
    }
}
int recherchemodele(){
    trierparmodele();
 int debut=0 , fin= aeroport.nbAvions-1;
 while (debut<=fin)
 {
    int milieu = (debut+fin)/2;
    if (strcasecmp(aeroport.flotte[milieu].modele,modele)==0)
        return milieu;
    else if(strcasecmp(aeroport.flotte[milieu].modele,modele)<0)
    debut = milieu+1;
    else
    fin = milieu-1;
 }
   return -1;
}
 int recherchecapacite(int capacite){
     trierparcapacite();
    int debut = 0 , fin = aeroport.nbAvions-1;
    while (debut<=fin)
    {
        int milieur = (debut+fin)/2;
        if(aeroport.flotte[milieur].capacite==capacite)
        return milieur;
        else if (aeroport.flotte[milieur]<capacite)
         debut = milieur +1;
        else
         fin = milieur -1; 
    }
    return -1;
    
 }
    int rechercheId(int id) {
    int debut=0, fin=aeroport.nbAvions-1;
    while(debut<=fin) {
        int milieu = (debut+fin)/2;
        if(aeroport.flotte[milieu].idAvion == id) return milieu;
        else if(aeroport.flotte[milieu].idAvion < id) fin=milieu+1;
        else debut=milieu-1;
    }
    return -1;
}

void modifierAvion() {
    int id;
    printf("Entrez ID de l'avion a modifier: ");
    scanf("%d",&id);
    int pos = rechercheId(id);
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
    int pos = rechercheId(id);
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

void menuAvions() {
    int choix;
    do{
        printf("\n------------ Gestion Avions---------------\n");
        printf("1-Ajouter un avion\n");
        printf("2-Modifier un avion\n");
        printf("3-Supprimer un avion\n");
        printf("4-Afficher les avions\n");
        printf("5-recherche un avion par id\n");
        printf("6-recherche un avion par modele\n");
        printf("7-trier par capacite\n");
        printf("8-trier par modele\n");
        printf("0-retour\n");
        printf("entrez le choix");
        scanf("%d",&choix);
        switch(choix){
            case 1: ajouterAvion(); break;
            case 2: modifierAvion(); break;
            case 3: supprimerAvion(); break;
            case 4: afficherFlotte(); break;
            case 5:{
            int id;
            printf("entrez id: ");
            scanf("%d",&id);
            int pos = rechercheId(id);
            if(pos!=-1)
            afficheravion(aeroport.flotte[pos]);
            else
            printf("non trouve.\n");
            }
               break;
            case 6:{
                char modele[50];
                printf("entrez le modele: ");
                scanf(" %[^\n]",modele);
                int pos = recherchemodele();
                if (pos!=-1)
                 afficheravion(aeroport.flotte[pos]);
                 else
                 printf("non truve.\n");
                 break;
            }
            case 7: trierparcapacite();
            break;
            case 8 : trierparmodele();
            break;
            case 0 :
            break;
            default : printf("choix invalide\n");
        }
    }while(choix!=0);
}
void menuAeroport() {
    int choix;
    do
    {
     printf("=========gestion de l'Aeroport========\n");
     printf("1-changer le nom\n");
     printf("2-afficher \n");
     printf("0-retourn\n");
     scanf("%d",&choix);
 switch (choix)
 {
 case 1:
    printf("nom aeroport: ");
    scanf(" %[^\n]",aeroport.nom);
    break;
 case 2:afficherflotte();  
    break;
 default:printf("choix invalide.\n");
    
 }
    } while (choix!=0);
    
}

int main() {
   aeroport.nbAvions = 0 ;
   printf("===========Gestion Aeroport=============\n");
   printf("nom de Aeroport:\n");
    scanf(" %[^\n]",aeroport);
    int choix;
    do{
       printf("\n======== Menu Principal =======\n");
       printf("1-Gestion Avions\n");
       printf("2-Gestion Aeroport\n");
       printf("0-Quitter\n");
       printf("Votre choix:");
       scanf("%d",&choix);
        switch(choix){
            case 1: menuAvions(); 
                break;
            case 2: menuAeroportGestion();
                break;
            case 3: calculCoeffOccupation();
                break;
            case 4: statistiques();
                break;
            case 0: printf("le programe est quitter\n");
                break;
            default: printf("choix invalide.\n");        
        }
    }while(choix!=0);
    return 0;
}