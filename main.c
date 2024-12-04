#include <stdio.h>
#include "fonction.h"

void afficherMenu() {
    printf("Menu:\n");
    printf("1. Ajouter un vol\n");
    printf("2. Réserver un siège\n");
    printf("3. Annuler une réservation\n");
    printf("4. Afficher les vols\n");
    printf("5. Quitter\n");
    printf("Entrez votre choix: ");
}

int main() {
    Vol vols[100];
    int nombreDeVols = 0;
    int choix;
    char code[10], destination[50], date[11];
    int sieges;

    chargerDonnees("fiche.txt", vols, &nombreDeVols);

    do {
        afficherMenu();
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                printf("Entrez le code du vol: ");
                scanf("%s", code);
                printf("Entrez la destination: ");
                scanf("%s", destination);
                printf("Entrez la date (AAAA-MM-JJ): ");
                scanf("%s", date);
                printf("Entrez le nombre de sièges: ");
                scanf("%d", &sieges);
                ajouterVol(vols, &nombreDeVols, code, destination, date, sieges);
                break;
            case 2:
                printf("Entrez le code du vol pour réserver un siège: ");
                scanf("%s", code);
                reserverSiege(vols, nombreDeVols, code);
                break;
            case 3:
                printf("Entrez le code du vol pour annuler une réservation: ");
                scanf("%s", code);
                annulerReservation(vols, nombreDeVols, code);
                break;
            case 4:
                afficherVols(vols, nombreDeVols);
                break;
            case 5:
                enregistrerDonnees("fiche.txt", vols, nombreDeVols);
                printf("Au revoir!\n");
                break;
            default:
                printf("Choix invalide, veuillez réessayer.\n");
                break;
        }
    } while (choix != 5);

    return 0;
}
