#include "./colacircular.h"

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

void crearCola(ColaCircular* pc)
{
    *pc = NULL;
}

int encolar(ColaCircular* pc,const void* elem,size_t tamElem)
{
    Nodo* nue = crearNodo(elem,tamElem);

    if(!nue)
        return FALSO;

    if(*pc)
    {
        nue->siguiente = (*pc)->siguiente;
        (*pc)->siguiente = nue;
    } else
    {
        nue->siguiente = nue;
    }
    *pc = nue;

    return VERDADERO;
}


int desencolar(ColaCircular* pc,void* elem,size_t tamElem)
{
}



int verFrente(ColaCircular* pc,void* dato,size_t tamElem)
{

}


int colaVacia(ColaCircular* pc)
{

}

int colaLlena(ColaCircular* pc,size_t tamElem)
{

}

void vaciarCola(ColaCircular* pc)
{

}
