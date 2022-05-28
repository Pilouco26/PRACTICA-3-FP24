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
    taula_adalt(&p);
    iniciar_taula_respostes(&p);
    imprimir_taula_respostes(&p);
    fer_taula(&p);
    printf("\nTenint en compte que la primera fila correspon al numero 1, i que la primera columna correspon tambe al numero 1.\n");


    while((errors<p.max_errors)&&(encerts<p.max_f*p.max_c))
    {
        taula_adalt(&p);
        //imprimir_taula_respostes(&p);
        fer_taula(&p);
        pregunta_posicio(&p);
        while (posicio_omplerta(&p)==true)
        {
            printf("\nAquesta posicio ja l'has omplert, torna a triar la posicio\n");
            pregunta_posicio(&p);
        }

        pregunta_resposta(&p);

        if (resposta_ok(&p)==true)
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

    if (errors==p.max_errors)
    {
        printf("\nGame over!\n");
    }
    else
    {
        printf("Joc completat!\n");
        for(int i=0; i<p.max_f; i++)
        {
            for(int j=0; j<p.max_c; j++)
            {
                printf("%d ", p.taula[i][j]);
            }
            printf("\n");
        }
    }


    return 0;
}
