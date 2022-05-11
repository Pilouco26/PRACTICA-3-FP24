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

void mostrar(fit_t *c, joc_t *g)
{
    int i,j, x, y, comptador, compta2;
    max_files(c); //passa per referencies les dades
    max_columnes(c);

    //BRUTAL FINS AQUI

    printf("\n");
    comptador=0;
    compta2=0;
    x=0; y=1; /*freestlye*/
    printf("   ");
    for (j=0; j<(c->max_c); j++)
    {
        for (i=0; i<((c->max_f)+1); i++)
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
        //printf("%d", compta2);
        g->taula_j[x][y]=compta2; /*freestlye*/
        y++; /*freestlye*/
        //printf(" ");
        compta2=0;
        comptador=0;
    }

    comptador=0;
    compta2=0;
    x=1; y=0; /*freestlye*/
   // printf("\n");

    for (i=0; i<(c->max_f); i++)
    {
        for (j=0; j<((c->max_c)+1); j++)
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
        (g->taula_j[x][y])=compta2; /*freestlye*/
        x++; /*freestlye*/
       // printf("\n");
        compta2=0;
        comptador=0;

    }

            /*a partir d'aquí és freestyle*/
    printf("\n");
    x=1; y=1;
    for (i=0; i<(c->max_f); i++)
    {
        for (j=0; j<(c->max_c); j++)
        {
            (g->taula_j[i+1][j+1])=(c->taula[i][j]);
            y++;
        }
        x++;
    }


    for (i=0; i<(c->max_f+1); i++)
    {
        for (j=0; j<(c->max_c+1); j++)
        {
            if((g->taula_j[i][0])<10)
            {
                printf("%d  ", (g->taula_j[i][j]));
            }
            else
            {
                printf("%d ", (g->taula_j[i][j]));
            }

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
void inicialitzarj(joc_t *g)
{
     g->n_acabar=0;
     g->encerts=0;
     g->errors=0; //INICIATLITZA

}

bool finalitza(joc_t *g, fit_t *c)
{
    bool r= false;
    printf("VOLS CONTINUAR JEFE? \n\nClica la tecla [+] per continuar\t Clica la tecla [0] per abandonar com un bozo \n");
    scanf("%d", &(g->n_acabar));
    if((g->n_acabar)==0)
    {
        bool r=true;
        printf("\nthx my g, ngl u got us in the first half.");
    }
    if((g->errors)>=(c->max_errors))
    {
        bool r=true;
        printf("has superat el maxim d'erros. Tbf has de ser completament retrasat per-ho :/. shmmm");
    }
    if((g->encerts)==25)
    {
        bool r=true;
        printf("GG. Time to touch grass ");
    }
    return r;
}
void presentacio(joc_t *g)
{
    printf("Hola, Benvingut al Mundial del 2022 de PICROSS\n");
    printf("----------------------------------------------\n");
    printf("----------------------------------------------\n");
    printf("----------------------------------------------\n");
    printf("----------------------------------------------\n");
    printf("Abans de tot volem saber quin és el teu nom, com et dius?\n");
    scanf("%s", &(g->nom));
    printf("gucci %s, vamos a darle que renta mazo aquest joc!", (g->nom));
}
