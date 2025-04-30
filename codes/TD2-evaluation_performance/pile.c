#include "pile.h"
#include <string.h>
#include <stdio.h>

typedef struct {
    char** elements;
    int capacite;
    int taille;
} pile;

pile* creerP(int capacite) {
    pile* p = (pile*)malloc(sizeof(pile));
    if (!p) return NULL;

    p->capacite = capacite < 0 ? -1 : capacite;
    p->taille = 0;
    p->elements = (char**)malloc((capacite > 0 ? capacite : 1) * sizeof(char*));
    if (!p->elements) {
        free(p);
        return NULL;
    }
    return p;
}

void supprimerP(pile* p) {
    if (!p) return;
    for (int i = 0; i < p->taille; i++) {
        free(p->elements[i]);
    }
    free(p->elements);
    free(p);
}

int tailleP(const pile* p) {
    return p ? p->taille : -1;
}

int estVideP(const pile* p) {
    return p ? p->taille == 0 : -1;
}

char* sommet(const pile* p) {
    if (!p || p->taille == 0) return NULL;
    return p->elements[p->taille - 1];
}

int empiler(pile* p, const char* element) {
    if (!p || !element) return 0;
    if (p->capacite > 0 && p->taille >= p->capacite) return 0;

    char* copie = strdup(element);
    if (!copie) return 0;

    p->elements[p->taille++] = copie;
    return 1;
}

char* depiler(pile* p) {
    if (!p || p->taille == 0) return NULL;
    return p->elements[--p->taille];
}

void viderP(pile* p) {
    if (!p) return;
    for (int i = 0; i < p->taille; i++) {
        free(p->elements[i]);
    }
    p->taille = 0;
}