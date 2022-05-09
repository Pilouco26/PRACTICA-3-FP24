#include <stdio.h>
#include <stdlib.h>
#include "picross.h"
#include <stdbool.h>

int main()
{
    fit_t c;
    if(obrir_fitxer(&c))
    {
        //mostrar(&c);
    }
    else
    {

        printf("AI CARAMBA!");
    }
/*
            comptador=0;
            x=0;  y=0;
            printf("   ");
            for (i=0; i<max_f+1; i++)
            {
               for (j=0; j< max_c+1; j++)
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
                            y++;
                            printf ("%d", comptador);
                            comptador=0;

                        }
                    }
                }
                printf(" ");
                x++;
            }
            printf("\n");
             comptador=0;
             x=0;  y=0;
             for (j=0; j< max_c+1; j++)
            {
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
                            printf ("%d", comptador);
                            comptador=0;

                        }


                    }
                }
                printf("\n");
                y++;
            }
    }


*/
    return 0;
}
