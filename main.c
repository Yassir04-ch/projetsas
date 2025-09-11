#include"library.h"

int main() {
   aeroport.nbAvions = 0 ;
    printf("==============================================\n");
    printf("=========== GESTION AEROPOZT =============\n");
    printf("==============================================\n");
    printf("nom de Aeroport:\n");
    scanf(" %[^\n]",aeroport.nom);
    int choix;
    do{
       printf("=====================================================\n");
       printf("=================== MENU PRINCIPAL ==================\n");
       printf("=====================================================\n");
       printf("\n");
       printf("1-Gestion Avions\n");
       printf("2-Gestion Aeroport\n");
       printf("3-calcul coefficient occupation\n");
       printf("4-statistiques");
       printf("0-Quitter\n");
       printf("Votre choix:");
       scanf("%d",&choix);
        switch(choix){
            case 1: menuAvions(); 
                break;
            case 2: menuAeroport();
                break;
            case 3: calculCoeffOccupation();
                break;
            case 4:statistique();
            break;    
            case 0: printf("le programe est quitter\n");
                break;
            default: printf("choix invalide.\n");        
        }
    }while(choix!=0);
    return 0;
}