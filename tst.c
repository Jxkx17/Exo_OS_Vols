#include <stdio.h>
#include "fonction.h"

int main() {
    Vol vols[10];
    int nombreDeVols = 0;

    ajouterVol(vols, &nombreDeVols, "AB123", "Paris", "2024-12-25", 150);
    if (nombreDeVols != 1) {
        printf("Test échoué: ajouterVol\n");
        return 1;
    }
    reserverSiege(vols, nombreDeVols, "AB123");
    if (vols[0].siegesDisponibles != 149) {
        printf("Test échoué: reserverSiege\n");
        return 1;
    }
    annulerReservation(vols, nombreDeVols, "AB123");
    if (vols[0].siegesDisponibles != 150) {
        printf("Test échoué: annulerReservation\n");
        return 1;
    }
    printf("Tous les tests ont réussi.\n");
    return 0;
}
