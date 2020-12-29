#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "gestione_menu.h"

/**
 * Funzione che stampa a video il menu principale e termina solo nel
 * caso in cui l'utente compie una selezione corretta
 * @return intero che indica la selezione effettuata dall'utente
 */
int OpzioneSelezionata() {

	int voce_menu_selezionata; //variabile che memorizza la scelta dell'utente
	int flag = 1;

	system("cls");

	while ( flag == 1 ) {

		printf("\n************* MENU PRINCIPALE *************\n");

		//visualizzo opzioni disponibili
		printf( "\n Selezionare un operazione\n"
				" 1 - Inserisci e calcola determinante di una matrice\n"
				" 2 - Inserisci e calcola somma tra 2 matrici\n"
				" 3 - Inserisci e calcola prodotto tra 2 matrici\n"
				" 99 - Termina esecuzione del programma\n" );

		printf(" --> ");

		if( scanf( "%d", &voce_menu_selezionata ) == 1) { /* riceve la scelta da parte dell'utente */
			flag = 0;
		} else {

			PulisciInputBuffer();
			printf( "\n Selezionare un operazione corretta.\n" );
		}
	}

	return voce_menu_selezionata;
}


/**
 * Funzione che in base alla selezione dell'utente visualizza il sottomenu corrispondente
 * @param matrice_A puntatore a struttura delle matrici
 * @param matrice_B puntatore a struttura delle matrici
 */
void GestioneMenuPrincipale( matrice *matrice_A, matrice *matrice_B ) {

	int selezione;

	while ( ( selezione = OpzioneSelezionata() ) != CHIUDI_MENU ) {

		switch ( selezione ) {
		case 1:		//calcola determinante di una matrice
				CalcolaDeterminante( matrice_A );
			break;
		case 2: 	//calcola somma tra due matrici
				CalcolaSomma( matrice_A, matrice_B );
			break;
		case 3: //calcola il prodotto tra due matrici
				CalcolaProdotto( matrice_A, matrice_B );
			break;
		default:

			printf( " Selezione errata!\n" );
			break;
		}
	}
}
