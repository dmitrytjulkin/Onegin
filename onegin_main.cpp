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
    size_t size = 5 * sizeof (char*);
    char** arrptr = (char**) calloc (size, 1);
    *arrptr = ptr;

    while (*(ptr + elem) != '\0') {
        if (*(ptr + elem) == '\n') {
            // printf ("nLines = %d\n", nLines + 1);
            *(arrptr + nLines) = ptr + elem + 1;
            // printf ("str:\n%s", *(arrptr + nLines));
            ++nLines;
        }
        printf ("nlines = %d, size - 1 = %zu\n", nLines, size - 1);
        if (nLines == size - 1) {
            printf ("\n\nnLines %d >= size %zu - 1,\narrptr[4] = \n%s\n\n",
                    nLines, size, *(arrptr + 4));
            size *= 2;
            if ((arrptr = (char**) realloc (arrptr, size + 1)) == NULL)
                printf ("\nEvo kak\n");
        } else
            printf ("\nEvo kak\n");


        ++elem;
    }

    // char* term = arrptr[1];
    // arrptr[1] = arrptr[0];
    // arrptr[0] = term;

    // printf ("2 line 1 elem = %d\n", (int) **(arrptr + 1));

    // printf ("*arrptr0 = %s\n", *arrptr);
    // printf ("*arrptr1 = %s\n", *(arrptr + 1));

    // printf ("str:\n%s\n", *arrptr);

    for (int i = 0; i < nLines; ++i) {
        printf ("line %d:\n%s", i, *(arrptr + i));
    }

    print_text (arrptr);

    free (ptr);

    printf ("COMMIT GITHUB!\n");
}
