#include <stdlib.h>
#include <string.h>
#include "./ordenamiento.h"

void swappvoids(void *a, void *b, size_t tamElem)
{
    //char aux[tamElem];
    void *aux = malloc(tamElem);
    memcpy(aux, a, tamElem);
    memcpy(a, b, tamElem);
    memcpy(b, aux, tamElem);
    free(aux);
}

void swapp(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int *searchLowerElement(int *start, int *endd)
{
    int *i;
    int *lowerIndex = start;
    for (i = start + 1; i <= endd; i++)
    {
        if (*i < *lowerIndex)
        {
            lowerIndex = i;
        }
    }
    return lowerIndex;
}

void *searchLowerElementVoid(void *start, void *endd, size_t tamElem, compare cmp)
{
    void *i;
    void *lowerIndex = start;
    for (i = start + tamElem; i <= endd; i += tamElem)
    {
        if (cmp(i, lowerIndex) < 0)
        {
            lowerIndex = i;
        }
    }
    return lowerIndex;
}

void OrderBySelection(int *arr, int cantElem)
{
    int *i, *lowerIndex;
    int *lastIndex = arr + cantElem - 1;

    for (i = arr; i < lastIndex; i++) // pasadas
    {
        lowerIndex = searchLowerElement(i, lastIndex);

        if (lowerIndex != i)
        {
            swapp(i, lowerIndex);
        }
    }

    return;
}

void OrderBySelectionVoid(void *arr, int cantElem, size_t tamElem, compare cmp)
{

    void *i, *lowerIndex;

    void *lastIndex = arr + (cantElem - 1) * tamElem;

    for (i = arr; i < lastIndex; i += tamElem) // pasadas
    {
        lowerIndex = searchLowerElementVoid(i, lastIndex, tamElem, cmp);

        if (lowerIndex != i)
        {
            swappvoids(i, lowerIndex, tamElem);
        }
    }

    return;
}

void OrderByInsertion(void *arr, int cantElem)
{
    return;
}
void OrderByBubble(void *arr, int cantElem)
{
    return;
}
