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
    nue->sig = NULL;
    return nue;
}


void destruirNodo(Nodo* nae,void* dst,size_t tamElem)
{
    memcpy(dst,nae->elem,tamElem);
    free(nae);
    free(nae->elem);

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
        nue->sig = (*pc)->sig;
        (*pc)->sig = nue;
    }
    else
    {
        nue->sig = nue;
    }
    *pc = nue;

    return VERDADERO;
}


int desencolar(ColaCircular* pc,void* elem,size_t tamElem)
{
    Nodo* nae=(*pc)->sig;

    if(*pc!=nae)
        (*pc)->sig=nae->sig;
    else
        *pc=NULL;

    destruirNodo(nae,elem,tamElem);

    return 1;
}



int verFrente(ColaCircular* pc,void* elem,size_t tamElem)
{
    if(!*pc)
        return 0;

    Nodo* frente=(*pc)->sig;

    memcpy(elem,frente->elem,min(tamElem,frente->tamElem));

    return 1;
}


int colaVacia(ColaCircular* pc)
{
    if(!*pc)
        return 1;

    return 0;
}

int colaLlena(ColaCircular* pc,size_t tamElem)
{
    Nodo* nue= (Nodo*)malloc(sizeof(Nodo));
    void* elem=malloc(tamElem);

    free(nue);
    free(elem);

    if(!nue||!elem)
        return 1;

    return 0;
}

void vaciarCola(ColaCircular* pc)
{
    if(*pc)
        return;

    while((*pc)!=(*pc)->sig)
    {
        Nodo* nae=(*pc)->sig;
        (*pc)->sig=nae->sig;

        free(nae->elem);
        free(nae);
    }

    free(*pc);
    *pc=NULL;
}
