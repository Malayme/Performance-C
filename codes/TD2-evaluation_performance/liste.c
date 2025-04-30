#include "liste.h"

typedef struct {
    char** elements;
    int capacite;
    int taille;
} liste;

liste* creer(int capacite) {
    liste* l = (liste*)malloc(sizeof(liste));
    if (!l) return NULL;

    l->capacite = capacite < 0 ? -1 : capacite;
    l->taille = 0;
    l->elements = (char**)malloc((capacite > 0 ? capacite : 1) * sizeof(char*));
    if (!l->elements) {
        free(l);
        return NULL;
    }
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
    if (!l || position < 0 || position >= l->taille || !element) return 0;
    char* copie = strdup(element);
    if (!copie) return 0;

    free(l->elements[position]);
    l->elements[position] = copie;
    return 1;
}

int ajouter(liste* l, int position, const char* element) {
    if (!l || !element || (position != -1 && (position < 0 || position > l->taille))) return 0;
    if (l->capacite > 0 && l->taille >= l->capacite) return 0;

    char* copie = strdup(element);
    if (!copie) return 0;

    if (position == -1 || position == l->taille) {
        l->elements[l->taille++] = copie;
    } else {
        for (int i = l->taille; i > position; i--) {
            l->elements[i] = l->elements[i - 1];
        }
        l->elements[position] = copie;
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