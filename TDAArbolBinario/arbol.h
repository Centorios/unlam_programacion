#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED

#define VERDADERO 1
#define FALSO 0
#define SIN_MEM 2
#define DUPLICADO 3

typedef int (*Cmp)(const void*,const void*);

typedef struct sNodo
{
    void* elem;
    size_t tamElem;
    struct sNodo* izq;
    struct sNodo* der;
} NodoA;

typedef NodoA* Arbol;

void crearArbol(Arbol* pa);
NodoA* crearNodo(void* dato,size_t tamElem);
int insertarEnArbol(Arbol* pa,void* dato,size_t tamElem,Cmp cmp);
int buscarNodo(Arbol* pa,void* dato,size_t tamElem,Cmp cmp,void* dst);

#endif // ARBOL_H_INCLUDED
