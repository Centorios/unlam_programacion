#include <stdio.h>
#include <stdlib.h>
#include <mem.h>
#include "./lista.h"

void crearLista(Lista* pl)
{
    pl = NULL;
}
int insertarEnListaOrdenada(Lista* pl,const void* elem, size_t tamElem,Cmp cmp)
{
    Nodo* nodoAInsertar = (Nodo*) malloc(sizeof(Nodo));
    void* dato = malloc(tamElem);
    if(!nodoAInsertar || !dato)
    {
        return SIN_MEM;
    }
    memcpy(nodoAInsertar->elem,elem,tamElem);
    nodoAInsertar->tamElem = tamElem;

    Nodo* actual = pl;
    Nodo* anterior = pl;

    if(!actual)
    {
        nodoAInsertar->siguiente = NULL;
        pl = nodoAInsertar;
    }
    if(cmp(actual->elem,elem) >0)
    {
        nodoAInsertar->siguiente=actual;
        pl = nodoAInsertar;
    }
    actual = actual->siguiente;


    while(actual || cmp(actual->elem,elem) < 0)
    {
        actual = actual->siguiente;
        anterior = anterior->siguiente;
    }

    anterior->siguiente = nodoAInsertar;
    nodoAInsertar->siguiente = actual;




    return 1;



}

