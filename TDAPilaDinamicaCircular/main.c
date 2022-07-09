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
    Nodo* nue = crearNodo(elemento,tamElemento);

    if(!nue)
        return FALSO;

    if(*pp)
    {
        nue->siguiente = (*pp)->siguiente;
        (*pp)->siguiente = nue;

    }
    else
    {
        nue->siguiente = nue;
        *pp = nue;
    }

    return 1;


}


int desapilar(Pila* pp,void* elemento,size_t tamElemento)
{
    Nodo* aux;

    if(*pp == NULL)
        return 0;

    aux = (*pp)->siguiente;
    memcpy(elemento,aux->elem,tamElemento);
    if(aux == *pp)
        *pp = NULL;
    else
        (*pp)->siguiente = aux->siguiente;
    free(aux->elem);
    free(aux);

    return 1;

}

int verTopePila(const Pila* pp,void*elemento,size_t tamElemento)
{
    if(*pp == NULL)
        return 0;
    memcpy(elemento,(*pp)->elem,tamElemento);
    return 1;
}

int pilaVacia(const Pila* pp)
{
    return *pp == NULL;
}

int pilaLlena(const Pila* pp,size_t tamElemento)
{
    Nodo* aux = (Nodo*)malloc(sizeof(Nodo));
    void* elem= malloc(tamElemento);
    free (aux);
    free (elem);
    return aux==NULL || elem == NULL;
}

void vaciarPila(Pila*pp)
{
    while(*pp)
    {
        Nodo* aux = (*pp)->siguiente;

        if(*pp == aux)
        {

            *pp = NULL;
        }
        else
        {
            (*pp)->siguiente = aux->siguiente;
            free(aux->elem);
            free(aux);
        }

    }

}
