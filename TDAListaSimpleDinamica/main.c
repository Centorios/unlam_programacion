#include <stdio.h>
#include <stdlib.h>
#include <mem.h>
#include "./lista.h"


Nodo *crearNodo(const void *elem, size_t tamElem);
void destruirNodo(Nodo *nodo, void *elem, size_t tamElem);

void crearLista(Lista *pl)
{
    *pl = NULL;
}

Nodo *crearNodo(const void *elem, size_t tamElem)
{
    Nodo *nue = (Nodo*)malloc(sizeof(Nodo));
    void *elemNodo = malloc(tamElem);

    if (!nue || !elemNodo)
    {
        free(nue);
        free(elemNodo);
        return NULL;
    }
    memcpy(elemNodo, elem,tamElem);
    nue->elem = elemNodo;
    nue->tamElem = tamElem;
    nue->siguiente = NULL;
    return nue;
}

void destruirNodo(Nodo *nodo, void *elem, size_t tamElem)
{
    memcpy(elem, nodo->elem, min(tamElem, nodo->tamElem));
    free(nodo->elem);
    free(nodo);
}

int listaVacia(Lista* pl)
{
    if(!*pl)
        return 1;
    return 0;
}

int listaLlena(Lista* pl,size_t tamElem)
{
    Nodo* nue=(Nodo*)malloc(sizeof(Nodo));
    void* elemNodo=malloc(tamElem);

    free(nue);
    free(elemNodo);

    if(!nue || !elemNodo)
        return 1;

    return 0;
}

int insertarEnListaAlPrincipio(Lista* pl, void* elem,size_t tamElem)
{

    Nodo* nue = crearNodo(elem,tamElem);
    nue->siguiente=*pl;
    *pl=nue;
    return VERDADERO;
}


int insertarEnListaAlFinal(Lista* pl, void* elem,size_t tamElem)
{
    Nodo* nue = crearNodo(elem,tamElem);
    while(*pl)
    {
        pl = &(*pl)->siguiente;
    }
    *pl= nue;
    return VERDADERO;

}


/*
int insertarEnListaOrdenadaPropio(Lista *pl, const void *elem, size_t tamElem, Cmp cmp)
{
    Nodo* nodoAInsertar = crearNodo(elem,tamElem);

    if(!nodoAInsertar)
    {
        return 0;
    }


    Nodo *actual = *pl;
    Nodo *anterior = *pl;

    if (!actual)
    {
        nodoAInsertar->siguiente = NULL;
        *pl = nodoAInsertar;
    }
    if (cmp(actual->elem, elem) > 0)
    {
        nodoAInsertar->siguiente = actual;
        *pl = nodoAInsertar;
    }
    actual = actual->siguiente;

    while (actual || cmp(actual->elem, elem) < 0)
    {
        actual = actual->siguiente;
        anterior = anterior->siguiente;
    }

    anterior->siguiente = nodoAInsertar;
    nodoAInsertar->siguiente = actual;

    return 1;
}
*/
int insertarEnListaOrdenada(Lista *pl, const void *elem, size_t tamElem, Cmp cmp)
{

    while (*pl && cmp(elem, (*pl)->elem) > 0) //*pl va primero para cubrir el null
        pl = &(*pl)->siguiente;

    if (*pl && cmp(elem, (*pl)->elem) == 0) // sin duplicados
        return DUPLICADO;

    Nodo *nodoAInsertar = crearNodo(elem, tamElem);

    if (!nodoAInsertar)
        return SIN_MEM;

    nodoAInsertar->siguiente = *pl;
    *pl = nodoAInsertar;

    return VERDADERO;
}


int eliminarDeListaOrdenada(Lista *pl, void *elem, size_t tamElem, Cmp cmp)
{

    while (*pl && cmp(elem, (*pl)->elem) > 0) //*pl va primero para cubrir el null
        pl = &(*pl)->siguiente;

    if (!*pl || cmp(elem, (*pl)->elem) < 0) // corto si estoy en el fin de la lista, o si encontre un elemento mas grande que el que estoy buscando
        return FALSO;

    Nodo *nodoAEliminar = *pl;
    *pl = nodoAEliminar->siguiente;

    destruirNodo(nodoAEliminar, elem, tamElem);

    return VERDADERO;
}


int eliminarDeListaDesordenada(Lista *pl,void* elem,size_t tamElem,Cmp cmp)
{

    while(*pl)
    {
        if(cmp((*pl)->elem,elem)==0)
        {
            Nodo* nae = (*pl);
            *pl = (*pl)->siguiente;
            destruirNodo(nae,elem,tamElem);
        }
        else
            pl = &(*pl)->siguiente;
    }
    return VERDADERO;
}





Lista* buscarMenor(Lista* pl,Cmp cmp)
{
    Lista* plMenor = pl;
    Lista* plActual = &(*plMenor)->siguiente;
    while(*plActual)
    {
        if(cmp((*plActual)->elem,(*plMenor)->elem) <0)
        {
            plMenor=plActual;
        }
        plActual=&(*plActual)->siguiente;
    }
    return plMenor;
}




void ordenarLista(Lista* pl,Cmp cmp)
{
    Lista lOrd;
    Lista* plUlt=&lOrd;
    Lista* plMenor;
    while(*pl)
    {
        plMenor=buscarMenor(pl,cmp);
        *plUlt=*plMenor;
        *plMenor=(*plMenor)->siguiente;
        plUlt=&(*plUlt)->siguiente;
    }
    *pl = lOrd;
}



void recorrerLista(Lista *pl,Accion accion, void* datosAccion)
{
    while(*pl)
    {
        accion((*pl)->elem,(*pl)->tamElem,datosAccion),
               pl=&(*pl)->siguiente;
    }

}






int crearIterador(Iterador *it, const Lista*pl)
{

    it->primero = *pl;
    it->actual = NULL;

    if(!*pl)
        return FALSO;

    return VERDADERO;
}


int primeroDeLista(Iterador *it, void* elem,size_t tamElem)
{
    if(!it->primero)
        return FALSO;

    it->actual = it->primero;
    memcpy(elem, it->actual->elem, min(tamElem, it->actual->tamElem));
    return VERDADERO;
}


int siguienteDeLista(Iterador* it,void* elem,size_t tamElem)
{
    if(!it->actual)
        return FALSO;

    it->actual = it->actual->siguiente;
    if(!it->actual)
        return FALSO;

    memcpy(elem, it->actual->elem, min(tamElem, it->actual->tamElem));
    return VERDADERO;
}



int haySiguienteDeLista(Iterador* it)
{
    if(!it->actual)
        return FALSO;

    return it->actual->siguiente != NULL;
}


int finLista(Iterador* it)
{
    return !it->actual;
}


