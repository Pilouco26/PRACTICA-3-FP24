#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "picross.h"

int main()
{

    picross_t p;
    printf("\nBenvingut al joc del Picross:\n");
    carregar_dades(&p); //carrega les dades
    iniciar_taula_respostes(&p); //fem les taules
    fer_taula(&p);

    printf("\nTenint en compte que la primera fila correspon al numero 1, i que la primera columna correspon tambe al numero 1.\n");


    while(!finalitza(p.encerts, p.errors, p)) //mentre no hagi acabat
    {
        taula_adalt(&p); //imprimim la taula d'adalt
        imprimir_taula_respostes(&p); //imprimim la taula de les respostes que conte la taula que calcula les files i la taula de respostes
        pregunta_posicio(&p); 
        while (posicio_omplerta(&p)) // per si omple una posicio que ja estava plena
        {
            printf("\nAquesta posicio ja l'has omplert, torna a triar la posicio\n");
            pregunta_posicio(&p);
        }

        pregunta_resposta(&p);
        actualizar_joc(&p); //actualitza
    }

    return 0;
}
