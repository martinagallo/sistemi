#include <stdio.h>
#include <stdlib.h>
/*
Memoria statica: Stack
Memoria dinamica: Heap
*/

void stampaVett(int a[], int dim);

int main(void)
{
    int v[] = { 1, 2, 3, 4, 5};
    int dimA = 5; 

    /*
        int dimA = 5; 
        .......
        int *dim; 
        dim = (int*) malloc(sizeof(int));
        *dim = 5;
    */
    


    printf("Array statico di %d elementi\n", dimA);
    stampaVett(v, dimA);

    /* ALLOCAZIONE DINAMICA */
    int numElem = 10; 
    int *p; 
    /* MALLOC => malloc(numByte) */
    p = (int*) malloc(sizeof(int) * numElem);
    stampaVett(p, numElem);

    /* CALLOC => calloc(numero celle per tipo, dimensione singolo elemento/tipo) */
    p = (int*) calloc(numElem, sizeof(int));
    stampaVett(p, numElem);


    /* REALLOC => realloc(indirizzo prima cella, nuova dimensione) */
    numElem = 15; 
    p = realloc(p, numElem * sizeof(int));
    stampaVett(p, numElem);

    /* FREE => free(indirizzo) */
    free(p);
    return 0;
}

void stampaVett(int a[], int dim)
{
    int i; 
    for(i = 0; i < dim; i++)
        printf("v[%d]: %d - %p\n", i, a[i], &a[i]);
}