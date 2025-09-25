#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>

#include "onegin.h"

void fill_arrptr (char* bufptr, char*** arrptr, int* nLines, int* size);
void bubble_sort_arrptr (char** arrptr, int nLines,
                         int (*strcompare) (char* str1, char* str2));
void swap_function (char** p1, char** p2);

// TODO \n\n or {35} \n

int main ()
{
    printf (MAG "START\n.....\n" CRESET);

    char* bufptr = 0;

    read_text (&bufptr);
    printf (GRN "passed reading\n.....\n" CRESET);

    int nLines = 0;
    int size = 5;
    char** arrptr = (char**) calloc (size, sizeof (char*));

    fill_arrptr (bufptr, &arrptr, &nLines, &size); // ADD &arrptr
    printf (GRN "passed filling arrptr\n.....\n" CRESET);

    bubble_sort_arrptr (arrptr, nLines, strcmp_function);
    printf (GRN "passed sorting\n.....\n" CRESET);

    print_text (arrptr);
    printf (GRN "passed printing\n.....\n" CRESET);

    bubble_sort_arrptr (arrptr, nLines, inverted_strcmp);
    printf (GRN "passed sorting\n.....\n" CRESET);

    print_text (arrptr);
    printf (GRN "passed printing\n.....\n" CRESET);

    free (bufptr);

    printf (MAG "COMMIT GITHUB!\n" CRESET);

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

        if (*nLines == *size - 1) {
            *size *= 2;

            if ((*arrptr = (char**) realloc (*arrptr, (*size + 1) * sizeof (char*))) == NULL)
                assert (0); // !
        }

        ++elem;
    }

    *(*arrptr + *nLines) = bufptr + elem + 1; // for '\0' // !!! "+ 1"

    // printf ("arrptr[0] = %p\n", *(*arrptr));
    // printf ("arrptr[1] = %p\n", *(*arrptr + 1));
    // printf ("arrptr[6] = %p\n", *(*arrptr + 6));
    // printf ("nLines = %d\n", *nLines);
}

void bubble_sort_arrptr (char** arrptr, int nLines,
                         int (*strcompare) (char* str1, char* str2))
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

            // printf (YEL "COMPARE\n" CRESET);
            // printf (CYN "comparison between %d and %d:\n" CRESET, elem - 1, elem);
            // print_line (*(arrptr + elem - 1), stdout);
            // print_line (*(arrptr + elem), stdout);
            // printf ("\n\n");

            int resultOfCmp = 0;

            // printf ("the end of str1: %c%c", *(*(arrptr + elem) - 2), *(*(arrptr + elem) - 1));
            // printf ("the end of str2: %c%c", *(*(arrptr + elem + 1) - 2), *(*(arrptr + elem + 1) - 1));

            if ((resultOfCmp = strcompare (*(arrptr + elem - 1), *(arrptr + elem))) > 0) { // not working for moved strings
                // printf (YELBG "SWAP" CRESET "\n");
                // print_line (*(arrptr + elem - 1), stdout);
                // print_line (*(arrptr + elem), stdout);
                // printf ("\n\n");

                check = 0;

                swap_function ((arrptr + elem - 1), (arrptr + elem)); // maybe doesn't work if no \n in the end
            }

            // printf ("result of compare: %d\n", resultOfCmp);
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
