#include"aeroport.h"
struct Aeroport aeroport;
int idcuonter = 1;

void ajouteravion(){
    if ( aeroport.nbavions >= max )
    {
     printf("le parc est plein\n");
    }
     
        struct avion av;
        
        printf("entrer le modele: ");
        scanf(" %[^\n]",av.modele);
        printf("entrer capacite de avion: ");
        scanf("%d",&av.capacite);
        printf("entrer status (disponible,en maintenance, en vol):");
        scanf(" %[^\n]",av.statut);
        printf("entrer la date(jour-mois-annee):");
        scanf("%d-%d-%d",&av.dateentree.jour,&av.dateentree.mois,&av.dateentree.annee);
       
        aeroport.flotte[aeroport.nbavions++]==av;
        printf("avion est ajouter");
      
}
void afficherflotte(){
    if (aeroport.nbavions==0)
    {
     printf("Aucun avion.\n");
     return;
    }
    for (int i = 0; i < aeroport.nbavions; i++)
    {
        afficheravions(aeroport.flotte[i]);
       }
    }
    void trierparid(){
      for (int i = 0; i <aeroport.nbavions-1; i++)
      {
         for(int j=0;j<aeroport.nbavions-i-1;j++){
            if(aeroport.flotte[j].idavion>aeroport.flotte[j+1].idavion){
               struct avion temp = aeroport.flotte[j];
               aeroport.flotte[j]=aeroport.flotte[j+1];
               aeroport.flotte[j+1]=temp;
            }
         }
      }
      
    }
   int recherchebinaireid( int id){
     trierparid();
     int gouche=0;
     int droite = aeroport.nbavions-1;
     while (gouche<=droite)
     {
      int milieu = (gouche+droite)/2;
      if(aeroport.flotte[milieu].idavion==id)
          return milieu;
      else if (aeroport.flotte[milieu].idavion<id)
         gouche=milieu+1;
      else
       droite=milieu-1;  
     }
     return -1;
   }
   void modifieravion(){
      int id;
      printf("entrez id de avion.");
      scanf("%d",&id);
      int pos = recherchebinaireid(id);
      if (pos == -1){
         printf("avion non trouver.\n");
         return;
      }
      printf("modifier modele: ");
      scanf(" %[^\n]",aeroport.flotte[pos].modele);
       printf("modifier capacite: ");
      scanf(" %[^\n]",aeroport.flotte[pos].capacite);
       printf("modifier staut: ");
      scanf(" %[^\n]",aeroport.flotte[pos].statut);
      
   }