#include <stdio.h>

#define N_MAX_RIGHE 100 //numero massimo di righe di una matrice
#define M_MAX_COLONNE 100 //numero massimo di colonne di una matrice

typedef struct {
	unsigned int n_righe; //!< n_righe della matrice inserito dall'utente
	unsigned int n_colonne; //!< n_colonne della matrice inserito dall'utente
	int a[N_MAX_RIGHE][M_MAX_COLONNE]; //!< matrice di interi utilizzata per le operazioni
} matrice;

/**
 * Funzione che calcola il deterimanate di matrici quadrate con numero di righe e colonne > 0
 */
void CalcolaDeterminante( matrice *matrice_A);

/**
 * Funzione che prende in input il numero di righe e di colonne della matrice da inserire
 */
void Input_n_col_rig(matrice *matrice_A, char *a);

/**
 * Funzione che prende in input i dati della matrice
 */
void InputDatiMatrice( matrice *matrice_A, char *a );

/**
 * Funzione che stampa una matrice
 */
void StampaMatrice( matrice *matrice_A, char *a );

/**
 * Funzione che calcola il determinante e restituisce un intero
 */
int Determinante( int a[N_MAX_RIGHE][M_MAX_COLONNE], int car );

/**
 * Funzione che calcola la somma tra due matrici
 */
void CalcolaSomma( matrice *matrice_A, matrice *matrice_B );

/**
 * Funzione che effettua il ciclo di calcoli e restituisce la matrice somma A+B
 */
void Somma( matrice *matrice_A, matrice *matrice_B, matrice *matrice_A_B );

/**
 * Funzione che calcola il prodotto tra matrici
 */
void CalcolaProdotto( matrice *matrice_A, matrice *matrice_B );

/**
 * Funzione che calcola il prodotto tra matrici e restituisce la matrice A*B
 */
void Prodotto( matrice *matrice_A, matrice *matrice_B, matrice *matrice_A_B );
