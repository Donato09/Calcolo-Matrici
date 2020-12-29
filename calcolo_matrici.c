#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "calcolo_matrici.h"
#include "funzioni_generiche.h"

/**
 * Funzione che calcola il deterimanate di matrici quadrate con numero di righe e colonne > 0
 */
void CalcolaDeterminante( matrice *matrice_A ) {

	int determinante = 0;
	printf("\n************* DETERMINANTE DI UNA MATRICE *************\n");

	//prendo in input il numero di righe e colonne della matrice
	//che deve essere quadrata
	do {

		Input_n_col_rig( matrice_A, "A" );

		if( matrice_A->n_colonne != matrice_A->n_righe ) {
			printf("\nPer carcolare il determinante la matrice deve essere quadrata. \n");
		}

	} while( matrice_A->n_colonne != matrice_A->n_righe );

	InputDatiMatrice( matrice_A, "A" );

	determinante = Determinante( matrice_A->a, matrice_A->n_righe );

	StampaMatrice( matrice_A, "A" ); //stamp della matrice presa in input

	printf("\nIl determinante della matrice e' %d \n", determinante);

	system("pause");
}

/**
 * Funzione che prende in input il numero di righe e di colonne della matrice da inserire
 */
void Input_n_col_rig( matrice *matrice_A, char *a ) {

	int n_righe = 0;
	int n_colonne = 0;

	do {

		printf("\nInserisci numero di righe della matrice %s --> ", a);

		if( scanf( "%d", &n_righe ) != 1) { /* verifico il corretto inserimento dell'utente e lo assegno alla variabile */

			PulisciInputBuffer();

			printf( "\n Inserisci un valore corretto.\n" );

		}

	} while ((n_righe > N_MAX_RIGHE) || (n_righe < 1));

	do {

		printf("\nInserisci numero di colonne della matrice %s --> ", a);

		if( scanf( "%d", &n_colonne ) != 1) { /* verifico il corretto inserimento dell'utente e lo assegno alla variabile */

			PulisciInputBuffer();

			printf( "\n Inserisci un valore corretto.\n" );

		}

	} while ((n_colonne > M_MAX_COLONNE) || (n_colonne < 1));

	matrice_A->n_righe = n_righe;
	matrice_A->n_colonne = n_colonne;
}

/**
 * Funzione che prende in input i dati della matrice
 */
void InputDatiMatrice( matrice *matrice_A, char *a ) {

	int i,j;

	printf( "\nInserimento dati nella matrice %s \n", a );

	for ( i=0; i < matrice_A->n_righe; i++ )

		for( j=0; j < matrice_A->n_colonne; j++ ) {

			printf("Inserisci elemento di riga %d e colonna %d: ", i, j);

			while ( scanf("%d", &matrice_A->a[i][j] ) != 1 ) { /* verifico il corretto inserimento dell'utente e lo assegno alla variabile */

				PulisciInputBuffer();

				printf( "\nInserisci un valore corretto.\n" );

				printf("Inserisci elemento di riga %d e colonna %d: ", i, j);
			}
	    }
}

/**
 * Funzione di stampa di una matrice passata come parametro
 */
void StampaMatrice( matrice *matrice_A, char *a ) {

	int i,j;

	printf( "\nStampiamo i dati della matrice %s \n", a );

	for ( i=0; i < matrice_A->n_righe; i++) {

	    printf("\n");

	    for( j=0; j < matrice_A->n_colonne; j++ )

	        printf( "\t%d", matrice_A->a[i][j] );

	    }

	printf("\n");
}

/**
 * Funzione che calcola il determinante e restituisce un intero
 */
int Determinante( int a[N_MAX_RIGHE][M_MAX_COLONNE], int car ) {

    int determinante = 0;

    //Cardinalità uno
    if (car == 1) determinante = a[0][0];
    //Cardinalità due
    if (car == 2)
        determinante = a[1][1] * a[0][0] - a[0][1] * a[1][0];
    //Cardinalità > 2
    else {

        for (int riga = 0; riga < car; riga++) {

            int sotto_matrice[N_MAX_RIGHE][M_MAX_COLONNE];

            //Sottomatrice di ordine car-1
            for (int i = 0; i < car-1; i++) {

                for (int j = 0; j < car-1; j++) {

                    int sotto_riga = (i < riga ? i : i+1);
                    int sotto_col = j+1;
                    sotto_matrice[i][j] = a[sotto_riga][sotto_col];

                }
            }
            //Segno sottomatrice + per pari, - per dispari
            if (riga % 2 == 0)

             determinante += a[riga][0] * Determinante(sotto_matrice, car-1);

            else

             determinante -= a[riga][0] * Determinante(sotto_matrice, car-1);
        }
    }

    return determinante;
}

/**
 * Funzione che calcola la somma tra due matrici
 */
void CalcolaSomma( matrice *matrice_A, matrice *matrice_B ) {

	matrice matrice_A_B;

	printf("\n************* SOMMA DI DUE MATRICI *************\n");

	do {
		//prendo in input il numero di righe e colonne della matrice A
		Input_n_col_rig( matrice_A, "A" );

		//prendo in input il numero di righe e colonne della matrice B
		Input_n_col_rig( matrice_B, "B" );

		if( matrice_A->n_colonne != matrice_B->n_colonne && matrice_A->n_righe != matrice_B->n_righe ) {
			printf("\nIl numero di righe e di colonne delle matrici A e B deve coincidere. \n");
		}

	} while (matrice_A->n_colonne != matrice_B->n_colonne || matrice_A->n_righe != matrice_B->n_righe);

	matrice_A_B.n_righe = matrice_A->n_righe;
	matrice_A_B.n_colonne = matrice_A->n_colonne;

	InputDatiMatrice( matrice_A, "A" );

	InputDatiMatrice( matrice_B, "B" );

	Somma( matrice_A, matrice_B, &matrice_A_B );

	StampaMatrice( matrice_A, "A" );

	StampaMatrice( matrice_B, "B" );

	StampaMatrice( &matrice_A_B, "A + B" );

	system("pause");
}

/**
 * Funzione che effettua il ciclo di calcoli e restituisce la matrice somma A+B
 */
void Somma( matrice *matrice_A, matrice *matrice_B, matrice *matrice_A_B ) {

	for (int i = 0; i < matrice_A->n_righe; i++) {

		for (int j = 0; j < matrice_A->n_colonne; j++) {

			matrice_A_B->a[i][j] = matrice_A->a[i][j] + matrice_B->a[i][j];

		}
	}

}

/**
 * Funzione che calcola il prodotto tra matrici
 */
void CalcolaProdotto( matrice *matrice_A, matrice *matrice_B ) {

	matrice matrice_A_B;

	printf("\n************* PRODOTTO DI DUE MATRICI *************\n");

	do {
		//prendo in input il numero di righe e colonne della matrice A
		Input_n_col_rig( matrice_A, "A" );

		//prendo in input il numero di righe e colonne della matrice B
		Input_n_col_rig( matrice_B, "B" );

		if( matrice_A->n_colonne != matrice_B->n_righe ) {
			printf("\nIl numero di colonne di A è diverso dal numero di righe di B. \n");
		}

	} while  (matrice_A->n_colonne != matrice_B->n_righe );

	matrice_A_B.n_righe = matrice_A->n_righe;
	matrice_A_B.n_colonne = matrice_B->n_colonne;

	InputDatiMatrice( matrice_A, "A" );

	InputDatiMatrice( matrice_B, "B" );

	Prodotto( matrice_A, matrice_B, &matrice_A_B);

	StampaMatrice( matrice_A, "A" );

	StampaMatrice( matrice_B, "B" );

	StampaMatrice( &matrice_A_B, "A + B" );

	system("pause");
}

/**
 * Funzione che calcola il prodotto tra matrici e restituisce la matrice A*B
 */
void Prodotto( matrice *matrice_A, matrice *matrice_B, matrice *matrice_A_B ) {

	 for ( int i=0; i < matrice_A->n_righe; i++ ) {

		 for (int j=0; j < matrice_B->n_colonne; j++ ) {

	            matrice_A_B->a[i][j] = 0;

	            for (int k=0; k < matrice_A->n_colonne; k++ )
	            	matrice_A_B->a[i][j] = matrice_A_B->a[i][j] + matrice_A->a[i][k] * matrice_B->a[k][j];
	    }
	 }
}
