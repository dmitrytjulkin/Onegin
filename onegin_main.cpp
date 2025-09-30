#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>

#include "onegin.h"

void fill_arrptr (char* buf_ptr, char** arrptr, int* nLines);
void bubble_sort_arrptr (char** arrptr, int nLines,
                         int (*strcompare) (char* str1, char* str2));
void swap_function (char** p1, char** p2);

int main ()
{
    printf (MAG "START\n.....\n" CRESET);

    clean_output ();

    char* buf_ptr = 0;
    size_t buf_size = 0;

    read_text (&buf_ptr, &buf_size);
    printf (GRN "passed reading\n.....\n" CRESET);

    int nLines = 0;
    char** arrptr = (char**) calloc (buf_size, sizeof (char*));

    fill_arrptr (buf_ptr, arrptr, &nLines);
    printf (GRN "passed filling arrptr\n.....\n" CRESET);

    bubble_sort_arrptr (arrptr, nLines, strcmp_function);
    printf (GRN "passed straight sorting\n.....\n" CRESET);

    print_text (arrptr);
    printf (GRN "passed printing straight sorting\n.....\n" CRESET);

    bubble_sort_arrptr (arrptr, nLines, inverted_strcmp);
    printf (GRN "passed invert sorting\n.....\n" CRESET);

    print_text (arrptr);
    printf (GRN "passed printing invert sorting\n.....\n" CRESET);

    FILE* poem_out = fopen ("onegin_output.txt", "a");
    assert (poem_out != NULL);

    fprintf (poem_out, "\n____________________________________________________________________\n");
    fprintf (poem_out, "%s\n", buf_ptr);
    printf (GRN "passed printing original text\n.....\n" CRESET);

    fclose (poem_out);

    free (arrptr);
    free (buf_ptr);

    printf (MAG "COMMIT GITHUB!\n" CRESET);

    return 0;
}

void fill_arrptr (char* buf_ptr, char** arrptr, int* nLines)
{
    assert (buf_ptr != NULL);
    assert (arrptr != NULL);
    assert (nLines != NULL);

    int elem = 0;
    *nLines = 1;

    *arrptr = buf_ptr;

    while (*(buf_ptr + elem) != '\0') {
        if (*(buf_ptr + elem) == '\n') {
            *(arrptr + *nLines) = buf_ptr + elem + 1;
            ++(*nLines);
        }

        ++elem;
    }

    *(arrptr + *nLines) = buf_ptr + elem + 1;
}

void bubble_sort_arrptr (char** arrptr, int nLines,
                         int (*strcompare) (char* str1, char* str2))
{
    assert (arrptr != 0);
    assert (strcompare != 0);

    int check = 0;

    while (!check) {
        int elem = 1;
        check = 1;

        while (elem < nLines - 1) {
            // printf (YEL "COMPARE\n" CRESET);
            // printf (CYN "comparison between %d and %d:\n" CRESET, elem - 1, elem);
            // print_line (*(arrptr + elem - 1), stdout);
            // print_line (*(arrptr + elem), stdout);
            // printf ("\n\n");

            if (strcompare (*(arrptr + elem - 1), *(arrptr + elem)) > 0) {
                // printf (YELBG "SWAP" CRESET "\n");
                // print_line (*(arrptr + elem - 1), stdout);
                // print_line (*(arrptr + elem), stdout);
                // printf ("\n\n");

                check = 0;

                swap_function ((arrptr + elem - 1), (arrptr + elem)); // maybe doesn't work if no \n in the end
            }

            ++elem;
        }
    }
}

void swap_function (char** p1, char** p2)
{
    assert (p1 != NULL);
    assert (p2 != NULL);

    char* temp = *p2;
    *p2 = *p1;
    *p1 = temp;
}
