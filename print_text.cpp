#include <stdio.h>
#include <assert.h>

#include "onegin.h"

void print_text (char** arrptr)
{
    assert (arrptr != NULL);

    FILE* poemOut = fopen ("onegin_output.txt", "w");

    int step = 0;

    printf ("arrptr[0] = %p\n", *arrptr);
    printf ("arrptr[6] = %p\n", *(arrptr + 6));

    do {
        // printf ("*arrptr in func = %p\n", arrptr + step);
        // printf ("str:\n%s\n", *(arrptr + step));

        print_line (*(arrptr + step), poemOut);

        step++;
        printf ("STEP = %d\n", step);
        printf ("ptr = %p\n", *(arrptr + step));
        print_line (*(arrptr + step), stdout);

    } while (**(arrptr + step) != '\0');
}

int print_line (char* ptr, FILE* stream)
{
    assert (ptr != NULL);
    assert (stream != NULL);

    int elem = 0;

    while (*(ptr + elem) != '\n' && *(ptr + elem) != '\0') {
        // printf ("ptr + elem = %s\n", (ptr + elem));
        fputc (*(ptr + elem), stream);

        ++elem;
    }

    // printf ("______________\n");

    fputc ('\n', stream);

    // printf ("elem = %d\n", elem);

    return elem + 1;
}
