#include <stdio.h>
#include <assert.h>

#include "onegin.h"

void print_text (char** arrptr)
{
    assert (arrptr != NULL);

    FILE* poem_out = fopen ("onegin_output.txt", "a");

    fputs ("\n____________________________________________________________________\n", poem_out);

    int step = 0;

    do {
        print_line (*(arrptr + step), poem_out);

        step++;

    } while (**(arrptr + step) != '\0');
}

int print_line (char* ptr, FILE* stream)
{
    assert (ptr != NULL);
    assert (stream != NULL);

    int elem = 0;

    while (*(ptr + elem) != '\n' && *(ptr + elem) != '\0') {
        fputc (*(ptr + elem), stream);

        ++elem;
    }

    fputc ('\n', stream);

    return elem + 1;
}

void clean_output ()
{
    FILE* poem_out = fopen ("onegin_output.txt", "w+");

    fclose (poem_out);
}
