#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "picross.h"



void carregar_dades(int taula[15][15], int borde_esquerra[15][1], int *max_c, int *max_f, int *max_errors, com_t *c )
{
    int i, j, comptador, compta2, com1, com4;
    FILE * fit;
    fit = fopen ( "input.txt", "r");
    if (fit== NULL)
    {
        printf("Error al obrir el fitxer\n");

    }
    else
    {
        fscanf(fit,  "%d", max_f);
        fscanf(fit,  "%d", max_c);
        fscanf(fit,  "%d", max_errors);

    }

    for (i=0; i< *max_f; i++)
    {
        for (j=0; j< *max_c; j++)
        {
            fscanf(fit, "%d", &taula[i][j]);
            printf("%d ", taula[i][j]);
        }
        printf("\n");
    }

    comptador=0;
    compta2=0;
    com4=0;
    com1=0;

    for (i=0; i<*max_f; i++)
    {
        for (j=0; j< *max_c+1; j++)
        {
            if(taula[i][j]==1)
            {
                comptador++;
            }
            else
            {
                if (comptador!=0)
                {
                    compta2 = compta2*10+comptador;
                    comptador=0;
                    com1++;
                }
            }
        }
        borde_esquerra[i][0]=compta2;
        compta2=0;
        comptador=0;
        if(com4<com1) com4=com1;
        com1=0;
    }
    c->com3=com4;

}
void iniciar_taula_adalt(int taula[15][15], int taula1[15][15], int max_c, int max_f, int max_errors, int com2)
{
    int x, y, i, j, comptador, com1;

     for (x=0; x<com2; x++)
            {
                for (y=0; y<max_f; y++)
                {
                    taula1[x][y]= 0;
                }
            }

            comptador=0;
            com1=0;
            com2=0;
            x=0;  y=0;
            for (j=0; j< max_c+1; j++)
            {
               // comptador=0;
                x=0;
                for (i=0; i<max_f+1; i++)
                {
                    if(taula[i][j]==1)
                    {
                        comptador++;
                    }
                    else
                    {
                        if (comptador!=0)
                        {
                            taula1[x][y]= comptador;
                            x++;
                            comptador=0;
                            com1++;
                        }
                    }
                }
                y++;

                if(com2<com1) com2=com1;
                com1=0;
                }
                printf("%d \n", com2);

             for(y=0; y<max_f; y++)
             {

                 for(x=0; x<com2; x++)
                 {
                     if(taula1[x][y]!=0)printf("%d ", taula1[x][y]);

                 }

             }
}

void iniciar_taula_respostes(char taula_respostes[15][15], int max_c, int max_f)
{
    int i, j;
    for (i=0; i<max_f; i++)
            {
                for (j=0; j<max_c+1; j++)
                {
                    taula_respostes[i][j]='X'; /*omple tota la taula amb el caràcter X*/
                }
            }
}

void imprimir_taula_respostes(int borde_esquerra[15][1], char taula_respostes[15][15], int max_c, int max_f, com_t c )
{
    printf("\n");
    int com5=c.com3;
    int i, j, k;
    for (i=0; i<max_f; i++)
        {
            for (j=0; j<max_c; j++)
            {
                if (j==0)
                {

                    if (borde_esquerra[i][j]<10)
                        {
                            printf ("%d", borde_esquerra[i][j]);
                            for(k=0; k<com5; k++)
                            {
                                printf(" ");
                            }
                            printf("|");
                        }
                    else
                    {
                        if (borde_esquerra[i][j]<100)
                        {
                            printf ("%d", borde_esquerra[i][j]);
                            for(k=0; k<com5-1; k++)
                            {
                                printf(" ");
                            }
                            printf("|");
                        }
                        else if (borde_esquerra[i][j]<1000)
                        {
                            printf ("%d", borde_esquerra[i][j]);
                            for(k=0; k<com5-2; k++)
                            {
                                printf(" ");
                            }
                            printf("|");
                        }
                        else if (borde_esquerra[i][j]<10000)
                        {
                            printf ("%d", borde_esquerra[i][j]);
                            for(k=0; k<com5-3; k++)
                            {
                                printf(" ");
                            }
                            printf("|");
                        }
                        else
                        {
                           printf ("%d", borde_esquerra[i][j]);
                            for(k=0; k<com5-4; k++)
                            {
                                printf(" ");
                            }
                            printf("|");
                        }

                    }
                }
                    printf(" %c", taula_respostes[i][j]);
            }
            printf(" |\n");
        }
    printf("\n");
}

void pregunta_posicio(int *fila, int *columna, int max_c, int max_f)
{
    printf("Tria una fila del 1 i al %d\n", max_f);
    scanf("%d", fila);
    while ((*fila<1)||(*fila>max_f))
    {
        printf("Fila no valida, tria una fila del 1 i al %d\n", max_f);
        scanf("%d", fila);
    }

    *fila= *fila-1;

    printf("Tria una columna del 1 i al %d\n", max_c);
    scanf("%d", columna);
    while ((*columna<1)||(*columna>max_c))
    {
        printf("Columna no valida, tria una columna del 1 i al %d\n", max_c);
        scanf("%d", columna);
    }
    *columna= *columna-1;
}

bool posicio_omplerta (char taula_respostes[15][15], int fila, int columna)
{
    bool omplert=false;

    if ((taula_respostes[fila][columna]=='0') || (taula_respostes[fila][columna]=='1'))
    {
        omplert=true;
    }

    return omplert;
}

void pregunta_resposta(int *resposta)
{

    printf("Escriu la teva resposta\n");
    scanf("%d", resposta);
    while ((*resposta!=0)&&(*resposta!=1))
    {
        printf("Resposta no valida, recorda que la resposta nomes pot ser un 1 o un 0\n");
        scanf("%d", resposta);
    }
}

bool resposta_ok(int taula[15][15], int fila, int columna, int resposta, char taula_respostes[15][15])
{
    bool correcte=false;
    if (resposta==taula[fila][columna])
    {
        correcte=true;
        taula_respostes[fila][columna]=resposta+'0';
    }
    return correcte;
}
