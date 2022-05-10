#include <stdio.h>
#include <stdlib.h>
#include "picross.h"
#include <stdbool.h>

int main()
{
        fit_t c;
        joc_t j;
        inicialitzar(&c);
        inicialitzarj(&c);
        if(obrir_fitxer)
        {
            obrir_fitxer(&c);
            mostrar(&c);
        }
        else
        {

           printf("AI CARAMBA!");
        }
     do
    { //aqui es on va el joc
        printf("\n\nSTROLL WDC 2024\n");
        printf("VOLS CONTINUAR JEFE? \n\nClica la tecla [+] per continuar\t Clica la tecla [0] per abandonar com un bozo \n");
        scanf("%d", &(j.n_acabar));
    }while ((!finalitza) || ((j.n_acabar)!=0));

    printf("\nthx my g, ngl u got us in the first half.");

    return 0;
}
