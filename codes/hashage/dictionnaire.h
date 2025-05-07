#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct liste
{
    char *valeur;
    char *key;
    struct couple *suivant;
} liste;

typedef struct
{
    liste *heads;
    int taille;
} dictionnaire;

// ajoute le nouveau couple (cle, valeur) si la clé n’existe pas encore,
// ou remplace la valeur courante de la clé par la nouvelle valeur si la clé
// existe déjà
void ajouter(dictionnaire *dictionnaire, char *key, char *value);

// valeur(cle), qui retourne la valeur courante associée à la clé si elle
// existe, ou NULL si elle n’existe pas
char *valeur(dictionnaire *dictionnaire, char *key);

// retirer(cle), qui retire le couple (cle, valeur) correspondant à la clé
void retirer(dictionnaire *dictionnaire, char *key);

// taille(), qui donne le nombre de couples (clé, valeur) existants.
int taille(dictionnaire *dictionnaire);


