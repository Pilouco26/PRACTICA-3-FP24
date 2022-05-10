#include <stdio.h>
#include <stdlib.h>


int main()
{
    FILE * fit;
    fit = fopen ( "input.txt", "r");
    int i, j, x, y, taula[10][10], taula1[10][10], comptador, compta2;
    int max_f, max_c, max_errors;
    if (fit== NULL)
    {
        printf("Error\n");
    }
    else
    {
        fscanf(fit,  "%d", &max_f);
        fscanf(fit,  "%d", &max_c);
        fscanf(fit,  "%d", &max_errors);

               for (i=0; i< max_f; i++)
               {
                   for (j=0; j< max_c; j++)
                   {
                       fscanf(fit, "%d", &taula[i][j]);
                       printf("%d ", taula[i][j]);
                   }
                   printf("\n");
               }
//
            printf("\n");
            comptador=0;
            compta2=0;
            x=0; y=1; /*freestlye*/
            printf("   ");
            for (j=0; j< max_c; j++)
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
            for (i=0; i<max_f; i++)
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
            for (i=0; i<max_f; i++)
            {
               for (j=0; j< max_c; j++)
               {
                   taula1[i+1][j+1]=taula[i][j];
                   y++;
               }
               x++;
            }


            for (i=0; i< max_f+1; i++)
               {
                   for (j=0; j< max_c+1; j++)
                   {
                       if(taula1[i][0]<10)
                       {
                           printf("%d  ", taula1[i][j]);
                       }
                       else
                       {
                           printf("%d ", taula1[i][j]);
                       }

                   }
                   printf("\n");
               }
    }

    return 0;
}
