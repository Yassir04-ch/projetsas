#include"aeroport.h"

int main() {
    int choix;
    do {
        printf("============menu principal=============\n");
        printf("1- Gestion des avions. \n");
        printf("2- Gestion de l'aeroport.\n");
        printf("3- Gestion des dates\n");
        printf("0. Quitter le program.\n");
        printf("Choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 0:
                printf("Programme termine\n");
                break;
            default:
                printf("Choix invalide\n");
                break;
        }
    } while (choix != 0);

    return 0;
}