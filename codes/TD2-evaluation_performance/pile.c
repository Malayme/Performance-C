#include "pile.h"
#include <string.h>

typedef struct {
    char** elements;
    int capacite;
    int taille;
} pile;

pile* creerP(int capacite) {
    if (capacite < 0) capacite = 10; // Capacité par défaut si négative
    pile* p = (pile*)malloc(sizeof(pile));
    if (!p) return NULL;

    p->elements = (char**)malloc(capacite * sizeof(char*));
    if (!p->elements) {
        free(p);
        return NULL;
    }

    p->capacite = capacite;
    p->taille = 0;
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

    if (p->taille == p->capacite) {
        int nouvelleCapacite = p->capacite * 2;
        char** nouveauxElements = (char**)realloc(p->elements, nouvelleCapacite * sizeof(char*));
        if (!nouveauxElements) return 0;
        p->elements = nouveauxElements;
        p->capacite = nouvelleCapacite;
    }

    p->elements[p->taille++] = strdup(element);
    return 1;
}

char* depiler(pile* p) {
    if (!p || p->taille == 0) return NULL;
    char* element = p->elements[--p->taille];
    return element;
}

void viderP(pile* p) {
    if (!p) return;
    for (int i = 0; i < p->taille; i++) {
        free(p->elements[i]);
    }
    p->taille = 0;
}