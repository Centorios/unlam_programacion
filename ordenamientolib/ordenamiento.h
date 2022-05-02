#include <stdio.h>
#ifndef ORDENAMIENTO_H_INCLUDED
#define ORDENAMIENTO_H_INCLUDED

typedef int (*compare)(const void*,const void*);

void OrderBySelection(int* arr, int cantElem);
void OrderBySelectionVoid(void* arr, int cantElem, size_t tamElem, compare cmp);
void OrderByInsertion(void* arr,int cantElem);
void OrderByBubble(void* arr, int cantElem);
void *searchLowerElementVoid(void *start, void *endd, size_t tamElem, compare cmp);
int* searchLowerElement(int* start, int* endd);
void swapp(int *a, int *b);
void swappvoids(void *a, void *b, size_t tamElem);
#endif // ORDENAMIENTO_H_INCLUDED
