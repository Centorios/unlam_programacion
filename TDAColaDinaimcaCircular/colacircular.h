#ifndef COLACIRCULAR_H_INCLUDED
#define COLACIRCULAR_H_INCLUDED
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

typedef Nodo* ColaCircular;


void crearCola(ColaCircular* pc);
int encolar(ColaCircular* pc,const void* dato,size_t tamElem);
int desencolar(ColaCircular* pc,void* dato,size_t tamElem);
int verFrente(ColaCircular* pc,void* dato,size_t tamElem);
int colaVacia(ColaCircular* pc);
int colaLlena(ColaCircular* pc,size_t tamElem);
void vaciarCola(ColaCircular* pc);

#endif // COLACIRCULAR_H_INCLUDED
