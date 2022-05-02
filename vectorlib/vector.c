#include <stdio.h>
#include "vector.h"

#define VERDADERO 1
#define FALSO 0
#define SIN_MEMORIA 2
#define DUPLICADO 3
#define NO_ENCONTRADO -1

void crearVector(Vector *vec)
{
    vec->cantElementosCargados = 0;
}

int existeValorEnVector(const Vector *vector, int valorABuscar)
{
    for (int i = (vector->cantElementosCargados - 1); i >= 0; i--)
    {
        if (valorABuscar == vector->vec[i])
        {
            return VERDADERO;
        }
    }
    return FALSO;
}

int insertarEnVectorAlFinal(Vector *vector, int valorAInsertar)
{
    if (vector->cantElementosCargados == CAPACIDADMAXIMA_VECTOR)
    {
        return SIN_MEMORIA;
    }

    vector->vec[vector->cantElementosCargados] = valorAInsertar;
    vector->cantElementosCargados++;
    return VERDADERO;
}

int insertarEnVectorAlInicio(Vector *vector, int valorAInsertar)
{
    if (vector->cantElementosCargados == CAPACIDADMAXIMA_VECTOR)
    {
        return SIN_MEMORIA;
    }

    int i = vector->cantElementosCargados - 1;

    while (i >= 0)
    {
        vector->vec[i] = vector->vec[i - 1];
        i--;
    }

    vector->vec[0] = valorAInsertar;
    vector->cantElementosCargados++;
    return VERDADERO;
}

int insertarEnVectorEnOrdenConDuplicado(Vector *vector, int valorAInsertar)
{
    if (vector->cantElementosCargados == CAPACIDADMAXIMA_VECTOR)
    {
        return SIN_MEMORIA;
    }
    int i = vector->cantElementosCargados - 1; // la ultima posicion libre porque va de 0 a cantElementosCargados-1

    while (i >= 0 && valorAInsertar < vector->vec[i])
    {
        vector->vec[i + 1] = vector->vec[i];
        i--;
    }
    vector->vec[i + 1] = valorAInsertar;

    vector->cantElementosCargados++;

    return VERDADERO;
}

int insertarEnVectorEnOrdenSinDuplicado(Vector *vector, int valorAInsertar)
{
    if (vector->cantElementosCargados == CAPACIDADMAXIMA_VECTOR)
    {
        return SIN_MEMORIA;
    }

    if (existeValorEnVector(vector, valorAInsertar))
    {
        return DUPLICADO;
    }
    int i = vector->cantElementosCargados - 1; // la ultima posicion libre porque va de 0 a cantElementosCargados-1

    while (i >= 0 && vector->vec[i] > valorAInsertar)
    {
        vector->vec[i + 1] = vector->vec[i];
        i--;
    }

    vector->vec[i + 1] = valorAInsertar;

    vector->cantElementosCargados++;

    return VERDADERO;
}

int buscarIndicePorValorEnVectorOrdenado(const Vector *vector, int valor)
{
    int i = 0;

    while (i < vector->cantElementosCargados && vector->vec[i] < valor)
    {
        i++;
    }

    if (i == vector->cantElementosCargados || vector->vec[i] < valor)
    {
        return NO_ENCONTRADO;
    }

    return i; // devuelve el indice del vector buscado
}

int eliminarDeVectorOrdenadoPorValor(Vector *vector, int valorAEliminar)
{
    int posEliminar = buscarIndicePorValorEnVectorOrdenado(vector, valorAEliminar);
    if (posEliminar == NO_ENCONTRADO)
    {
        return FALSO;
    }

    int i;

    for (i = posEliminar; i <= vector->cantElementosCargados - 2; i++)
    {
        vector->vec[i] = vector->vec[i + 1];
    }

    vector->cantElementosCargados--;

    return VERDADERO;
}

void mostrarVector(const Vector *vector)
{
    int i;
    printf("[");
    for (i = 0; i < vector->cantElementosCargados; i++)
    {
        printf("%d,", vector->vec[i]);
    }
    printf("]\n");
}
