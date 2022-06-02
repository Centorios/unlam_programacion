#include "./pilacircular.h"


void crearPila(Pila* pp)
{
    *pp = NULL;
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

int apilar(Pila* pp, const void* elemento, size_t tamElemento)
{
    Nodo* nue = crearNodo(elemento,tamElemento)

    if(!nue)
        return FALSO;

    if(*pp)
    {
        nue->siguiente = (*pp)->siguiente;
        (*pp)->siguiente = nue

    } else
    {
        nue->siguiente = nue;
        *pp = nue;
    }



}


int desapilar(Pila* pp,void* elemento,size_t tamElemento)
{

}

int verTopePila(const Pila* pp,void*elemento,size_t tamElemento)
{

}

int pilaVacia(const Pila* pp)
{

}

int pilaLlena(const Pila* pp,size_t tamElemento)
{

}

void vaciarPila(Pila*pp)
{

}
