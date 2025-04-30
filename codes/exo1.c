#include <stdio.h>

/* montre l'addresse d'un pointeur
int main(void)
{
    int *p;

    printf("Adresse du pointeur p: %p\n", &p);

    return (0);
}*/

/* montre la direction de la pile
void fonction()
{
    int p;
    printf("p = %p\n", &p);
}

int main(int argc, char *argv[])
{
    int variable = 1;

    printf("variable: %p\n", &variable);

    fonction();

    return (0);
}*/


/* montre la taille max de la pile
int * start;

void fonction()
{
    int workArea;

    long long unsigned int address1 = (long long unsigned int)start;
    long long unsigned int address2 = (long long unsigned int)&workArea;
    long long unsigned int size = address1 - address2;

    printf("size = %p, %d\n", size, size);
    fonction();
}

int main(int argc, char *argv[])
{
    int variable = 1;
    start = &variable;
    printf("variable %p\n", &variable);
    fonction();

    return (0);
}
*/

/* Montre le nombre d'octets qui séparent 2 variables

int main(int argc, char *arv[])
{
    int variable = 1;

    printf("argc = %p, variable = %p\n", &argc, &variable);
    
    return (0);
}*/

/* Modifie la valeur de retour, donc crash
int main(int argc, char *argv[])
{
    int variable = 1;
    //unsigned long long int tmp = (unsigned long long int)&variable;
    unsigned long long int *tmp2 = (unsigned long long int *)&variable;

    tmp2[0] = 0;
    tmp2[1] = 0;
    tmp2[2] = 0;
    tmp2[3] = 0;
    tmp2[4] = 0;
    tmp2[5] = 0;
    tmp2[6] = 0;
    tmp2[7] = 0;
    tmp2[8] = 0;
    tmp2[9] = 0;
    tmp2[10] = 0;
    tmp2[11] = 0;
    tmp2[12] = 0;
    return (0);
}*/


/* Partie 1.3 du TD
 
void fonction(int parametre){

    printf("p = %d\n", parametre);
}

int main(int argc, char *argv[])
{
    int variable = 1;

    fonction(variable);

    return 0;

}

void fonction2(int *p)
{
    *p = 2;
    printf("Valeur de v après changement de valeur: %d\n", *p);
}

int main(int argc, char *argv[])
{
    int variable2 = 1;
    int *p = &variable2;

    printf("Valeur de v avant changement de valeur: %d\n", variable2);

    fonction2(p);

    return (0);
}
*/

#include <stdarg.h>
#include <float.h>
/*
double max_reel(int count, ...)
{
    va_list args;
    va_start(args, count);
    
    double max = -DBL_MAX;

    for(int i = 0; i < count; i++){
        double value = va_arg(args, double);
        if(value > max){
            max = value;
        }
    }
    
    va_end(args);

    return max;

}



int main(int argc, char *argv[])
{
    printf("Le plus grand nombre entre 1.5, -1.5 et 4.5 est: %f\n", max_reel(3, 1.5, -1.5, 4.5));

    return (0);


}
*/

// Affiche 4 addresses avec un point commun
/*
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int *a = malloc(1);
    int *b = malloc(2);
    int *c = malloc(3);
    int *d = malloc(4); 

    printf("a = %p\n", &a);
    printf("b = %p\n", &b);
    printf("c = %p\n", &c);
    printf("d = %p\n", &d);

    return(0);
}
*/

// Même adresse après un free
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
int main(int argc, char *argv[])
{
    int *a = malloc(1);

    printf( "Adresse avant free: %p\n", &a);
    free(a);

    a = malloc(1);

    printf("Adresse après free: %p\n", &a);

    return (0);
}
*/

int main(int argc, char *argv[])
{
    int *a = malloc(sizeof(int));

    if (a == NULL) {
        fprintf(stderr, "Erreur d'allocation mémoire\n");
        return 1;
    }

    // Écrit en dehors des limites allouées
    a[1] = 42; // Provoque un comportement indéfini

    printf("Valeur hors limites: %d\n", a[1]);

    free(a);

    return 0;
}










