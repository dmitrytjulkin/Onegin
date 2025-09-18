#include <stdio.h>

#include "onegin.h"

int print_line (char* ptr, FILE* stream);

void print_text (char* ptr, int nLines)
{
    FILE* poemOut = fopen ("onegin_output.txt", "w");
    int step = 0;
    // fputs (ptr, poemOut);
    do {
        step += print_line (ptr + step, poemOut);
    } while (*(ptr + step) != '\0');
}

int print_line (char* ptr, FILE* stream)
{
    int elem = 0;
    // printf ("CHECK\n");

    while (*(ptr + elem) != '\n' && *(ptr + elem) != '\0') {
        fputc (*(ptr + elem), stream);
        ++elem;
    }

    fputc ('\n', stream);
    // printf ("elem = %d\n", elem);
    return elem + 1;
}
