#include <stdio.h>
#include <stdlib.h>
#include "../ordenamientolib/ordenamiento.h"

typedef struct
{
    int codigo;
    char descripcion[200];
    int cantidad;
    float precio;

} Producto;

int cmpInt(const void *a, const void *b)
{
    int *ai = (int *)a;
    int *bi = (int *)b;
    return *ai - *bi;
    // return *(int*)a - *(int*)b;
}

int cmpProductsDesc(const void *a, const void *b)
{
    Producto *prodA = (Producto *)a;
    Producto *prodB = (Producto *)b;
    return strcmp(prodA->descripcion, prodB->descripcion);
}

int cmpProductosPrecios(const void *a, const void *b)
{
    Producto *prodA = (Producto *)a;
    Producto *prodB = (Producto *)b;
    return (int)(prodA->precio * 100) - (int)(prodB->precio * 100);
}

int main()
{
    int vector[10] = {3, 4, 8, 7, 6, 1, 2, 9, 5, 10};
    int vector2[10] = {3, 4, 8, 7, 6, 1, 2, 9, 5, 10};
    Producto vector3[10] = {
        {3, "Leche", 30, 10.5},
        {7, "Arroz", 70, 11.5},
        {4, "Huevos", 40, 40.5},
        {1, "Pan", 10, 10.5},
        {5, "Cereal", 50, 50.5},
        {10, "Jabon", 100, 100},
        {6, "Lavandina", 60, 60.5},
        {9, "Cafe", 90, 90.5},
        {8, "Mantequilla", 80, 80.5},
        {2, "Bolas de mono", 20, 20.5},
    };
    OrderBySelection(vector, 10);
    OrderBySelectionVoid(vector2, 10, sizeof(int), cmpInt);
    OrderBySelectionVoid(vector3, 10, sizeof(Producto), cmpProductosPrecios);
    int i;
    for (i = 0; i <= 9; i++)
    {
        printf("%d ", vector[i]);
    }
    puts("");
    for (i = 0; i <= 9; i++)
    {
        printf("%d ", vector2[i]);
    }
    puts("");
    for (i = 0; i <= 9; i++)
    {
        printf("%d,%s,%d,%f \n", vector3[i].cantidad, vector3[i].descripcion, vector3[i].codigo, vector3[i].precio);
    }

    return 0;
}
