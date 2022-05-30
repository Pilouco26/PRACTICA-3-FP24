#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "picross.h"

int main()
{

    picross_t p;
    printf("\nBenvingut al joc del Picross:\n");
    carregar_dades(&p);
    iniciar_taula_respostes(&p);
    fer_taula(&p);

    printf("\nTenint en compte que la primera fila correspon al numero 1, i que la primera columna correspon tambe al numero 1.\n");


    while(!finalitza(p.encerts, p.errors, p))
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
        actualizar_joc(&p);
    }

    return 0;
}
