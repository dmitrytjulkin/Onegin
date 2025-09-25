#include <stdio.h>
#include <ctype.h>

enum theBiggestString {
    firstSmaller = -1,
    firstEqual,
    firstBigger
};

enum whoFinished {
    firstFinished = 1,
    secondFinished,
    bothFinished
};

#include "onegin.h"
//
// int strcmp_function (char* str1, char* str2);
// int inverted_strcmp (char* str1, char* str2);

int choose_who_is_bigger (int endOfLine1, int endOfLine2);
//
// int main () {
//     char str1[] = "  2-/.] abe  \\20 ";
//     char str2[] = "    abcdz \n\\\\00";
//
//     printf ("straight: %d\ninverted: %d\n",
//             strcmp_function(str1, str1 + 18, str2, str2 + 18),
//             inverted_strcmp(str1, str1 + 18, str2, str2 + 18));
// }

int strcmp_function (char* str1, char* str2)
{
    int elem1 = 0, elem2 = 0;
    int endOfLine1 = 0, endOfLine2 = 0;

    while (!isalpha (str1[elem1]))
        ++elem1;

    while (!isalpha (str2[elem2]))
        ++elem2;

    for ( ; ; ++elem1, ++elem2) {
        if (str1[elem1] == '\n')
            endOfLine1 = 1;

        if (str2[elem2] == '\n')
            endOfLine2 = 2;

        if (endOfLine1 + endOfLine2 > 0)
            break;

        if (tolower (str1[elem1]) != tolower (str2[elem2])) {
            // printf ("str1[] = %c (%d) and str2[] = %c (%d)\n",
            //         tolower (str1[elem1]), tolower (str1[elem1]),
            //         tolower (str2[elem2]), tolower (str2[elem2]));
            // printf ("diffference %d\n", tolower (str1[elem1]) - tolower (str2[elem2]));

            return tolower (str1[elem1]) - tolower (str2[elem2]);
        }
    }

    // printf ("str1[] = %c (%d) and str2[] = %c (%d)\n",
    //         tolower (str1[elem1]), tolower (str1[elem1]),
    //         tolower (str2[elem2]), tolower (str2[elem2]));
    // printf ("diffference %d\n", str1[elem1] - str2[elem2]);

    return choose_who_is_bigger (endOfLine1, endOfLine2);
}

int inverted_strcmp (char* str1, char* str2)
{
    int elem1 = 0, elem2 = 0;
    int endOfLine1 = 0, endOfLine2 = 0;

    // printf ("end of str1 before skip: %c (%d)\n", *(elem1 - 1), *(elem1 - 1));
    // printf ("end of str2 before skip: %c (%d)\n", *(elem2 - 1), *(elem2 - 1));

    while (*(str1 + elem1) != '\n' && *(str1 + elem1) != '\0')
        ++elem1;
    while (*(str2 + elem2) != '\n' && *(str2 + elem2) != '\0')
        ++elem2;

    while (!isalpha (*(str1 + elem1)))
        --elem1;

    while (!isalpha (*(str2 + elem2)))
        --elem2;

    for ( ; ; --elem1, --elem2) {
        if (tolower (*(str1 + elem1)) != tolower (*(str2 + elem2))) {
            // printf ("str1[] = %c (%d) and str2[] = %c (%d)\n",
            //         tolower (*(str1 + elem1)), tolower (*(str1 + elem1)),
            //         tolower (*(str2 + elem2)), tolower (*(str2 + elem2)));
            // printf ("diffference %d\n", tolower (*(str1 + elem1)) - tolower (*(str2 + elem2)));

            return tolower (*(str1 + elem1)) - tolower (*(str2 + elem2));
        }

        if (*(str1 + elem1) == str1[0])
            endOfLine1 = 1;

        if (*(str2 + elem2) == str2[0])
            endOfLine2 = 2;

        if (endOfLine1 + endOfLine2 > 0)
            break;
    }

    // printf ("str1[] = %c (%d) and str2[] = %c (%d)\n",
    //         tolower (*(str1 + elem1)), tolower (*(str1 + elem1)),
    //         tolower (*(str2 + elem2)), tolower (*(str2 + elem2)));
    // printf ("diffference %d\n", tolower (*(str1 + elem1)) - tolower (*(str2 + elem2)));

    return choose_who_is_bigger (endOfLine1, endOfLine2);
}

int choose_who_is_bigger (int endOfLine1, int endOfLine2)
{
    switch (endOfLine1 + endOfLine2) {
        case bothFinished:
            return firstEqual;

        case secondFinished:
            return firstBigger;

        case firstFinished:
            return firstSmaller;

        default:
            return firstEqual;
    }
}
