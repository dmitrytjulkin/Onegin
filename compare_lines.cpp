#include <stdio.h>
#include <ctype.h>

int strcmp_function (char* str1, char* str2);
int inverted_strcmp (char* str1, int end1, char* str2, int end2);

int main () {
    char str1[] = "abcde";
    char str2[] = "ab";
    printf ("%d\n", strcmp_function(str1, str2));
}

int strcmp_function (char* str1, char* str2)
{
    int elem1 = 0, elem2 = 0;
    int endOfLine1 = 0, endOfLine2;

    while (!isalpha (str1[elem1]))
        ++elem1;

    while (!isalpha (str2[elem2]))
        ++elem2;

    for ( ; ; elem1++, elem2++) {
        if (str1[elem1] == '\n' || str1[elem2] == '\0')
            endOfLine1 = 1;

        if (str2[elem1] == '\n' || str2[elem2] == '\0')
            endOfLine2 = 2;

        if (endOfLine1 + endOfLine2 > 0)
            break;

        if (str1[elem1] != str2[elem2])
            return str1[elem1] - str2[elem2];
    }

    switch (endOfLine1 + endOfLine2) {
        case 3: return 0;
        case 2: return 1;
        case 1: return -1;
        default: return 0;
    }
}

int inverted_strcmp (char* str1, int end1, char* str2, int end2)
{
    int elem1 = end1, elem2 = end2;

    while (!isalpha ());
}
