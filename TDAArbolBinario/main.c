#include<stdlib.h>
#include<mem.h>
#include "./arbol.h"


void crearArbol(Arbol* pa)
{
    *pa=NULL;
}


NodoA* crearNodo(void* dato,size_t tamElem)
{
    NodoA* nai = (NodoA*) malloc(sizeof(NodoA));
    void* elem = malloc(tamElem);

    if(!nai || !elem)
    {
        free(nai);
        free(elem);
        return NULL;
    }
    memcpy(elem,dato,tamElem);
    nai->der = NULL;
    nai->izq = NULL;
    nai->tamElem = tamElem;
    nai->elem = elem;
    return nai;
}


int insertarEnArbol(Arbol* pa,void* dato,size_t tamElem,Cmp cmp)
{
    if(!*pa)
    {
        NodoA* nai = crearNodo(dato,tamElem);
        if(!nai)
        {
            return SIN_MEM;
        }
        *pa = nai;
        return VERDADERO;
    }

    int auxCmp = cmp((*pa)->elem,dato);

    if(auxCmp == 0)
        return DUPLICADO;

    if(auxCmp > 0)
    {
        return insertarEnArbol(&(*pa)->izq,dato,tamElem,cmp);
    }
    return insertarEnArbol(&(*pa)->der,dato,tamElem,cmp);

}


int buscarNodo(Arbol* pa,void* dato,size_t tamElem,Cmp cmp,void* dst)
{
    if(!*pa)
        return FALSO;

    int auxCmp = cmp((*pa)->elem,dato);

    if(auxCmp == 0)
    {
        memcpy(dst,dato,tamElem);
        return VERDADERO;
    }
    if(auxCmp > 0)
    {

        return buscarNodo(&(*pa)->izq,dato,tamElem,cmp,dst);
    }
    else
    {
        return buscarNodo(&(*pa)->der,dato,tamElem,cmp,dst);
    }
}




