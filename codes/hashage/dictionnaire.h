#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define FACTEUR_AGRANDISSEMENT 2
#define SEUIL_AGRANDISSEMENT 0.75
#define SEUIL_RAPETISSEMENT 0.25

typedef struct liste
{
    char *valeur;
    char *key;
    struct liste *suivant;
} liste;

typedef struct dictionnaire
{
    liste **tableau; // Tableau dynamique de listes chaînées
    int taille; // Nombre d'éléments dans le dictionnaire
    int capacite; // Taille actuelle du tableau
} dictionnaire;

// ajoute le nouveau couple (cle, valeur) si la clé n’existe pas encore,
// ou remplace la valeur courante de la clé par la nouvelle valeur si la clé
// existe déjà
void ajouter(dictionnaire *d, char *key, char *value);

// valeur(cle), qui retourne la valeur courante associée à la clé si elle
// existe, ou NULL si elle n’existe pas
char *valeur(dictionnaire *d, char *key);

// retirer(cle), qui retire le couple (cle, valeur) correspondant à la clé
void retirer(dictionnaire *d, char *key);

// taille(), qui donne le nombre de couples (clé, valeur) existants
int taille(dictionnaire *d);

// Initialise un dictionnaire avec une capacité initiale donnée
void initialiser_dictionnaire(dictionnaire *d, int capacite_initiale);

// Libère toute la mémoire associée au dictionnaire
void detruire_dictionnaire(dictionnaire *d);
