#include "liste.h"

typedef struct {
    char** elements;
    int capacite;
    int taille;
} liste;

liste* creer(int capacite) {
    if (capacite < 0) capacite = 10; // Capacité par défaut si négative
    liste* l = (liste*)malloc(sizeof(liste));
    if (!l) return NULL;

    l->elements = (char**)malloc(capacite * sizeof(char*));
    if (!l->elements) {
        free(l);
        return NULL;
    }

    l->capacite = capacite;
    l->taille = 0;
    return l;
}

void supprimer(liste* l) {
    if (!l) return;
    for (int i = 0; i < l->taille; i++) {
        free(l->elements[i]);
    }
    free(l->elements);
    free(l);
}

int taille(const liste* l) {
    return l ? l->taille : -1;
}

int estVide(const liste* l) {
    return l ? l->taille == 0 : -1;
}

char* lire(const liste* l, int position) {
    if (!l || position < 0 || position >= l->taille) return NULL;
    return l->elements[position];
}

int position(const liste* l, const char* element) {
    if (!l || !element) return -1;
    for (int i = 0; i < l->taille; i++) {
        if (strcmp(l->elements[i], element) == 0) return i;
    }
    return -1;
}

int contient(const liste* l, const char* element) {
    return position(l, element) != -1;
}

int ecrire(liste* l, int position, const char* element) {
    if (!l || !element || position < 0 || position >= l->taille) return 0;
    free(l->elements[position]);
    l->elements[position] = strdup(element);
    return 1;
}

int ajouter(liste* l, int position, const char* element) {
    if (!l || !element || position < -1 || position > l->taille) return 0;

    if (l->taille == l->capacite) {
        int nouvelleCapacite = l->capacite * 2;
        char** nouveauxElements = (char**)realloc(l->elements, nouvelleCapacite * sizeof(char*));
        if (!nouveauxElements) return 0;
        l->elements = nouveauxElements;
        l->capacite = nouvelleCapacite;
    }

    if (position == -1 || position == l->taille) {
        l->elements[l->taille++] = strdup(element);
    } else {
        for (int i = l->taille; i > position; i--) {
            l->elements[i] = l->elements[i - 1];
        }
        l->elements[position] = strdup(element);
        l->taille++;
    }
    return 1;
}

char* retirer(liste* l, int position) {
    if (!l || position < 0 || position >= l->taille) return NULL;

    char* element = l->elements[position];
    for (int i = position; i < l->taille - 1; i++) {
        l->elements[i] = l->elements[i + 1];
    }
    l->taille--;
    return element;
}

void vider(liste* l) {
    if (!l) return;
    for (int i = 0; i < l->taille; i++) {
        free(l->elements[i]);
    }
    l->taille = 0;
}