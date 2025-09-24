#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>

#include "onegin.h"

void fill_arrptr (char* bufptr, char*** arrptr, int* nLines, int* size);
void bubble_sort_arrptr (char** arrptr, int nLines,
                         int (*strcompare) (char* str1, char* end1, char* str2, char* end2));
void swap_function (char** p1, char** p2);

int main ()
{
    printf ("START\n.....\n");

    char* bufptr = 0;

    read_text (&bufptr);

    printf ("passed reading\n.....\n");

    int nLines = 0;
    int size = 5;
    char** arrptr = (char**) calloc (size, sizeof (char*)); // TODO

    fill_arrptr (bufptr, &arrptr, &nLines, &size); // ADD &arrptr

    // printf ("arrptr[0] = %p\n", arrptr[0]);
    // printf ("arrptr[1] = %p\n", arrptr[1]);

    printf ("passed filling arrptr\n.....\n");

    // bubble_sort_arrptr (arrptr, nLines, strcmp_function);
    // printf ("main() -> arrptr = %p\n", arrptr);
    print_text (arrptr);

    printf ("passed printing\n.....\n");

    // bubble_sort_arrptr (arrptr, nLines, inverted_strcmp);
    // print_text (arrptr);

    free (bufptr);

    printf ("COMMIT GITHUB!\n");

    return 0;
}

void fill_arrptr (char* bufptr, char*** arrptr, int* nLines, int* size)
{
    assert (bufptr != NULL);
    assert (arrptr != NULL);
    assert (nLines != NULL);
    assert (size != NULL);

    int elem = 0;
    *nLines = 1;

    **arrptr = bufptr;

    while (*(bufptr + elem) != '\0') {
        if (*(bufptr + elem) == '\n') {
            *(*arrptr + *nLines) = bufptr + elem + 1;
            ++(*nLines);
        }

        if (*nLines == *size - 1) { // TODO
            *size *= 2;

            if ((*arrptr = (char**) realloc (*arrptr, (*size + 1) * sizeof (char*))) == NULL) // TODO
                assert (0); // !
        }

        ++elem;

        if (*nLines > 6)
            printf ("arrptr[6] = %p\n", *(*arrptr + 6));
    }

    *(*arrptr + *nLines) = bufptr + elem + 1; // for '\0' // !!! "+ 1"

    // printf ("arrptr[0] = %p\n", *(*arrptr));
    // printf ("arrptr[1] = %p\n", *(*arrptr + 1));
    // printf ("arrptr[6] = %p\n", *(*arrptr + 6));
    // printf ("nLines = %d\n", *nLines);
}

void bubble_sort_arrptr (char** arrptr, int nLines,
                         int (*strcompare) (char* str1, char* end1, char* str2, char* end2))
{
    assert (arrptr != 0);
    assert (strcompare != 0);

    int check = 0;

    // printf ("arrptr[0] = %p\n\n", *arrptr);
    // printf ("arrptr[1] = %p\n\n", *(arrptr + 1));

    while (!check) {
        int elem = 1;
        check = 1;

        while (elem < nLines - 1) {
            // printf ("elem = %d\n", elem);
            // printf ("arrptr[elem] = %p\n", *(arrptr + elem));
            // print_line (*(arrptr + elem), stdout);
            // printf("char = %d", **(arrptr + elem));
            // printf ("\n\n");

            // printf ("end1 = %d, ", *(*(arrptr + elem) - 1));
            // printf ("end2 = %d\n", *(*(arrptr + elem + 1) - 1));

            printf ("COMPARE\n");
            print_line (*(arrptr + elem - 1), stdout);
            print_line (*(arrptr + elem), stdout);
            printf ("\n\n");

            if (strcompare (*(arrptr + elem - 1), *(arrptr + elem) - 1,
                             *(arrptr + elem), *(arrptr + elem + 1) - 1) > 0) {
                printf ("SWAP\n");
                print_line (*(arrptr + elem - 1), stdout);
                print_line (*(arrptr + elem), stdout);
                printf ("\n\n");

                check = 0;
                // printf ("DA\n");
                swap_function ((arrptr + elem - 1), (arrptr + elem)); // maybe doesn't work if no \n in the end
            }
            // print_line (*(arrptr + elem - 1), stdout);
            // print_line (*(arrptr + elem), stdout);

            ++elem;
        }
    }
}

void swap_function (char** p1, char** p2)
{
    assert (p1 != NULL);
    assert (p2 != NULL);

    char* term = *p2;
    *p2 = *p1;
    *p1 = term;
}
