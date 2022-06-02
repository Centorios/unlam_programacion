#ifndef TDAPILADINAMICA_H_INCLUDED
#define TDAPILADINAMICA_H_INCLUDED
#define FALSO 0
#define VERDADERO 1
#include <mem.h>
#include <stdlib.h>



typedef struct sNodo
{
    void* elem;
    size_t tamElem;
    struct sNodo* sig;
}Nodo;

typedef Nodo* Pila;

void crearPila(Pila* pp);
int apilar(Pila* pp, const void* elemento, size_t tamElemento);
int desapilar(Pila* pp,void* elemento,size_t tamElemento);
int verTopePila(const Pila* pp,void*elemento,size_t tamElemento);
int pilaVacia(const Pila* pp);
int pilaLlena(const Pila* pp,size_t tamElemento);
void vaciarPila(Pila*pp);

#endif // TDAPILAESTATICA_H_INCLUDED
