#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "onegin.h"

int main()
{
    printf ("START\n");
    char* ptr = 0;
    int nSymbols = 0;
    read_text (&ptr, &nSymbols);

    // printf ("%s\n", ptr);

    int elem = 0;
    int nLines = 1;
    size_t size = 10 * sizeof (char);
    char** arrptr = (char**) calloc (size, sizeof (char));
    *arrptr = ptr; //!

    while (*(ptr + elem) != '\0') {
        if (*(ptr + elem) == '\n') {
            *(arrptr + nLines - 1) = ptr + elem;
            ++nLines;
        }

        if (nLines == size - 1) {
            size *= 2;
            arrptr = (char**) realloc (arrptr, size + 1);
        }

        ++elem;
    }

    char* term = arrptr[1];
    arrptr[1] = arrptr[0];
    arrptr[0] = term;

    print_text (ptr, 2);

    free (ptr);

    printf ("COMMIT GITHUB!\n");
}
