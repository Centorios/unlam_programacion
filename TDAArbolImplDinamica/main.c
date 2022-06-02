#include <stdlib.h>
#include <mem.h>
#include "./arbol.h"

void crearArbol(Arbol *pa)
{
    *pa = NULL;
}

NodoA *crearNodo(void *dato, size_t tamElem)
{
    NodoA *nai = (NodoA *)malloc(sizeof(NodoA));
    void *elem = malloc(tamElem);

    if (!nai || !elem)
    {
        free(nai);
        free(elem);
        return NULL;
    }
    memcpy(elem, dato, tamElem);
    nai->der = NULL;
    nai->izq = NULL;
    nai->tamElem = tamElem;
    nai->elem = elem;
    return nai;
}


void destruirNodo(NodoA* nae, void* dato, size_t tamElem)
{
    memcpy(dato,nae->elem,tamElem);
    free(nae->elem);
    free(nae);
}

int insertarEnArbolRecursivo(Arbol *pa, void *dato, size_t tamElem, Cmp cmp, Actualizar actualizar)
{
    if (!*pa)
    {
        NodoA *nai = crearNodo(dato, tamElem);
        if (!nai)
        {
            return SIN_MEM;
        }
        *pa = nai;
        return VERDADERO;
    }

    int auxCmp = cmp((*pa)->elem, dato);

    if (auxCmp == 0)
    {
        if (actualizar)
        {
            actualizar((*pa)->elem, dato);
        }
        return DUPLICADO;
    }

    return insertarEnArbolRecursivo(auxCmp > 0 ? &(*pa)->izq : &(*pa)->der, dato, tamElem, cmp, actualizar);
}

int insertarEnArbolIterativo(Arbol *pa, void *dato, size_t tamElem, Cmp cmp, Actualizar actualizar)
{
    int comp;

    while (*pa)
    {
        comp = cmp(dato, (*pa)->elem);

        if (comp == 0)
        {
            if (actualizar)
                return actualizar((*pa)->elem, dato);
            return DUPLICADO;
        }

        if (comp > 0)
            pa = &(*pa)->izq;
        else
            pa = &(*pa)->der;
    }

    NodoA *nai = crearNodo(dato, tamElem);
    if (!nai)
        return SIN_MEM;
    *pa = nai;
    return VERDADERO;
}

int buscarNodo(Arbol *pa, void *dato, size_t tamElem, Cmp cmp, void *dst)
{
    if (!*pa)
        return FALSO;

    int auxCmp = cmp((*pa)->elem, dato);

    if (auxCmp == 0)
    {
        memcpy(dst, dato, tamElem);
        return VERDADERO;
    }
    if (auxCmp > 0)
    {

        return buscarNodo(&(*pa)->izq, dato, tamElem, cmp, dst);
    }
    else
    {
        return buscarNodo(&(*pa)->der, dato, tamElem, cmp, dst);
    }
}

int arbolVacio(Arbol *pa)
{
}

void recorrerArbolPreOrden(Arbol *pa, Accion accion, void *datosAccion)
{
    if (!*pa)
        return;

    accion((*pa)->elem, datosAccion);
    recorrerArbolPreOrden(&(*pa)->izq, accion, datosAccion);
    recorrerArbolPreOrden(&(*pa)->der, accion, datosAccion);
}

void recorrerArbolEnOrden(Arbol *pa, Accion accion, void *datosAccion)
{
    if (!*pa)
        return;

    recorrerArbolEnOrden(&(*pa)->izq, accion, datosAccion);
    accion((*pa)->elem, datosAccion);
    recorrerArbolEnOrden(&(*pa)->der, accion, datosAccion);
}

void recorrerArbolPosOrden(Arbol *pa, Accion accion, void *datosAccion)
{
    if (!*pa)
        return;

    recorrerArbolPosOrden(&(*pa)->izq, accion, datosAccion);
    recorrerArbolPosOrden(&(*pa)->der, accion, datosAccion);
    accion((*pa)->elem, datosAccion);
}
void vaciarArbol(Arbol *pa)
{
}
int esArbolCompleto(const Arbol *pa)
{
}
int esArbolBalanceado(const Arbol *pa)
{
}
int esArbolAVL(const Arbol *pa)
{
}
TipoArbol tipoArbol(const Arbol *pa)
{
}
void imprimirArbolRecursiva(Arbol *pa, Imprimir accion, void *datosAccion, int nivel)
{
    if (!*pa)
        return;

    imprimirArbol(&(*pa)->izq, accion, datosAccion, nivel + 1);
    accion((*pa)->elem, datosAccion, nivel);
    imprimirArbol(&(*pa)->der, accion, datosAccion, nivel + 1);
}

void imprimirArbol(Arbol *pa, Imprimir accion, void *datosAccion, int nivel)
{
    imprimirArbolRecursiva(pa, accion, datosAccion, 0);
}
