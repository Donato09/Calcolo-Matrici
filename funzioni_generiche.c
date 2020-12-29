#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "funzioni_generiche.h"

/**
 * Funzione che ripulisce il buffer dai caratteri in eccesso/superflui
 * puo' essere utilizzata ad esempio per pulire il buffer di input
 */
void PulisciInputBuffer()
{
    char c;

    while ( ( c = getchar() ) != '\n' && c != EOF );
}
