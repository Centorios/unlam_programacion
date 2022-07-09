#ifndef PILACIRCULAR_H_INCLUDED
#define PILACIRCULAR_H_INCLUDED
#include <stdlib.h>
#include <mem.h>
#define FALSO 0
#define VERDADERO 1
typedef void(*Accion)(void* elem, size_t tamElem, void* datosAccion);



typedef struct sNodo
{
    void* elem;
    size_t tamElem;
    struct sNodo* siguiente;  //si tira error aca falta el struct adelante de snodo*

} Nodo;



//en esta impl pila*pp apunta a la base

typedef Nodo* Pila;

void crearPila(Pila* pp);
int apilar(Pila* pp, const void* elemento, size_t tamElemento);
int desapilar(Pila* pp,void* elemento,size_t tamElemento);
int verTopePila(const Pila* pp,void*elemento,size_t tamElemento);
int pilaVacia(const Pila* pp);
int pilaLlena(const Pila* pp,size_t tamElemento);
void vaciarPila(Pila*pp);

#endif // PILACIRCULAR_H_INCLUDED
