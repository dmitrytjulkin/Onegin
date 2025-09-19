#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>

#include "onegin.h"
// stats, fstats?
void read_text (char** ptr, int* nSymbols)
{
    assert (ptr != NULL);
    assert (nSymbols != NULL);

    FILE* poem = fopen("onegin_input.txt","r");

    size_t size = 5 * sizeof (char);
    size_t step = 0;
    *ptr = (char*) calloc (size + 1, sizeof (char));

    *nSymbols = 0;

    while (true) {
        size_t goOut = fread(*ptr + step, sizeof (char), size, poem);

        // printf ("ptr + step:%s\n", ptr + step);
        // printf ("goOut = %zu, step = %zu, size = %zu", goOut, step, size);

        if (goOut == 0)
            break;

        *nSymbols += goOut;
        step += size;
        size *= 3;

        *ptr = (char*) realloc (*ptr, step + size + 1);
    }

    fclose (poem);
}
