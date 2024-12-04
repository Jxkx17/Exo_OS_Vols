#include "fonction.h"
#include <stdio.h>
#include <string.h>

void ajouterVol(Vol vols[], int *nombreDeVols, const char *code, const char *destination, const char *date, int sieges) {
    strcpy(vols[*nombreDeVols].code, code);
    strcpy(vols[*nombreDeVols].destination, destination);
    strcpy(vols[*nombreDeVols].date, date);
    vols[*nombreDeVols].siegesDisponibles = sieges;
    (*nombreDeVols)++;
}

void reserverSiege(Vol vols[], int nombreDeVols, const char *code) {
    for (int i = 0; i < nombreDeVols; i++) {
        if (strcmp(vols[i].code, code) == 0) {
            if (vols[i].siegesDisponibles > 0) {
                vols[i].siegesDisponibles--;
                printf("Reservation réussie pour le vol %s.\n", code);
            } else {
                printf("Aucun siège disponible pour le vol %s.\n", code);
            }
            return;
        }
    }
    printf("Vol non trouvé.\n");
}

void annulerReservation(Vol vols[], int nombreDeVols, const char *code) {
    for (int i = 0; i < nombreDeVols; i++) {
        if (strcmp(vols[i].code, code) == 0) {
            vols[i].siegesDisponibles++;
            printf("Annulation réussie pour le vol %s.\n", code);
            return;
        }
    }
    printf("Vol non trouvé.\n");
}

void afficherVols(Vol vols[], int nombreDeVols) {
    for (int i = 0; i < nombreDeVols; i++) {
        printf("Vol %s vers %s le %s - Sièges disponibles: %d\n", vols[i].code, vols[i].destination, vols[i].date, vols[i].siegesDisponibles);
    }
}

void enregistrerDonnees(const char *fichier, Vol vols[], int nombreDeVols) {
    FILE *file = fopen(fichier, "w");
    for (int i = 0; i < nombreDeVols; i++) {
        fprintf(file, "%s %s %s %d\n", vols[i].code, vols[i].destination, vols[i].date, vols[i].siegesDisponibles);
    }
    fclose(file);
}

void chargerDonnees(const char *fichier, Vol vols[], int *nombreDeVols) {
    FILE *file = fopen(fichier, "r");
    if (file == NULL) {
        return;
    }
    while (fscanf(file, "%s %s %s %d", vols[*nombreDeVols].code, vols[*nombreDeVols].destination, vols[*nombreDeVols].date, &vols[*nombreDeVols].siegesDisponibles) != EOF) {
        (*nombreDeVols)++;
    }
    fclose(file);
}
