 #include"library.h"
 int idCounter = 1;
// fanction pour ajouter un avion a la flotte de l'aeroport
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
    printf("entrez la date d'entree jour-mois-annee ");
    scanf("%d-%d-%d",&a.dateentree.jour,&a.dateentree.mois,&a.dateentree.annee);

    aeroport.flotte[aeroport.nbAvions++] = a;
    printf("Avion ajoute avec ID %d\n", a.idAvion);
}
//fonction pour afficher les informations d'un avion
 void afficherAvion(struct Avion a){
    printf("ID: %d \t modele: %s \t capacite: %d \t statut: %s \t %d-%d-%d\n"
        ,a.idAvion,a.modele,a.capacite,a.statut,a.dateentree);
 }
 //fonction pour afficher tous les avions
 void afficherFlotte(){
    if (aeroport.nbAvions == 0)
    {
      printf("aucun avion.\n");
      return;
    }
    for (int i = 0; i <aeroport.nbAvions; i++)
      afficherAvion(aeroport.flotte[i]);
 }
 //fonction pour trier la flotte par modele 
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
//fonction pour trier la flotte par capacite
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
//recherche binaire d'un avion par modele
int recherchemodele(char modele[]){
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
//recherche binaire d'un avion par modele
 int recherchecapacite(int capacite){
     trierparcapacite();
    int debut = 0 , fin = aeroport.nbAvions-1;
    while (debut<=fin)
    {
        int milieu = (debut+fin)/2;
        if(aeroport.flotte[milieu].capacite==capacite)
        return milieu;
        else if (aeroport.flotte[milieu].capacite<capacite)
         debut = milieu +1;
        else
         fin = milieu -1; 
    }
    return -1;
    
 }
 //fonction pour trier les avions par id
   void trierparid(){
     for (int i = 0; i <aeroport.nbAvions-1; i++)
     {
       for (int j = 0; j <aeroport.nbAvions-i-1; j++)
       {
        if (aeroport.flotte[j].idAvion>aeroport.flotte[j+1].idAvion)
        {
           struct Avion tmp = aeroport.flotte[j];
           aeroport.flotte[j] = aeroport.flotte[j+1];
           aeroport.flotte[j+1] = tmp;
        }
       }
     }
//recherche binaire d'un avion par id
   }
    int rechercheId(int id) {
    trierparid();
    int debut=0, fin=aeroport.nbAvions-1;
    while(debut<=fin) {
        int milieu = (debut+fin)/2;
        if(aeroport.flotte[milieu].idAvion == id) return milieu;
        else if(aeroport.flotte[milieu].idAvion < id) debut = milieu+1;
        else fin = milieu-1;
    }
    return -1;
}
//fonction pour modifier les informations d'un avion
void modifierAvion() {
    int id;
    printf("Entrez ID de l'avion a modifier: ");
    scanf("%d",&id);
    int pos = rechercheId(id);
    if(pos == -1) { printf("Avion non trouve!\n"); 
        return;
     }
    printf("Modifier modele: ");
    scanf(" %[^\n]",aeroport.flotte[pos].modele);
    printf("Modifier capacite: ");
    scanf("%d",&aeroport.flotte[pos].capacite);
    printf("Modifier statut: ");
    scanf(" %[^\n]",aeroport.flotte[pos].statut);
    printf("modifier la date: ");
    char dateStr[20];
    fgets(dateStr, sizeof(dateStr),stdin);

    scanf(dateStr," %d-%d-%d",&aeroport.flotte[pos].dateentree.jour,
    &aeroport.flotte[pos].dateentree.mois,aeroport.flotte[pos].dateentree.annee);
    printf("Avion modifie.\n");
}
//fonction pour supprimer un avion
void supprimerAvion() {
    int id;
    printf("Entrez ID de l'avion a supprimer: ");
    scanf("%d",&id);
    int pos = rechercheId(id);
    if(pos==-1)
     { 
        printf("Avion non trouve!\n"); 
        return;
     }
    for(int i=pos;i<aeroport.nbAvions-1;i++) {
        aeroport.flotte[i] = aeroport.flotte[i+1];
    }
    aeroport.nbAvions--;
    printf("Avion supprime.\n");
}
//fonction pour calculer le coefficien
void calculCoeffOccupation() {
    int dispo=0;
    for(int i=0;i<aeroport.nbAvions;i++)
        if(strcmp(aeroport.flotte[i].statut,"Disponible")==0) dispo++;
    if(aeroport.nbAvions==0){printf("Aucun avion.\n"); return;}
    float coeff = ((float)dispo/aeroport.nbAvions)*100;
    printf("Coeff. occupation: %.2f%%\n",coeff);
}
//fonction pour calculer et afficher les statistique de les avions 
void statistique(){
    if (aeroport.nbAvions==0)
    {
      printf("aucun avion on aeroport.\n");
      return ;
    }
    int dispo = 0 , maintenance = 0 , Envol = 0;
    int mincap = aeroport.flotte[0].capacite;
    int maxcap = aeroport.flotte[0].capacite;
    int totalcap=0;
  for(int i = 0 ;i<aeroport.nbAvions ; i++){
    totalcap+=aeroport.flotte[i].capacite;
    if(strcasecmp(aeroport.flotte[i].statut,"Disponible")==0)
       dispo++;
    if (strcasecmp(aeroport.flotte[i].statut,"En maintenance")==0)
     maintenance++;
    if(strcasecmp(aeroport.flotte[i].statut,"En vol")==0)
     Envol++;
    if (aeroport.flotte[i].capacite>maxcap)
     maxcap=aeroport.flotte[i].capacite;
    if (aeroport.flotte[i].capacite<mincap)
     mincap=aeroport.flotte[i].capacite;
     
}
   printf("total avions est : %d \n",aeroport.nbAvions);
   printf("disponible est : %d\n ",dispo);
   printf("En maintenance est : %d\n",maintenance);
   printf("En vol est : %d\n ",Envol);
   printf("le maximum capacite est : %d\n",maxcap);
   printf("le minimum capacite est : %d\n",mincap);
   printf("la capacite total est : %d\n",totalcap);
}
//mune de les avions pour choisir le tulisateur les case 
void menuAvions() {
    int choix;
    do{
        printf("==============================================\n");
        printf("===          Gestion Avions                ===\n");
        printf("==============================================\n");
        printf("\n");
        printf("1-Ajouter un avion\n");
        printf("2-Modifier un avion\n");
        printf("3-Supprimer un avion\n");
        printf("4-Afficher les avions\n");
        printf("5-recherche un avion par id\n");
        printf("6-recherche un avion par modele\n");
        printf("7-trier par capacite\n");
        printf("8-trier par modele\n");
        printf("0-retour\n");
        printf("entrez le choix: ");
        scanf("%d",&choix);
        switch(choix){
            case 1: ajouterAvion(); break;
            case 2: modifierAvion(); break;
            case 3: supprimerAvion(); break;
            case 4: afficherFlotte(); break;
            case 5:{
                int id;
                printf("entrez ID: ");
                scanf("%d",&id);
                int pos = rechercheId(id);
                if(pos!=-1)
                afficherAvion(aeroport.flotte[pos]);
                else
                printf("non trouve.\n");
                }
               break;
            case 6:{
                char modele[50];
                printf("entrez le modele: ");
                scanf(" %[^\n]",modele);
                int pos = recherchemodele(modele);
                if (pos!=-1)
                 afficherAvion(aeroport.flotte[pos]);
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
//menu de aeroport 
void menuAeroport() {
    int choix;
    do
    {
     printf("==========================================\n");
     printf("========= GESTION de l'AEROPORT ==========\n");
     printf("==========================================\n");
     printf("\n");
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
 case 2:afficherFlotte();  
    break;
 default:printf("choix invalide.\n");
    
 }
    } while (choix!=0);
    
}
