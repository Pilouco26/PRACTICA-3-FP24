#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "picross.h"

bool obrir_fitxer(fit_t c)
{
    int *max_f, *max_c, *max_errors;
    bool r = true;
    &c.fit = fopen ( "input.txt", "r");

    if (c->fit== NULL)
    {
        printf("Error\n");
        r = false;
    }
    else
    {

        fscanf(c->fit,  "%d", &*max_f);
        fscanf(c->fit,  "%d", &*max_c);
        fscanf(c->fit,  "%d", &*max_errors);


    }
    return r;
}

void mostrar(fit_t c, int *max_f, int *max_c, int *max_errors)
{

        int i, j, x,y, taula[10][10], taula1[10][10], comptador;
        for (i=0; i< max_f; i++)
        {
            for (j=0; j< max_c; j++)
            {
                fscanf(&c.fit, "%d", &taula[i][j]);
                printf("%d ", taula[i][j]);

            }
            printf("\n");
        }
}

