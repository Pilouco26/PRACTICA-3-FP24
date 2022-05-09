#include <stdbool.h>


typedef struct
{
    FILE *fit;
}   fit_t;

/**
 * @brief Carrega dades
 * @param c (E)
 */
void carregar_dades();

/**
 * @brief Carrega dades
 * @param c (E)
 * @return true
 * @return false
 */
bool llegir_fitxer();
/**
 * @brief Acaba el joc
 *
 * @param
 */
void finalitza();
/**
 * @brief Verifica la jugada
 * @param c (E)
 * @return true Encerta
 * @return false Puzolana
 */
bool correcte();
/**
 * @brief Ensenya el tauler  del picross
 *
 * @param (E) El tauler
 */
void mostrar();
/**
 * @brief Carrega dades
 * @param c (E)
 * @return true Si l'usuari ha introduit dades valides
 * @return false Al revès
 */
bool verificar_dades();

bool obrir_fitxer();
