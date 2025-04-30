#include "liste.h"

typedef struct noeud {
    char* element;
    struct noeud* suivant;
} noeud;

typedef struct {
    noeud* tete;
    int taille;
} liste;

liste* creer(int capacite) {
    (void)capacite; // La capacité n'est pas utilisée pour une liste chaînée
    liste* l = (liste*)malloc(sizeof(liste));
    if (!l) return NULL;

    l->tete = NULL;
    l->taille = 0;
    return l;
}

void supprimer(liste* l) {
    if (!l) return;

    noeud* courant = l->tete;
    while (courant) {
        noeud* temp = courant;
        courant = courant->suivant;
        free(temp->element);
        free(temp);
    }
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

    noeud* courant = l->tete;
    for (int i = 0; i < position; i++) {
        courant = courant->suivant;
    }
    return courant->element;
}

int position(const liste* l, const char* element) {
    if (!l || !element) return -1;

    noeud* courant = l->tete;
    int index = 0;
    while (courant) {
        if (strcmp(courant->element, element) == 0) {
            return index;
        }
        courant = courant->suivant;
        index++;
    }
    return -1;
}

int contient(const liste* l, const char* element) {
    return position(l, element) != -1;
}

int ecrire(liste* l, int position, const char* element) {
    if (!l || position < 0 || position >= l->taille || !element) return 0;

    noeud* courant = l->tete;
    for (int i = 0; i < position; i++) {
        courant = courant->suivant;
    }

    char* copie = strdup(element);
    if (!copie) return 0;

    free(courant->element);
    courant->element = copie;
    return 1;
}

int ajouter(liste* l, int position, const char* element) {
    if (!l || !element || (position != -1 && (position < 0 || position > l->taille))) return 0;

    noeud* nouveau = (noeud*)malloc(sizeof(noeud));
    if (!nouveau) return 0;

    nouveau->element = strdup(element);
    if (!nouveau->element) {
        free(nouveau);
        return 0;
    }

    if (position == 0) {
        nouveau->suivant = l->tete;
        l->tete = nouveau;
    } else {
        noeud* courant = l->tete;
        for (int i = 0; i < position - 1; i++) {
            courant = courant->suivant;
        }
        nouveau->suivant = courant->suivant;
        courant->suivant = nouveau;
    }

    l->taille++;
    return 1;
}

char* retirer(liste* l, int position) {
    if (!l || position < 0 || position >= l->taille) return NULL;

    noeud* courant = l->tete;
    noeud* precedent = NULL;

    for (int i = 0; i < position; i++) {
        precedent = courant;
        courant = courant->suivant;
    }

    if (precedent) {
        precedent->suivant = courant->suivant;
    } else {
        l->tete = courant->suivant;
    }

    char* element = courant->element;
    free(courant);
    l->taille--;
    return element;
}

void vider(liste* l) {
    if (!l) return;

    noeud* courant = l->tete;
    while (courant) {
        noeud* temp = courant;
        courant = courant->suivant;
        free(temp->element);
        free(temp);
    }
    l->tete = NULL;
    l->taille = 0;
}