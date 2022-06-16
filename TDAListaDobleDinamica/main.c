#include "./listadoble.h"

NodoD *crearNodo(const void *elem, size_t tamElem)
{
    NodoD *nue = (NodoD *)malloc(sizeof(NodoD));
    void *elemNodo = malloc(tamElem);

    if (!nue || !elemNodo)
    {
        free(nue);
        free(elemNodo);
        return NULL;
    }
    memcpy(elemNodo, elem, tamElem);
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

void crearLista(Lista *pl)
{
    *pl = NULL;
}

int insertarEnListaOrdenada(Lista *pl, const void *elem, size_t tamElem, Cmp cmp)
{
    NodoD *act = *pl;

    if (!act) // act == NULL
    {
        *pl = crearNodo(elem, tamElem);

        if (!(*pl))
            return SIN_MEM;

        return VERDADERO;
    }

    while (act->anterior && cmp(elem, act->elem) < 0)
        act = act->anterior;

    while (act->siguiente && cmp(elem, act->elem) > 0)
        act = act->siguiente;

    int compRes = cmp(elem, act->elem);

    if (compRes == 0)
        return DUPLICADO;

    NodoD *anterior = NULL;
    NodoD *siguiente = NULL;

    if (compRes < 0)
    {
        siguiente = act;
        anterior = act->anterior;
    }
    else
    {
        anterior = act;
        siguiente = act->siguiente;
    }

    NodoD *nuevo = crearNodo(elem, tamElem);

    if (!nuevo)
    {
        return SIN_MEM;
    }

    nuevo->anterior = anterior;
    nuevo->siguiente = siguiente;

    if (anterior)
    {
        anterior->siguiente = nuevo;
    }

    if (siguiente)
    {
        siguiente->anterior = nuevo;
    }

    *pl = nuevo;

    return TODO_OK;
}

int insertarEnListaAlPrincipio(Lista *pl, void *elem, size_t tamElem)
{
    NodoD *act = *pl;
    if (act)
        while (act->anterior)
        {

            act = act->anterior;
        }

    NodoD *nue = crearNodo(elem, tamElem);

    if (!nue)
    {

        return SIN_MEM;
    }

    memcpy(nue->elem, elem, tamElem);
    nue->tamElem = tamElem;
    nue->siguiente = act;
    nue->anterior = NULL;
    if (act)
    {

        act->anterior = nue;
    }
    *pl = nue;
    return VERDADERO;
}

int insertarEnListaAlFinal(Lista *pl, void *elem, size_t tamElem)
{
    NodoD *act = *pl;

    if (act)
    {
        while (act->siguiente)
        {
            act = act->siguiente;
        }
    }
    NodoD *nue = crearNodo(elem, tamElem);
    memcpy(nue->elem, elem, tamElem);
    nue->siguiente = NULL;
    nue->anterior = act;
    nue->tamElem = tamElem;
    if (act)
    {
        act->siguiente = nue;
    }
    *pl = nue;
    return VERDADERO;
}

int eliminarDeListaOrdenada(Lista *pl, void *elem, size_t tamElem, Cmp cmp)
{

    if (!*pl)
    {
        return FALSO;
    }

    NodoD *nae = *pl;

    while (nae->anterior && cmp(elem, nae->elem) < 0)
        nae = nae->anterior;

    while (nae->siguiente && cmp(elem, nae->elem) > 0)
        nae = nae->siguiente;

    int compRes = cmp(elem, nae->elem);

    if (compRes != 0)
    {
        return FALSO;
    }

    if (nae->anterior)
    {
        nae->anterior->siguiente = nae->siguiente;
    }
    if (nae->siguiente)
    {
        nae->siguiente->anterior = nae->anterior;
    }

    if (nae == *pl)
    {
        if (nae->siguiente)
        {
            *pl = nae->siguiente;
        }
        else
        {
            *pl = nae->anterior;
        }
    }

    destruirNodo(nae, elem, tamElem);

    return VERDADERO;
}

int eliminarDeListaDesordenada(Lista *pl, void *elem, size_t tamElem, Cmp cmp)
{
    NodoD *act = *pl;
    if (!*pl)
    {
        return FALSO;
    }
    while (act->anterior)
    {
        act = act->anterior;
    }
    while (act)
    {
        if (cmp(elem, act->elem) == 0)
        {
            if (act->anterior)
            {
                act->anterior->siguiente = act->siguiente;
            }
            if (act->siguiente)
            {
                act->siguiente->anterior = act->anterior;
                *pl = act->siguiente;
            }
            else
            {
                *pl = act->anterior;
            }
            destruirNodo(act, elem, tamElem);
            return VERDADERO;
        }
        else
        {
            act = act->siguiente;
        }
    }
}

int buscarEnListaOrdenada(const Lista *pl, void *elem, size_t tamElem, Cmp cmp)
{
}

int listaVacia(Lista *pl)
{
    return *pl == NULL;
}
int listaLlena(Lista *pl, size_t tamElem)
{

    NodoD *nue = (NodoD *)malloc(sizeof(NodoD));
    void *aux = malloc(tamElem);
    free(nue);
    free(aux);
    return nue == NULL || aux == NULL;
}
void VaciarLista(Lista *pl)
{
    NodoD *act = *pl;

    if (act)
    {
        while (act->anterior)
        {
            act = act->anterior;
        }
        while (act)
        {
            NodoD *aux = act->siguiente;

            free(act->elem);
            free(act);
            act = aux;
        }
        *pl = NULL;
    }
}

void ordenarLista(Lista *pl, Cmp cmp)
{
    NodoD *act = *pl;
    NodoD *sup = NULL;
    NodoD *inf = NULL;
    int marca = 1;
    if (act == NULL)
    {
        return;
    }
    while (act->anterior)
    {
        act = act->anterior;
    }
    while (marca)
    {
        marca = 0;
        while (act->siguiente != sup)
        {
            if (cmp(act->elem, act->siguiente->elem) > 0)
            {
                void *aux = act->elem;
                size_t tamAux = act->tamElem;
                marca = 1;
                act->elem = act->siguiente->elem;
                act->siguiente->elem = aux;
                act->tamElem = act->siguiente->tamElem;
                act->siguiente->tamElem = tamAux;
            }
            act = act->siguiente;
        }
        sup = act;
        while (act->anterior != inf)
        {
            if (cmp(act->elem, act->anterior->elem) < 0)
            {
                void *aux = act->elem;
                size_t tamAux = act->tamElem;
                marca = 1;
                act->elem = act->anterior->elem;
                act->anterior->elem = aux;
                act->tamElem = act->anterior->tamElem;
                act->anterior->tamElem = tamAux;
            }
            act = act->anterior;
        }
        inf = act;
    }
}
void recorrerListaAccion(Lista *pl, Accion accion, void *datosAccion)
{
    NodoD *act = *pl;
    while (act->anterior)
    {
        act = act->anterior;
    }
    while (act)
    {
        accion(act->elem, datosAccion, datosAccion);
        act = act->siguiente;
    }
}

int eliminarDeListaOrdDuplicados(Lista *pl, const void *elem, size_t tamElem)
{
}
int eliminarDeListaDesordDuplicados(Lista *pl, const void *elem, size_t tamElem)
{
}
