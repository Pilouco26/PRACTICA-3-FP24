#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "picross.h"

int main()
{

    picross_t p;
    int encerts=0;
    int errors=0;
    printf("\nBenvingut al joc del Picross:\n");
    carregar_dades(&p);
    iniciar_taula_respostes(&p);
    fer_taula(&p);

    printf("\nTenint en compte que la primera fila correspon al numero 1, i que la primera columna correspon tambe al numero 1.\n");


    while(!finalitza(encerts, errors, p))
    {
        taula_adalt(&p);
        imprimir_taula_respostes(&p);
        pregunta_posicio(&p);
        while (posicio_omplerta(&p))
        {
            printf("\nAquesta posicio ja l'has omplert, torna a triar la posicio\n");
            pregunta_posicio(&p);
        }

        pregunta_resposta(&p);

        if (resposta_ok(&p))
        {
            printf("\nCorrecte\n");
            encerts++;
        }
        else
        {
            printf("\nError\n");
            errors++;
        }
    }

    return 0;
}
