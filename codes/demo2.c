#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* echantillon;
    int taille;
} donnee;

donnee* creer_donnee(int taille) {
    donnee* d = malloc(sizeof(donnee));
    if (d == NULL) {
        perror("malloc()");
        return NULL;
    }

    d->echantillon = malloc(taille * sizeof(int));
    if (d->echantillon == NULL) {
        free(d);
        perror("malloc()");
        return NULL;
    }

    d->taille = taille;
    return d;
}

void traiter_donnee(donnee* d) {
    // traitement des données
    // ...
}

void detruire_donnee(donnee* d) {
    free(d->echantillon);
    free(d);
}

int main(void) {

    for (int i = 0; i < 1000 * 1000 * 1000; i++) {
        if (i % (500 * 1000) == 0) printf("i=%7d\n", i);
        donnee* d = creer_donnee(1024);
        if (d != NULL) {
            traiter_donnee(d);
            detruire_donnee(d);
        }
    }

    printf("terminé\n");
    return 0;
}
