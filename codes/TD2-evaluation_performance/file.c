#include "file.h"
#include <string.h>

typedef struct {
    char** elements;
    int capacite;
    int taille;
    int debut;
} file;

file* creerF(int capacite) {
    if (capacite < 0) capacite = 10; // Capacité par défaut si négative
    file* f = (file*)malloc(sizeof(file));
    if (!f) return NULL;

    f->elements = (char**)malloc(capacite * sizeof(char*));
    if (!f->elements) {
        free(f);
        return NULL;
    }

    f->capacite = capacite;
    f->taille = 0;
    f->debut = 0;
    return f;
}

void supprimerF(file* f) {
    if (!f) return;
    for (int i = 0; i < f->taille; i++) {
        free(f->elements[(f->debut + i) % f->capacite]);
    }
    free(f->elements);
    free(f);
}

int tailleF(const file* f) {
    return f ? f->taille : -1;
}

int estVideF(const file* f) {
    return f ? f->taille == 0 : -1;
}

char* debut(const file* f) {
    if (!f || f->taille == 0) return NULL;
    return f->elements[f->debut];
}

int enfiler(file* f, const char* element) {
    if (!f || !element) return 0;

    if (f->taille == f->capacite) {
        int nouvelleCapacite = f->capacite * 2;
        char** nouveauxElements = (char**)malloc(nouvelleCapacite * sizeof(char*));
        if (!nouveauxElements) return 0;

        for (int i = 0; i < f->taille; i++) {
            nouveauxElements[i] = f->elements[(f->debut + i) % f->capacite];
        }

        free(f->elements);
        f->elements = nouveauxElements;
        f->capacite = nouvelleCapacite;
        f->debut = 0;
    }

    int position = (f->debut + f->taille) % f->capacite;
    f->elements[position] = strdup(element);
    f->taille++;
    return 1;
}

char* defiler(file* f) {
    if (!f || f->taille == 0) return NULL;

    char* element = f->elements[f->debut];
    f->debut = (f->debut + 1) % f->capacite;
    f->taille--;
    return element;
}

void viderF(file* f) {
    if (!f) return;
    for (int i = 0; i < f->taille; i++) {
        free(f->elements[(f->debut + i) % f->capacite]);
    }
    f->taille = 0;
    f->debut = 0;
}