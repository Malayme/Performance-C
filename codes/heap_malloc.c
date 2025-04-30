#include <stdio.h>
#include <stdlib.h>

int main() {
    // Allouer un bloc de mémoire de 1 octet sur le tas
    void* ptr = malloc(1);

    // Vérifier si l'allocation a réussi
    if (ptr == NULL) {
        fprintf(stderr, "Échec de l'allocation de mémoire\n");
        return 1;
    }

    // Afficher l'adresse du bloc de mémoire alloué
    printf("Adresse du tas : %p\n", ptr);

    // Libérer la mémoire allouée
    free(ptr);

    return 0;
}

