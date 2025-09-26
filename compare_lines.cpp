#include <stdio.h>
#include <ctype.h>
#include <assert.h>

enum theBiggestString {
    first_smaller = -1,
    first_equal,
    first_bigger
};

enum whoFinished {
    nobody_finished,
    first_finished,
    second_finished,
    both_finished
};

#include "onegin.h"

int choose_who_is_bigger (int end_of_line1, int end_of_line2);

int strcmp_function (char* str1, char* str2)
{
    assert (str1 != NULL);
    assert (str2 != NULL);

    int elem1 = 0, elem2 = 0;
    int end_of_line1 = 0, end_of_line2 = 0;

    while (!isalpha (str1[elem1]) && str1[elem1] != '\n')
        ++elem1;

    while (!isalpha (str2[elem2]) && str2[elem2] != '\n') {
        ++elem2;
    }

    for ( ; ; ++elem1, ++elem2) {
        if (str1[elem1] == '\n')
            end_of_line1 = first_finished;

        if (str2[elem2] == '\n')
            end_of_line2 = second_finished;

        if (end_of_line1 + end_of_line2 > nobody_finished)
            break;

        if (tolower (str1[elem1]) != tolower (str2[elem2])) {
            // printf ("str1[] = %c (%d) and str2[] = %c (%d)\n",
            //         tolower (str1[elem1]), tolower (str1[elem1]),
            //         tolower (str2[elem2]), tolower (str2[elem2]));
            // printf ("diffference %d\n", tolower (str1[elem1]) - tolower (str2[elem2]));

            return tolower (str1[elem1]) - tolower (str2[elem2]);
        }
    }
//
//     printf ("str1[] = %c (%d) and str2[] = %c (%d)\n",
//             tolower (str1[elem1]), tolower (str1[elem1]),
//             tolower (str2[elem2]), tolower (str2[elem2]));
//     printf ("diffference %d\n", tolower (str1[elem1]) - tolower (str2[elem2]));

    return choose_who_is_bigger (end_of_line1, end_of_line2);
}

int inverted_strcmp (char* str1, char* str2)
{
    assert (str1 != NULL);
    assert (str2 != NULL);

    int elem1 = 0, elem2 = 0;
    int end_of_line1 = 0, end_of_line2 = 0;

    while (*(str1 + elem1) != '\n' && *(str1 + elem1) != '\0')
        ++elem1;

    while (*(str2 + elem2) != '\n' && *(str2 + elem2) != '\0')
        ++elem2;

    while (!isalpha (*(str1 + elem1)))
        --elem1;

    while (!isalpha (*(str2 + elem2)))
        --elem2;

    for ( ; ; --elem1, --elem2) {
        if (tolower (*(str1 + elem1)) != tolower (*(str2 + elem2)))
            return tolower (*(str1 + elem1)) - tolower (*(str2 + elem2));

        if (*(str1 + elem1) == str1[0])
            end_of_line1 = 1;

        if (*(str2 + elem2) == str2[0])
            end_of_line2 = 2;

        if (end_of_line1 + end_of_line2 > 0)
            break;
    }

    return choose_who_is_bigger (end_of_line1, end_of_line2);
}

int choose_who_is_bigger (int end_of_line1, int end_of_line2)
{
    switch (end_of_line1 + end_of_line2) {
        case both_finished:
            return first_equal;

        case second_finished:
            return first_bigger;

        case first_finished:
            return first_smaller;

        default:
            return first_equal;
    }
}
