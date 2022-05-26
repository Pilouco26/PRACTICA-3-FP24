#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "picross.h"


int main()
{
    int taula[15][15], taula1[15][15], borde_esquerra[15][1], resposta, encerts, errors, max_errors, max_f, max_c, fila, columna, com3;
    char taula_respostes[15][15];

    com_t c;
    encerts=0;
    errors=0;

    carregar_dades(taula, borde_esquerra, &max_c, &max_f, &max_errors, &c);
    iniciar_taula_respostes(taula_respostes, max_c, max_f);
    printf("Tenint en compte que la primera fila correspon al numero 1, i que la primera columna correspon tambe al numero 1\n");


    while((errors<max_errors)&&(encerts<max_f*max_c))
    {
        iniciar_taula_adalt(taula, taula1, max_c, max_f);
        imprimir_taula_respostes(borde_esquerra, taula_respostes, max_c, max_f, c);
        pregunta_posicio(&fila, &columna, max_c, max_f);
        while (posicio_omplerta(taula_respostes, fila, columna))
        {
            printf("Aquesta posicio ja l'has omplert, torna a triar la posicio\n");
            pregunta_posicio(&fila, &columna, max_c, max_f);
        }

        pregunta_resposta(&resposta);

        if (resposta_ok(taula, fila, columna, resposta, taula_respostes))
        {
            printf("Correcte\n");
            encerts++;
        }
        else
        {
            printf("error\n");
            errors++;
        }
    }

    if (errors==max_errors)
    {
        printf("Game over\n");
    }
    else
    {
        printf("GG nigga\n");
    }

    return 0;
}
