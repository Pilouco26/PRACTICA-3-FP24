#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 100

typedef struct
{
    int taula[MAX][MAX];
    int taula1[MAX][MAX];
    int taula2[MAX][MAX];
    int max_c;
    int max_f;
    int max_errors;
    int n;
    int fila;
    int columna;
    int resposta;
    char taula_respostes[MAX][MAX];

} picross_t;

void carregar_dades(picross_t *p);

void taula_adalt(picross_t *p);

void imprimir_taula_respostes(picross_t *p);

void pregunta_posicio(picross_t *p);

bool posicio_omplerta (picross_t *p);

bool resposta_ok(picross_t *p);

void pregunta_resposta(picross_t *p);

bool finalitza(int encerts, int errors, picross_t p);
