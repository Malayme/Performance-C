#include "dictionnaire.h"

void ajouter(dictionnaire *dictionnaire, char *key, char *value)
{
    if (!dictionnaire || !key || !value)
        exit(EXIT_FAILURE);

    liste *current = dictionnaire->heads;
    while (current)
    {
        //clé existe
        if (strcmp(current->key, key) == 0)
        {
            free(current->valeur);
            current->valeur = strdup(value);
            return;
        }
        current = current->suivant;
    }
    //clé existe pas
    liste *nouveau = malloc(sizeof(liste));
    if (!nouveau) 
        return;

    nouveau->key = strdup(key);
    nouveau->valeur = strdup(value);
    nouveau->suivant= dictionnaire->heads;
    dictionnaire->heads = nouveau;
    dictionnaire->taille++;
    
}

char *valeur(dictionnaire *dictionnaire, char *key)
{
    if(!dictionnaire || !key)
    {
        exit(EXIT_FAILURE);
    }

    liste *current = dictionnaire->heads;
    while (current)
    {
        if(strcmp(current->key, key) == 0)
        {
            return current->valeur;
        }
        current = current->suivant;
    }

    return NULL; //pas de clé
}

void retirer(dictionnaire *dictionnaire, char *key)
{
    if(!dictionnaire || !key)
        return;
    
    liste *current = dictionnaire->heads;
    liste *prev = NULL;

    while (current)
    {
        if (strcmp(current->key, key) == 0){
            //Clé trouvée
            if(prev) {
                prev->suivant = current->suivant;
            } else {
                dictionnaire->heads = current->suivant;
            }

            free(current->key);
            free(current->valeur);
            free(current);
            dictionnaire->taille--;
            return;
        }
        prev = current;
        current = current->suivant;
    }
}

int taille(dictionnaire *dictionnaire)
{
    if(!dictionnaire)
        return (0);
    return dictionnaire->taille;
}

int main()
{
    dictionnaire dictionnaire = {NULL, 0};

    ajouter(&dictionnaire, "cle1", "valeur1");
    ajouter(&dictionnaire, "cle2", "valeur2");
    printf("Taille du dictionnaire : %d\n", taille(&dictionnaire));
    printf("Valeur de clé 1: %s\n", valeur(&dictionnaire, "cle1"));

    retirer(&dictionnaire, "cle1");
    printf("Taille après la suppression : %d\n", taille(&dictionnaire));
    printf("Valeur de cle1: %s\n", valeur(&dictionnaire, "cle1"));

    return 0;

}
