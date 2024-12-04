#ifndef FONCTION_H
#define FONCTION_H

typedef struct {
    char code[10];
    char destination[50];
    char date[11];
    int siegesDisponibles;
} Vol;

void ajouterVol(Vol vols[], int *nombreDeVols, const char *code, const char *destination, const char *date, int sieges);
void reserverSiege(Vol vols[], int nombreDeVols, const char *code);
void annulerReservation(Vol vols[], int nombreDeVols, const char *code);
void afficherVols(Vol vols[], int nombreDeVols);
void enregistrerDonnees(const char *fichier, Vol vols[], int nombreDeVols);
void chargerDonnees(const char *fichier, Vol vols[], int *nombreDeVols);

#endif
