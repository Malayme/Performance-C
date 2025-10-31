#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dictionnaire.h"

#define NOMBRE_RECHERCHES 1000000

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <nombre_elements> <taille_initiale>\n", argv[0]);
        return 1;
    }

    int nombre_elements = atoi(argv[1]);
    int taille_initiale = atoi(argv[2]);

    dictionnaire d;
    initialiser_dictionnaire(&d, taille_initiale);

    // Insérer des éléments dans le dictionnaire
    char key[20];
    for (int i = 0; i < nombre_elements; i++) {
        sprintf(key, "cle%d", i);
        ajouter(&d, key, "valeur");
    }

    // Mesurer le temps de recherche
    clock_t debut = clock();
    for (int i = 0; i < NOMBRE_RECHERCHES; i++) {
        sprintf(key, "cle%d", rand() % nombre_elements);
        valeur(&d, key);
    }
    clock_t fin = clock();

    double temps = (double)(fin - debut) / CLOCKS_PER_SEC;
    printf("Temps pour %d recherches : %f secondes\n", NOMBRE_RECHERCHES, temps);

    detruire_dictionnaire(&d);
    return 0;
}