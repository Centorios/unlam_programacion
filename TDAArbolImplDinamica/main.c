#include <stdlib.h>
#include <mem.h>
#include <stdio.h>
#include <math.h>
#include "./arbol.h"



int insertarArchivoEnArbol(Arbol* arbol,FILE* archivo,size_t tamElem,Cmp cmp);
void cargarArbolArchivo(Arbol* arbol,FILE* archivo,size_t tamElem,Cmp cmp,int li,int ls);
int insertarEnArbolArchivo(Arbol* arbol,const void* elem,size_t tamElem,Cmp cmp);

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

void destruirNodo(NodoA *nae, void *dato, size_t tamElem)
{
    memcpy(dato, nae->elem, tamElem);
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

    return insertarEnArbolRecursivo(auxCmp < 0 ? &(*pa)->der : &(*pa)->izq, dato, tamElem, cmp, actualizar);
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

        if (comp < 0)
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
    if(!*pa)
        return VERDADERO;
    return FALSO;
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
    if(!*pa)
        return;

    vaciarArbol(&(*pa)->izq);
    vaciarArbol(&(*pa)->der);

    free((*pa)->elem);
    free(*pa);

    *pa=NULL; //esto es en el padre

}

TipoArbol tipoArbol(const Arbol *pa)
{
    if(esArbolCompleto(pa))
        return COMPLETO;
    else if(esArbolBalanceado(pa))
        return BALANCEADO;
    else if(esArbolAVL(pa))
        return AVL;

    return DESBALANCEADO;
}

void imprimirArbolRecursiva(Arbol *pa, Imprimir accion, void *datosAccion, int nivel)
{
    if (!*pa)
        return;

    imprimirArbolRecursiva(&(*pa)->der, accion, datosAccion, nivel + 1);
    accion((*pa)->elem, datosAccion, nivel);
    imprimirArbolRecursiva(&(*pa)->izq, accion, datosAccion, nivel + 1);
}

void imprimirArbol(Arbol *pa, Imprimir accion, void *datosAccion)
{
    imprimirArbolRecursiva(pa, accion, datosAccion, 0);
}

Arbol *buscarRaizArbol(const Arbol *pa, const void *elem, size_t tamElem, Cmp cmp)
{
    if (!*pa)
    {
        return NULL;
    }

    int comp = cmp(elem, (*pa)->elem);

    if (comp == 0)
    {
        return (Arbol*)pa;
    }

    return buscarRaizArbol(comp < 0 ? &(*pa)->der : &(*pa)->izq, elem, tamElem, cmp);
}

Arbol *mayorDeArbol(Arbol *pa)
{
    if (!(*pa)->der)
    {
        return pa;
    }

    pa = &(*pa)->der;
    return mayorDeArbol(pa);
}

Arbol *menorDeArbol(Arbol *pa)
{
    if (!(*pa)->izq)
    {
        return pa;
    }

    pa = &(*pa)->izq;
    return menorDeArbol(pa);
}

int alturaArbol(Arbol *pa)
{
    if (!*pa)
    {
        return 0;
    }
    return max(alturaArbol(&(*pa)->izq), alturaArbol(&(*pa)->der)) + 1;
}

void eliminarRaizArbol(Arbol *pae)
{
    if (!(*pae)->izq && !(*pae)->der)
    {
        free(*pae);
        *pae = NULL;
        return;
    }

    int izq = alturaArbol(&(*pae)->izq);
    int der = alturaArbol(&(*pae)->der);

    Arbol *par = izq > der ? mayorDeArbol(&(*pae)->izq) : menorDeArbol(&(*pae)->der);

    (*pae)->elem = (*par)->elem;
    (*pae)->tamElem = (*par)->tamElem;

    eliminarRaizArbol(par);
}

int eliminarDeArbol(Arbol *pa, void *elem, size_t tamElem, Cmp cmp)
{
    Arbol *pae = buscarRaizArbol(pa, elem, tamElem, cmp);

    if (!pae)
    {
        return FALSO;
    }

    memcpy(elem, (*pae)->elem, min(tamElem, (*pae)->tamElem)); // previamente se copia en elem
    free((*pae)->elem);                                        // aca se elimina el elemento

    eliminarRaizArbol(pae); // elimina el nodo, no el elemento

    return VERDADERO;
}

int contarNodos(const Arbol *pa)
{
    if (!*pa)
    {
        return 0;
    }
    return contarNodos(&(*pa)->izq) + contarNodos(&(*pa)->der) + 1;
}

int contarNodoHastaNivel(const Arbol *pa, int nivel)
{
    if (!*pa)
    {
        return 0;
    }
    if (nivel == 0)
    {
        return 1;
    }
    return contarNodoHastaNivel(&(*pa)->izq, nivel - 1) + contarNodoHastaNivel(&(*pa)->der, nivel - 1)+1;
}

int esArbolCompleto(const Arbol *pa)
{
    int cnc = pow(2, alturaArbol((Arbol*)pa)) -1; // cantidad de nodos calculado
    int cnr = contarNodos(pa);         // cantidad de nodo real
    return cnc == cnr;
}

int esArbolBalanceado(const Arbol *pa)
{
    int h = alturaArbol((Arbol*)pa);

    if(h <= 2)
    {
        return VERDADERO;
    }
    int cantNodosCompletosPenultimoNivel = pow(2, h - 1)-1;
    int cantNodosReal = contarNodoHastaNivel(pa, h - 2);
    return cantNodosCompletosPenultimoNivel == cantNodosReal;
}
int esArbolAVL(const Arbol *pa)
{
    if (!*pa)
    {
        return VERDADERO;
    }
    int izq = alturaArbol(&(*pa)->izq);
    int der = alturaArbol(&(*pa)->der);


    if(abs(izq - der) > 1)
    {
        return FALSO;
    }
    return esArbolAVL(&(*pa)->izq) && esArbolAVL(&(*pa)->der);

}



int insertarArchivoEnArbol(Arbol* arbol,FILE* archivo,size_t tamElem,Cmp cmp)  //esta es la que se llama del main
{
    fseek(archivo,0, SEEK_END);

    int tamArchBytes=ftell(archivo);

    int cantReg = tamArchBytes/tamElem;

    int li=0;
    int ls=cantReg-1;

    cargarArbolArchivo(arbol,archivo,tamElem,cmp,li,ls);



    return 1;
}



void cargarArbolArchivo(Arbol* arbol,FILE* archivo,size_t tamElem,Cmp cmp,int li,int ls)
{
    if(li>ls)
        return;

    int m=(li+ls)/2;

    fseek(archivo,m*tamElem,SEEK_SET);

    void* elem;
    elem=malloc(tamElem);

    fread(elem,tamElem,1,archivo);

    insertarEnArbolArchivo(arbol,elem,tamElem,cmp);
    cargarArbolArchivo(arbol,archivo,tamElem,cmp,li,m-1);
    cargarArbolArchivo(arbol,archivo,tamElem,cmp,m+1,ls);
}


NodoA* crearNodoArchivo(const void* elem,size_t tamElem)
{
    NodoA* nue=(NodoA*)malloc(sizeof(NodoA));

    if(!nue)
    {
        free(nue);
        return NULL;
    }

    nue->elem=(void*)elem;
    nue->tamElem=tamElem;
    nue->izq=NULL;
    nue->der=NULL;

    return nue;
}




int insertarEnArbolArchivo(Arbol* arbol,const void* elem,size_t tamElem,Cmp cmp)
{
    if(!*arbol)
    {
        *arbol=crearNodoArchivo(elem,tamElem);

        return !*arbol? 0:1;
    }

    int comparacion=cmp(elem,(*arbol)->elem);

    if(comparacion==0)
    {
        return 2;
    }

    return insertarEnArbolArchivo(comparacion>0? &(*arbol)->der : &(*arbol)->izq,elem,tamElem,cmp);
}



