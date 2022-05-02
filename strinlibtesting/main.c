#include <stdio.h>
#include <stdlib.h>
#include "../stringlib/stringlib.h"

int main()
{
    char cadena[] = {"pepe     puto   $$$## poronga "};
    char* cadenaPointer = cadena;

    normalizeString(cadenaPointer);

    printf("%s\n",cadena);

    cadenaPointer=cadena;

    int wordCount = countWords(cadenaPointer);


    printf("%d palabras",wordCount);

    return 0 ;
}
