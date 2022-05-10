#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "picross.h"

bool obrir_fitxer(fit_t *c)
{

    bool correcte = true;
    c->fit = fopen ( "input.txt", "r"); //obra fitxer

    if (c->fit== NULL)
    {
        printf("Error\n"); //no hi ha fitxert
        correcte = false;
    }
    else
    {

        fscanf(c->fit,  "%d", &(c->max_f)); //llegeix fitxer
        fscanf(c->fit,  "%d", &(c->max_c));
        fscanf(c->fit,  "%d", &(c->max_errors));


    }



        for (int i=0; i<(c->max_f); i++)
        {
            for (int j=0; j<(c->max_c); j++)
            {
                fscanf(c->fit, "%d", &(c->taula[i][j])); //copia les dades a una taula

            }
        }

    return correcte; //retorna si ha obert el fitxer
}

void mostrar(fit_t *c)
{
    int i,j, x, y, taula1[10][10], comptador, compta2;
    max_files(c); //passa per referencies les dades
    max_columnes(c);

    for ( i=0; i<(c->max_f); i++)
        {
            for ( j=0; j<(c->max_c); j++)
            {
                printf("%d ", (c->taula[i][j]));

            }
            printf("\n");
        }
        //BRUTAL FINS AQUI

    printf("\n");
    comptador=0;
    compta2=0;
    x=0; y=1; /*freestlye*/
    printf("   ");
    for (j=0; j< (c->max_c); j++)
    {
        for (i=0; i<(c->max_f+1); i++)
        {
            if((c->taula[i][j])==1)
            {
                comptador++;
            }
            else
            {
                if (comptador!=0)
                {
                    compta2 = compta2*10+comptador;
                    comptador=0;
                }
            }
        }
        printf("%d", compta2);
        taula1[x][y]=compta2; /*freestlye*/
        y++; /*freestlye*/
        printf(" ");
        compta2=0;
        comptador=0;
    }

    comptador=0;
    compta2=0;
    x=1; y=0; /*freestlye*/
    printf("\n");
    for (i=0; i<(c->max_f); i++)
    {
        for (j=0; j<(c->max_c+1); j++)
        {
            if((c->taula[i][j])==1)
            {
                comptador++;
            }
            else
            {
                if (comptador!=0)
                {
                    compta2 = compta2*10+comptador;
                    comptador=0;
                }
            }
         }
        printf("%d", compta2);
        taula1[x][y]=compta2; /*freestlye*/
        x++; /*freestlye*/
        printf("\n");
        compta2=0;
        comptador=0;

    }

            /*a partir d'aquí és freestyle*/
    printf("\n\n");
    x=1; y=1;
    for (i=0; i<(c->max_f); i++)
    {
        for (j=0; j< (c->max_c); j++)
        {
            taula1[x][y]=(c->taula[i][j]);
            y++;
        }
        x++;
    }


    for (x=0; x<(c->max_f); x++)
    {
        for (y=0; y< (c->max_c); y++)
        {
            printf("%d ", taula1[x][y]);
        }
        printf("\n");
    }
}

int max_files (fit_t *c)
{
    return(c->max_f);
}

int max_columnes (fit_t *c)
{
    return(c->max_c);
}



void inicialitzar(fit_t *c)
{
     c->max_f=0; //INICIATLITZA
     c->max_c=0;

}
void inicialitzarj(joc_t *j)
{
     j->n_acabar=0; //INICIATLITZA

}

bool finalitza(joc_t *j, fit_t *c)
{
    bool r=false;

    if((j->errors)>=(c->max_errors))
    {
        bool r=true;
    }
    else if((j->encerts)=25)
    {
        bool r=true;
    }
    return r;
}

