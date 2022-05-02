#include <stdio.h>
#include <stdlib.h>
#include "../vectorlib/vector.h"

#define CAPACIDAD_MAXIMA 5

int main()
{
    Vector vector1;

    crearVector(&vector1);

    if (insertarEnVectorAlFinal(&vector1, 12))
    {
        printf("se inserto el valor 12\n");
    }
    else
    {
        printf("no se pudo insertar el valor 12\n");
    }
    if (insertarEnVectorAlFinal(&vector1, 34))
    {
        printf("se inserto el valor 34\n");
    }
    else
    {
        printf("no se pudo insertar el valor 34\n");
    }

    if (insertarEnVectorAlFinal(&vector1, 56))
    {
        printf("se inserto el valor 56\n");
    }
    else
    {
        printf("no se pudo insertar el valor 56\n");
    }

    if (insertarEnVectorAlFinal(&vector1, 78))
    {
        printf("se inserto el valor 78\n");
    }
    else
    {
        printf("no se pudo insertar el valor 78\n");
    }

    if (insertarEnVectorAlFinal(&vector1, 91))
    {
        printf("se inserto el valor 91\n");
    }
    else
    {
        printf("no se pudo insertar el valor 91\n");
    }

    if (insertarEnVectorAlFinal(&vector1, 12))
    {
        printf("se inserto el valor 12\n");
    }
    else
    {
        printf("no se pudo insertar el valor 12\n");
    }

    mostrarVector(&vector1);

    eliminarDeVectorOrdenadoPorValor(&vector1, 12);
    mostrarVector(&vector1);

    insertarEnVectorAlInicio(&vector1, 123);
    mostrarVector(&vector1);
    eliminarDeVectorOrdenadoPorValor(&vector1, 123);
    int errorCode = insertarEnVectorEnOrdenSinDuplicado(&vector1, 123);

    if (errorCode == 2 || errorCode == 3)
    {
        printf("el valor a insertar ya se encontraba en el vector o el vector no tiene memoria\n");
    }

    if (errorCode == 1)
    {
        printf("se inserto el valor 123 sin duplicado\n");
    }

    return 0;
}
