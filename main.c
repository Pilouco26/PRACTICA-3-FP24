#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE * fit;
    fit = fopen ("input.txt", "r");
    int i, j, x,y, taula[10][10], taula1[5][5], comptador;
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

               printf("\n");
                printf("  ");




            for (x=0; x< 3; x++)
            {
                for (y=0; y<max_f; y++)
                {
                    taula1[x][y]= 0;
                }
            }

            comptador=0;
            x=0;  y=0;
            for (j=0; j< max_c+1; j++)
            {
               // comptador=0;
                x=2;
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
                            x--;
                            comptador=0;
                        }
                    }
                }
                y++;
            }

           for (x=0; x<3; x++)
            {
                printf("\n   ");
                for(y=0; y<5; y++)
                {
                    if (taula1[x][y]!=0) printf("%d ", taula1[x][y]);
                }
             }
              for (x=0; x< 5; x++)
            {
                for (y=0; y<3; y++)
                {
                    taula1[x][y]= 0;
                }
            }

            comptador=0;
             x=0;
             y=0;
             for (i=0; i < max_f+1; i++)
            {

                y=0;
                for (j=0; j < max_c+1; j++)
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
                            comptador=0;
                        }
                    }
                }
                x++;
            }
             printf("\n");

             for (x=0; x<5; x++)
            {
                for (y=0; y<2; y++)
                {
                    if (taula1[x][y]!= 0) printf ("%d", taula1[x][y]);
                }
                printf ("\n");
            }

    }



    return 0;
}
