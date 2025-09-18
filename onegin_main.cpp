#include <stdio.h>
#include <stdlib.h>

#include "onegin.h"

int main()
{
    printf ("START\n");
    char* ptr = 0;
    int count = 0;
    read_text (&ptr, &count);

    printf ("%s\n", ptr);
    free (ptr);
}
