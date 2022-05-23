#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX_EL 10

/**
 * @brief Carrega dades
 * @param c (E)
 */
void carregar_dades();
/**
 * @brief Acaba el joc
 *
 * @param
 */
void iniciar_taula_respostes();
/**
 * @brief Verifica la jugada
 * @param c (E)
 * @return true Encerta
 * @return false Puzolana
 */
 void iniciar_taula_adalt();
 /**
 * @brief Verifica la jugada
 * @param c (E)
 * @return true Encerta
 * @return false Puzolana
 */
 void imprimir_taula_respostes();
/**
 * @brief Ensenya el tauler  del picross
 *
 * @param (E) El tauler
 */
void pregunta_posicio();
/**
 * @brief Carrega dades
 * @param c (E)
 * @return true Si l'usuari ha introduit dades valides
 * @return false Al revès
 */
bool posicio_omplerta();
/**
 * @brief Carrega dades
 * @param c (E)
 * @return true Si l'usuari ha introduit dades valides
 * @return false Al revès
 */
void pregunta_resposta();
/**
 * @brief Carrega dades
 * @param c (E)
 * @return true Si l'usuari ha introduit dades valides
 * @return false Al revès
 */
bool resposta_ok();
