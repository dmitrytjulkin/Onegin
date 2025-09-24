#include <stdio.h>
#include <ctype.h>

#include "onegin.h"
//
// int strcmp_function (char* str1, char* end1, char* str2, char* end2);
// int inverted_strcmp (char* str1, char* end1, char* str2, char* end2);

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

int strcmp_function (char* str1, char* end1, char* str2, char* end2)
{
    int elem1 = 0, elem2 = 0;
    int endOfLine1 = 0, endOfLine2 = 0;

    while (!isalpha (str1[elem1]))
        ++elem1;

    while (!isalpha (str2[elem2]))
        ++elem2;

    for ( ; ; elem1++, elem2++) {
        if (str1[elem1] == *end1)
            endOfLine1 = 1;

        if (str2[elem2] == *end2)
            endOfLine2 = 2;

        if (endOfLine1 + endOfLine2 > 0)
            break;

        if (tolower (str1[elem1]) != tolower (str2[elem2])) {
            // printf ("str1[] = %c (%d) and str2[] = %c (%d)\n",
            // tolower (str1[elem1]), tolower (str1[elem1]), tolower (str2[elem2]), tolower (str2[elem2]));
            // printf ("diffference %d\n", (int) str1[elem1] - (int) str2[elem2]);
            return tolower (str1[elem1]) - tolower (str2[elem2]);
        }
    }
//
//     printf ("str1[] = %c (%d) and str2[] = %c (%d)\n", str1[elem1], str1[elem1], str1[elem2], str1[elem2]);
//     printf ("diffference %d\n", str1[elem1] - str2[elem2]);

    return choose_who_is_bigger (endOfLine1, endOfLine2);
}

int inverted_strcmp (char* str1, char* end1, char* str2, char* end2)
{
    char* elem1 = end1, * elem2 = end2;
    int endOfLine1 = 0, endOfLine2 = 0;

    while (!isalpha (*elem1))
        --elem1;

    while (!isalpha (*elem2))
        --elem2;

    for ( ; ; elem1--, elem2--) {
        if (tolower (*elem1) != tolower (*elem2))
            return tolower (*elem1) - tolower (*elem2);

        if (*elem1 == str1[0])
            endOfLine1 = 1;

        if (*elem2 == str2[0])
            endOfLine2 = 2;

        if (endOfLine1 + endOfLine2 > 0)
            break;
    }

    int biggerIs = choose_who_is_bigger (endOfLine1, endOfLine2);

    // printf ("str1[] = %c (%d) and str2[] = %c (%d)\n", *elem1, *elem1, *elem2, *elem2);

    return choose_who_is_bigger (endOfLine1, endOfLine2);
}

int choose_who_is_bigger (int endOfLine1, int endOfLine2)
{
    switch (endOfLine1 + endOfLine2) {
        case 3:
            return 0;

        case 2:
            return 1;

        case 1:
            return -1;

        default:
            return 0;
    }
}
