/**
* @file main.c
* @brief Programma che calcola il determinante di una matrice, somma e prodotto tra matrici.
*
* Il sistema si occupa di calcolare determinante, somma e prodotto di matrici.
* Tramite un menu principale l'amministratore puo':
* 	- calcolare il determinante di una matrice
* 	- calcolare la somma tra due matrici
* 	- calcolare il prodotto tra due matrici
*
*
* @version 1.0
* @date 22/10/2020
* @authors Donato Micele
*
* @copyright GNU Public License.
*/
#include <stdio.h>
#include <stdlib.h>
#include "gestione_menu.h"

int main( void ) {

	matrice matrice_A;
	matrice matrice_B;

	matrice_A.n_colonne = 0;
	matrice_A.n_righe = 0;

	matrice_B.n_colonne = 0;
	matrice_B.n_righe = 0;

	GestioneMenuPrincipale( &matrice_A, &matrice_B);

	return EXIT_SUCCESS;
}
