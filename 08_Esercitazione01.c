#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

void visualizzaMenu();
int verificaPalindroma(char* str);
void concatenaStringhe(char* str1,char* str2);

int main(void)
{
    int *scelta;
    scelta = (int*)malloc(sizeof(int));
    //Es 1
    char *str;
    //Es 2
    char *str1;
    char *str2;

   
    do{
        visualizzaMenu();
        printf("Scelta > ");
        scanf("%d", scelta);

        system("@cls||clear");
        fflush(stdin);
        switch(*scelta)
        {
            case 1:
            str = (char*)malloc(sizeof(char) * MAX); //dichiarato un vettore grande 100
            /*Data una stringa in input, verificare se è PALINDROMA*/
            printf("Inserisci stringa > ");
            gets(str);
            //rialloco per ottimizzare spazio in memoria (rimuovo le celle in eccesso)
            str = realloc(str, sizeof(char)*(strlen(str)) + 1);
            /*printf("Stringa inserita > %s\n", str);
            printf("Dimensione > %s\n", strlen(str));*/
            if(verificaPalindroma(str) == 1){
                printf("La stringa %s e' palindroma\n", str);
            }
            else
                printf("La stringa %s NON e' palindroma\n", str);
            free(str);
            break;
            case 6:
            /*Date due stringhe in input, contarle e stampare il risultato*/
            str1 = (char*)malloc(sizeof(char) * MAX);
            str2 = (char*)malloc(sizeof(char) * MAX);
            if(str1 != NULL && str2 != NULL)
            {
                printf("Stringa 1 > ");
                gets(str1);
                printf("Stringa 2 > ");
                gets(str2);
            str1 = realloc(str1, sizeof(char)*(strlen(str1)) + 1);
            str2 = realloc(str1, sizeof(char)*(strlen(str2)) + 1);
            concatenaStringhe(str1,str2);
            }
            free(str1);
            free(str2);
            break;
            case 0:
                printf("Arrivederci....\n");
            break;
            default:
                printf("Opzione non disponibile\n");
            break;
        }

    }while(*scelta!= 0);
    free(scelta);

    return 0;
}


void visualizzaMenu()
{
    printf("\nESERCITAZIONE - PUNTATORI\n");
    printf("1. Verifica se una stringa e' palindroma\n");
    printf("2. Inverti una stringa\n");
    printf("3. Conta vocali e consonanti di una stringa\n");
    printf("4. Cerca un valore in un vettore\n");
    printf("5. Calcola minimo, massimo e media di un vettore\n");
    printf("6. Concatena due stringhe\n");
    printf("0. Esci\n");
}


int verificaPalindroma(char* str)
{
    // 'a' 'n' 'n' 'a'
    // 'l' 'u' 'c' 'a'
    char* inizio;
    char* fine;
    inizio = str;
    fine = inizio + (strlen(str) - 1);

    while((inizio < fine) &&(*inizio == *fine)) // due condizioni che mi permettono di getsire si ala sovrapposizione dei puntatori, sia l'uscita
    {
        inizio++;
        fine--;
    }
    if(*inizio == *fine)
        return 1;
    return 0;
}

void concatenaStringhe(char* str1,char* str2)
{
    str1=realloc(str1, sizeof(char)* (strlen(str1)+ strlen(str2)+1));
}