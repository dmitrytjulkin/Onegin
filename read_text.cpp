#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "onegin.h"

void read_text (char** ptr, int* count)
{
    FILE* poem = fopen("onegin_poem.txt","r");
    size_t size = 5 * sizeof (char), step = 0;
    *ptr = (char*) calloc (size + 1, sizeof (char));

    *count = 0;

    while (true) {
        size_t goOut = fread(*ptr + step, sizeof (char), size, poem);

        // printf ("ptr + step:%s\n", ptr + step);
        // printf ("goOut = %zu, step = %zu, size = %zu", goOut, step, size);

        if (goOut == 0)
            break;

        *count += goOut;
        step += size;
        size *= 3;

        *ptr = (char*) realloc (*ptr, step + size + 1);
    }
}
