#include <stdbool.h>
#define MAX_EL 10


typedef struct
{
    FILE *fit;
    int max_errors, max_f;
    int max_c;
    int *taula[MAX_EL][MAX_EL];
}   fit_t;

typedef struct
{
    int *taula_j[MAX_EL][MAX_EL];
    int errors;
    int encerts;
    int n_acabar;
    char nom[10];
} joc_t;
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
bool finalitza();
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
void inicialitzar();
int max_columnes ();
int max_files ();
