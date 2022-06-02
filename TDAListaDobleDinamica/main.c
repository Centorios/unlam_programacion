#include "./listadoble.h"

NodoD *crearNodo(const void *elem, size_t tamElem)
{
    NodoD *nue = (NodoD*)malloc(sizeof(NodoD));
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
    nue->anterior = NULL;
    return nue;
}

void destruirNodo(NodoD *nodo, void *elem, size_t tamElem)
{
    memcpy(elem, nodo->elem, min(tamElem, nodo->tamElem));
    free(nodo->elem);
    free(nodo);
}


void crearLista(Lista* pl)
{
    *pl = NULL;
}

int insertarEnListaOrdenada(Lista* pl,const void* elem, size_t tamElem,Cmp cmp)
{
    NodoD* act = *pl;

    if(!act) //act == NULL
    {
        *pl = crearNodo(elem,tamElem);

        if(!(*pl))
            return SIN_MEM;

        return VERDADERO;
    }

    while(act->anterior && cmp(elem,act->elem) < 0)
        act = act->anterior;

    while(act->siguiente && cmp(elem,act->elem) > 0)
        act = act->siguiente;

    int compRes = cmp(elem,act->elem);

    if(compRes == 0)
        return DUPLICADO;

    NodoD* anterior = NULL;
    NodoD* siguiente = NULL;

    if(compRes < 0)
    {
        siguiente = act;
        anterior = act->anterior;
    }
    else
    {
        anterior = act;
        siguiente = act->siguiente;
    }

    NodoD* nuevo = crearNodo(elem,tamElem);

    if(!nuevo)
    {
        return SIN_MEM;
    }

    nuevo->anterior = anterior;
    nuevo->siguiente = siguiente;

    if(anterior)
    {
        anterior->siguiente = nuevo;
    }

    if(siguiente)
    {
        siguiente->anterior = nuevo;
    }

    *pl = nuevo;

    return TODO_OK;
}

int insertarEnListaAlPrincipio(Lista* pl, void* elem,size_t tamElem)
{

}

int insertarEnListaAlFinal(Lista*pl, void* elem,size_t tamElem)
{

}

int eliminarDeListaOrdenada(Lista* pl, void* elem,size_t tamElem,Cmp cmp)
{

    if(!*pl)
    {
        return FALSO;
    }

    NodoD* nae = *pl;

    while(nae->anterior && cmp(elem,nae->elem) < 0)
        nae = nae->anterior;

    while(nae->siguiente && cmp(elem,nae->elem) > 0)
        nae = nae->siguiente;

    int compRes = cmp(elem,nae->elem);

    if(compRes != 0)
    {
        return FALSO;
    }

    if(nae->anterior)
    {
        nae->anterior->siguiente = nae->siguiente;
    }
    if(nae->siguiente)
    {
        nae->siguiente->anterior = nae->anterior;
    }

    if(nae == *pl)
    {
        if(nae->siguiente)
        {
            *pl = nae->siguiente;
        } else {
            *pl = nae->anterior;
        }
    }

    destruirNodo(nae,elem,tamElem);

    return VERDADERO;
}


int eliminarDeListaDesordenada(Lista* pl, void* elem,size_t tamElem,Cmp cmp)
{

}


int buscarEnListaOrdenada(const Lista* pl, void* elem,size_t tamElem,Cmp cmp)
{

}

int listaVacia(Lista* pl)
{

}
int listaLlena(Lista* pl)
{

}
void VacialLista(Lista* pl)
{

}

void ordenarLista(Lista* pl, Cmp cmp)
{

}
void recorrerLista(Lista* pl, Accion accion,void* datosAccion)
{

}

int eliminarDeListaOrdDuplicados(Lista* pl, const void* elem,size_t tamElem)
{

}
int eliminarDeListaDesordDuplicados(Lista* pl, const void* elem,size_t tamElem)
{

}
