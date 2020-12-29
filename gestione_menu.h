#include "calcolo_matrici.h"


/**
 * Constante simbolica: definisce il numero per uscire dal programma oppure tornare al menu precedente
 */
#define CHIUDI_MENU 99

/**
 * Funzione che visualizza il menu principale con
 * le possibili operazioni che l'utente può effettuare
 * @return restituisce un intero che indica la selezione dell'utente
 */
int OpzioneSelezionata();

/**
 * Funzione che in base alla selezione dell'utente visualizza il sottomenu corrispondente
 * @param info_preferenze puntatore a struttura delle preferenze
 * @param info_brani puntatore a struttura dei brani
 * @param info_utenti puntatore a struttura degli utenti
 */
void GestioneMenuPrincipale( matrice *matrice_A, matrice *matrice_B );
