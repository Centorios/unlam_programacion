#include "./TDAPilaDinamica.h"
#define min(a,b) (a>b? a:b)


void crearPila(Pila* pp)
{
    *pp = NULL;
}


int apilar(Pila* pp,const void* elem, size_t tamElem)
{
    Nodo* nue = (Nodo*)malloc(sizeof(Nodo));
    void* elemNodo = malloc(tamElem);

    if(!nue || !elemNodo)
    {
        free(nue);
        free(elemNodo);
        return FALSO;
    }

    nue->elem = elemNodo;
    nue->tamElem = tamElem;
    nue->sig = *pp;
    *pp = nue;

    memcpy(elemNodo,elem,tamElem);
    return VERDADERO;
}



int desapilar(Pila* pp ,void* elem, size_t tamElem)
{
    if(!*pp)
        return FALSO;

    Nodo* nae = *pp;
    memcpy(elem,nae->elem,min(tamElem,nae->tamElem));
    *pp = nae->sig;
    free(nae->elem);
    free(nae);
    return VERDADERO;

}



int verTopePila(const Pila* pp,void* elem, size_t tamElem)
{
    if(!*pp)
        return FALSO;

    Nodo* tope = *pp;
    memcpy(elem,tope->elem,min(tamElem,tope->tamElem));
    return VERDADERO;
}

int pilaLlena(const Pila* pp,size_t tamElem)
{
    void* nodo = malloc(sizeof(Nodo));
    void* elem = malloc(tamElem);
    free(nodo);
    free(elem);
    return !nodo||!elem;
}

void vaciarPila(Pila* pp)
{
    Nodo* nae = *pp;

    while(nae)
    {
        *pp = nae->sig;
        free(nae->elem);
        free(nae);
        nae = *pp;
    }

}
