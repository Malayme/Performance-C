#include <stdio.h>
#include <stdlib.h>

void traitement_donnees(int taille) {

    int* donnees = malloc(taille * sizeof(int));
    if (donnees == NULL) {
        perror("malloc():");
        return;
    }

    // traitement des données
    // ...
}

int main(void) {

    // boucle de traitement de milliers d'échantillons de données
    for (int i = 0; i < 1000 * 1000 * 1000; i++) {
        if (i % (500 * 1000) == 0) printf("i=%7d\n", i);
        traitement_donnees(1024);
    }

    printf("terminé\n");
    return 0;
}
