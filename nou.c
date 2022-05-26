#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void carregar_dades(int taula[10][10], int borde_esquerra[10][1], int *max_c, int *max_f, int *max_errors)
{
    int i, j, comptador, compta2;
    FILE * fit;
    fit = fopen ( "input.txt", "r");
    if (fit== NULL)
    {
        printf("Error al obrir el fitxer\n");
        return 0;
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

    for (i=0; i<*max_f; i++)
    {
        for (j=0; j<*max_c+1; j++)
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
        borde_esquerra[i][0]=compta2;
        compta2=0;
        comptador=0;
    }
}

void iniciar_taula_respostes(char taula_respostes[10][10], int max_c, int max_f)
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

void imprimir_taula_respostes(int borde_esquerra[10][1], char taula_respostes[10][10], int max_c, int max_f)
{
    printf("\n");
    int i, j;
    for (i=0; i<max_f; i++)
        {
            for (j=0; j<max_c; j++)
            {
                if (j==0)
                {
                    if (borde_esquerra[i][j]<10)
                        {
                            printf ("%d   |", borde_esquerra[i][j]);
                        }
                    else
                    {
                        if (borde_esquerra[i][j]<100)
                        {
                            printf ("%d  |", borde_esquerra[i][j]);
                        }
                        else
                        {
                            printf ("%d |", borde_esquerra[i][j]);
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

bool posicio_omplerta (char taula_respostes[10][10], int fila, int columna)
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

bool resposta_ok(int taula[10][10], int fila, int columna, int resposta, char taula_respostes[10][10])
{
    bool correcte=false;
    if (resposta==taula[fila][columna])
    {
        correcte=true;
        taula_respostes[fila][columna]=resposta+'0';
    }
    return correcte;
}


int main()
{
    int taula[10][10], index[3][10], borde_esquerra[10][1], resposta, encerts, errors, max_errors, max_f, max_c, fila, columna;
    char taula_respostes[10][10];

    encerts=0;
    errors=0;

    carregar_dades(taula, borde_esquerra, &max_c, &max_f, &max_errors);
    iniciar_taula_respostes(taula_respostes, max_c, max_f);
    printf("Tenint en compte que la primera fila correspon al numero 1, i que la primera columna correspon tambe al numero 1\n");


    while((errors<max_errors)&&(encerts<max_f*max_c))
    {
        imprimir_taula_respostes(borde_esquerra, taula_respostes, max_c, max_f);
        pregunta_posicio(&fila, &columna, max_c, max_f);
        while (posicio_omplerta(taula_respostes, fila, columna)==true)
        {
            printf("Aquesta posicio ja l'has omplert, torna a triar la posicio\n");
            pregunta_posicio(&fila, &columna, max_c, max_f);
        }

        pregunta_resposta(&resposta);

        if (resposta_ok(taula, fila, columna, resposta, taula_respostes)==true)
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
        printf("GG\n");
    }

    return 0;
}
