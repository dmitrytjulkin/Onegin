#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <sys/stat.h>

#include "onegin.h"

// fseek, ftell

void read_text (char** ptr, size_t* buf_size)
{
    assert (ptr != NULL);

    FILE* poem = fopen("onegin_input.txt","r");
    assert (poem != NULL);

    struct stat buf_data = {};

    fstat (fileno(poem), &buf_data);
    *buf_size = buf_data.st_size;

    size_t step = 0;
    *ptr = (char*) calloc (*buf_size + 1, sizeof (char));

    int nSymbols = 0;

    fread(*ptr + step, sizeof (char), *buf_size, poem);

//     while (true) {
//         size_t goOut = fread(*ptr + step, sizeof (char), size, poem);
//
//         if (goOut == 0)
//             break;
//
//         nSymbols += goOut;
//         step += size;
//         size *= 3;
//
//         *ptr = (char*) realloc (*ptr, step + size + 1);
//     }

    fclose (poem);
}
