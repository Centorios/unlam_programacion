#include <stdio.h>
#include <mem.h>
#include <stdlib.h>
#include "./cola.h"
#define min(a,b) (a < b ? a : b)

void crearCola(Cola* pc)
{
    pc->fin = pc->inicio = NULL;
}
int encolar(Cola* pc, const void* elem, size_t tamElem)
{
    Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));
    void* elemNodo = malloc(tamElem);
    if(!nuevo || !elemNodo)
    {
        free(nuevo);
        free(elemNodo);
        return 0;
    }
    memcpy(elemNodo,elem,tamElem);
    nuevo->elem = elemNodo;
    nuevo->tamElem = tamElem;
    nuevo->siguiente = NULL;
    if(!pc->fin)
    {
        pc->fin = nuevo;
    }
    else
    {
        pc->fin->siguiente = nuevo; //
    }

    pc->fin=nuevo;
    return 1;
}

int desencolar(Cola* pc,void* elem, size_t tamElem)
{
    if(!pc->inicio)
    {
        return 0;
    }
    Nodo* nae = pc->inicio;
    pc->inicio = nae->siguiente;
    if(!pc->inicio)
        pc->fin = NULL;
    memcpy(elem,nae->elem,min(nae->tamElem,tamElem));
    free(nae->elem);
    free(nae);
    return 1;
}

int verFrenteDeCola(Cola* pc, void* elem,size_t tamElem)
{
    if(!pc->inicio)
        return 0;
    Nodo* frente = pc->inicio;
    memcpy(elem,frente->elem,min(tamElem,frente->tamElem));
    return 1;
}


void vaciarCola(Cola* pc)
{
    Nodo* frente = pc->inicio;
    Nodo* nae;
    while(frente)
    {
        nae=frente;
        frente=nae->siguiente;
        free(nae->elem);
        free(nae);
    }
    pc->fin = pc->inicio = NULL;
}

int colaLlena(Cola* pc)
{

}
int colaVacia(Cola* pc)
{

}

