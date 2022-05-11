#include <stdio.h>
#include <stdlib.h>
#include "picross.h"
#include <stdbool.h>

int main()
{
        fit_t c;
        joc_t g;
        inicialitzar(&c);
        inicialitzarj(&c);
        if(obrir_fitxer)
        {
            obrir_fitxer(&c);

        }
        else
        {

           printf("AI CARAMBA!");
        }
     do
    { //aqui es on va el joc
        presentacio(g);
        mostrar(&c, &g);
        finalitza(&c, &g);
    }while ((finalitza));



    return 0;
}
