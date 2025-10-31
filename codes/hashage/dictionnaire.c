#include "dictionnaire.h"

#define FACTEUR_AGRANDISSEMENT 2
#define SEUIL_AGRANDISSEMENT 0.75
#define SEUIL_RAPETISSEMENT 0.25

// Fonction de hachage simple : somme des caractères de la clé
unsigned int hachage(const char *key, int taille_tableau)
{
    unsigned int hash = 0;
    for (size_t i = 0; key[i] != '\0'; i++)
    {
        hash += key[i];
    }
    return hash % taille_tableau;
}

// Fonction pour redimensionner le tableau
void redimensionner(dictionnaire *d, int nouvelle_taille)
{
    liste **nouveau_tableau = calloc(nouvelle_taille, sizeof(liste *));
    if (!nouveau_tableau)
    {
        perror("Erreur d'allocation lors du redimensionnement");
        exit(EXIT_FAILURE);
    }

    // Rehashing des éléments existants
    for (int i = 0; i < d->capacite; i++)
    {
        liste *current = d->tableau[i];
        while (current)
        {
            liste *suivant = current->suivant;
            unsigned int nouvel_index = hachage(current->key, nouvelle_taille);

            // Insérer dans le nouveau tableau
            current->suivant = nouveau_tableau[nouvel_index];
            nouveau_tableau[nouvel_index] = current;

            current = suivant;
        }
    }

    free(d->tableau);
    d->tableau = nouveau_tableau;
    d->capacite = nouvelle_taille;
}

// Ajouter un couple (clé, valeur) dans le dictionnaire
void ajouter(dictionnaire *d, char *key, char *value)
{
    if (!d || !key || !value)
        return;

    // Vérifier si un redimensionnement est nécessaire (agrandissement)
    if ((float)d->taille / d->capacite > SEUIL_AGRANDISSEMENT)
    {
        redimensionner(d, d->capacite * FACTEUR_AGRANDISSEMENT);
    }

    unsigned int index = hachage(key, d->capacite);
    liste *current = d->tableau[index];

    while (current)
    {
        if (strcmp(current->key, key) == 0)
        {
            // La clé existe déjà, mise à jour de la valeur
            free(current->valeur);
            current->valeur = strdup(value);
            return;
        }
        current = current->suivant;
    }

    // La clé n'existe pas, ajout d'un nouveau couple
    liste *nouveau = malloc(sizeof(liste));
    if (!nouveau)
        return;

    nouveau->key = strdup(key);
    nouveau->valeur = strdup(value);
    nouveau->suivant = d->tableau[index];
    d->tableau[index] = nouveau;
    d->taille++;
}

// Récupérer la valeur associée à une clé
char *valeur(dictionnaire *d, char *key)
{
    if (!d || !key)
        return NULL;

    unsigned int index = hachage(key, d->capacite);
    liste *current = d->tableau[index];

    while (current)
    {
        if (strcmp(current->key, key) == 0)
        {
            return current->valeur;
        }
        current = current->suivant;
    }

    return NULL; // Clé non trouvée
}

// Retirer un couple (clé, valeur) du dictionnaire
void retirer(dictionnaire *d, char *key)
{
    if (!d || !key)
        return;

    unsigned int index = hachage(key, d->capacite);
    liste *current = d->tableau[index];
    liste *prev = NULL;

    while (current)
    {
        if (strcmp(current->key, key) == 0)
        {
            // Clé trouvée, suppression du couple
            if (prev)
            {
                prev->suivant = current->suivant;
            }
            else
            {
                d->tableau[index] = current->suivant;
            }

            free(current->key);
            free(current->valeur);
            free(current);
            d->taille--;

            // Vérifier si un redimensionnement est nécessaire (rapetissement)
            if ((float)d->taille / d->capacite < SEUIL_RAPETISSEMENT
                && d->capacite > 10)
            {
                redimensionner(d, d->capacite / FACTEUR_AGRANDISSEMENT);
            }

            return;
        }
        prev = current;
        current = current->suivant;
    }
}

// Obtenir la taille du dictionnaire
int taille(dictionnaire *d)
{
    if (!d)
        return 0;
    return d->taille;
}

// Initialiser un dictionnaire
void initialiser_dictionnaire(dictionnaire *d, int capacite_initiale)
{
    d->tableau = calloc(capacite_initiale, sizeof(liste *));
    if (!d->tableau)
    {
        perror("Erreur d'allocation lors de l'initialisation");
        exit(EXIT_FAILURE);
    }
    d->taille = 0;
    d->capacite = capacite_initiale;
}

// Libérer toute la mémoire associée au dictionnaire
void detruire_dictionnaire(dictionnaire *d)
{
    for (int i = 0; i < d->capacite; i++)
    {
        liste *current = d->tableau[i];
        while (current)
        {
            liste *temp = current;
            current = current->suivant;
            free(temp->key);
            free(temp->valeur);
            free(temp);
        }
    }
    free(d->tableau);
}
