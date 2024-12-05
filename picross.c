
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "picross.h"

void carregar_dades(picross_t *p)
{
    p->encerts=0;
    p->errors=0;
    FILE * fit;
    fit = fopen ("input.txt", "r"); //OBTÉ EL FITXER
    int i, j;
    if (fit== NULL)
    {
        printf("Error al obrir el fitxer\n");
    }
    else
    {
        fscanf(fit,  "%d", &p->max_f); //SCANEJA FILES, COLUMNES I MAXIM D'ERRORS
        fscanf(fit,  "%d", &p->max_c);
        fscanf(fit,  "%d", &p->max_errors);

              for (i=0; i< p->max_f; i++)
               {
                   for (j=0; j< p->max_c; j++)
                   {
                       fscanf(fit, "%d", &p->taula[i][j]);  //OBTÉ LA TAULA
                      // printf("%d ", p->taula[i][j]);
                   }
               }
    }

}
void taula_adalt(picross_t *p)
{
     int x, y, j, i, comptador;

     p->n = p->max_f/2+1; // A la n i guardem el maxim de valors que tindrem a la taula d'adalt que seria el maxim files dividit entre 2.
    
           for (x=0; x< p->max_f; x++)  //PROCEDIMENTOMPLIR LA TAULA DE 0s.
            {
                for (y=0; y<p->max_c; y++)
                {
                    p->taula1[x][y]= 0;     
                }
            }

            comptador=0;
            y=0;
            for (j=0; j< p->max_c+1; j++)
            {
               // comptador=0;
                x= p->n;                                //inicialitzem la x a n(que seria el maxim);
                for (i=0; i<p->max_f+1; i++)   //BUCLE RECORRENT TOTA LA TAULA
                {
                    if(p->taula[i][j]==1)     //SI TROBA UN 1, AUGMENTA EL COMPATDOR
                    {
                        comptador++;
                    }
                    else                        //TROBA UN 0
                    {
                        if (comptador!=0)   //SI ABANS HI HAVIA UN 1, GUARDA EL COMPTADOR A LA TAULA DELS INDEXOS
                        {
                            p->taula1[x][y]= comptador; //guarda a la taula1 que es la taula del comptador
                            x--;                //i resta una posicio a la x
                            comptador=0; //inicialitzem el comptador
                        }
                    }
                }
                y++; //incrementem la columna de la taula
            }
    
            //PRINTEM ELS RESULTATS

           for (x= p->n; x>0; x--) //seguim recorrent de manera descendent desde el maxim que seria n, fins a 0
            {
                printf("\n");
                for(int k=0; k< p->n+2; k++ )  // printem espais per cuadrar la taula
                {
                     printf(" ");
                }
                for(y=0; y<p->max_c; y++)      
                {
                    if (p->taula1[x][y]!=0)
                    {
                        printf("%d ", p->taula1[x][y]); // printem el valor de la taula si no es 0
                    }
                    else
                    {
                        printf("  "); //si es 0 printem espais.
                    }
                }
             }
}
void iniciar_taula_respostes(picross_t *p)
{
       for (int i=0; i<p->max_f; i++)
            {
                for (int j=0; j< p->max_c+((p->n)+1); j++)
                {
                    p->taula_respostes[i][j]='X';           //S'OMPLE DE X LA TAULA DE RESPOSTES, PODRIA SER ESPAIS O EL QUE VOLGUESSIM
                }

            }
}
void fer_taula(picross_t *p)
{
    //GUARDEM ZEROS A LA TAULA 2//
        int x, y, i, j, comptador;
              for ( x=0; x< p->max_f; x++)
            {
                for ( y=0; y<p->max_c; y++)
                {
                    p->taula2[x][y]= 0;
                }
            }
//Taula de columnes amb els resultats 
            comptador=0;
             x=0;
             y=0;
             for ( i=0; i < p->max_f+1; i++) 
            {
                y=0;
                for ( j=0; j < p->max_c+1; j++)
                {
                    if(p->taula[i][j]==1) 
                    {
                        comptador++;  // sumem el comptador si trobem 1
                    }
                    else //trobem zeros
                    {
                        if (comptador!=0) //trobem zeros i el comptador el tenim diferent de 0.
                        {
                            p->taula2[x][y]= comptador; //guardem en la taula2 el comptador
                            y++; 
                            comptador=0; //inicialitzem el comptador
                        }
                    }
                }
                x++; //incrementem la fila
            }
}
void imprimir_taula_respostes(picross_t *p)
{

            int i,j,x,y;
            printf("\n"); 
            i=0;
             for (x=0; x<p->max_f; x++)
            {
                j=0;
                for ( y=0; y<p->max_c+p->n+1; y++)   //guardem el max de columnes i li sumem n per reservar espai per la taula2 que es la taula de columnnes amb resultat
                {
                    if (p->taula2[x][y]!= 0) //si no es zero 
                    {
                        if(y< p->n)// si les columnes son menors que el maxim que podem tenir
                        {
                           printf ("%d", p->taula2[x][y]); //(avans ja haurem printat la taula que es mostra adalt) printem la taula de columnes
                        }
                    }
                     else //quan trobem zeros a la taula
                    {
                        printf(" "); // printem un espai
                        if(y> p->n) //quan les columnes siguin mes grans que el maxim que podem tenir de posibilitats
                        {
                            printf("%c", p->taula_respostes[i][j]); //printem la taula de respostes
                            j++;
                        }
                    }
                }
                printf("\n");
            i++;
            }
}

void pregunta_posicio(picross_t *p)
{
    printf("\nTria una fila del 1 i al %d\n", p->max_f);                //PREGUNTA A L'USUARI
    scanf("%d", &p->fila);
    while ((p->fila<1)||(p->fila> p->max_f))
    {
        printf("\nFila no valida, tria una fila del 1 i al %d\n", p->max_f);    //Demanem fila mentre l'usuari posi una fila no valida
        scanf("%d", &p->fila);
    }

    p->fila= p->fila-1;                                 // RECORDEM QUE 1 AQUI ES 0

    printf("\nTria una columna del 1 i al %d\n", p->max_c);
    scanf("%d", &p->columna);
    while ((p->columna<1)||(p->columna>p->max_c))
    {
        printf("\nColumna no valida, tria una columna del 1 i al %d\n", p->max_c);          //Demanem columna mentre l'usuari posi una columna no valida
        scanf("%d", &p->columna);
    }
    p->columna= p->columna-1;
}

bool posicio_omplerta (picross_t *p)
{
    bool omplert=false;

    if ((p->taula_respostes[p->fila][p->columna]=='0') || (p->taula_respostes[p->fila][p->columna]=='1')) //SI DETECTA UN 1 O UN 0, VOL DIR QUE ESTA PLENA
    {
        omplert=true;
    }

    return omplert; //RETORNA EL QUE PASSA
}

void pregunta_resposta(picross_t *p)
{

    printf("\nEscriu la teva resposta\n"); //DEMANA PER LA RESPOSTA
    scanf("%d", &p->resposta);
    while ((p->resposta!=0)&&(p->resposta!=1))
    {
        printf("\nResposta no valida, recorda que la resposta nomes pot ser un 1 o un 0\n");        //USUARI S'EQUIVOCA POSANT UN NUMERO DIFERENT A 0 || 1
        scanf("%d", &p->resposta);
    }
}

bool resposta_ok(picross_t *p)
{
    bool correcte=false;
    if (p->resposta==p->taula[p->fila][p->columna])
    {
        correcte=true;
        p->taula_respostes[p->fila][p->columna]= p->resposta+ '0';          //LA RESPOSTA COINCIDEIX

    }
    return correcte;
}
bool finalitza(int encerts, int errors, picross_t p)
{
    bool r;
    r=false;
    if((errors>=p.max_errors)||(encerts==p.max_f*p.max_c)) //ACABA EL BUCLE
    {
        r=true;
    }
    if (errors==p.max_errors) //quan el jugador arriba el maxim d'errors
    {
        printf("\nGame over!\n");
    }
    else if((encerts==p.max_f*p.max_c)) //ET FELICITA quan has completat correctament
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
    return r; //RETORNA SI FINALITZA O NO

}
void actualizar_joc(picross_t *p)
{
  if (resposta_ok(&p))
        {
            printf("\nCorrecte\n");
            p->encerts++;
        }
        else
        {
            printf("\nError\n");
            p->errors++;
        }
}
