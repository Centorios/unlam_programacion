#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED
#include <stdio.h>
#include <mem.h>
#define FALSO 0
#define VERDADERO 1
#define ERR_PILA_LLENA 2

#define min(a,b) ((a) < (b) ? (a) : (b))


///////////////PILA IMPL ESTATICA//////////////////////////////////////
#define TAM_PILA 1000

typedef struct
{
    char vPila[TAM_PILA];
    unsigned int tope;
}Pila;

/////////////////////////////////////////////////////////////////////////////
void crearPila(Pila* pp);
int apilar(Pila* pp, const void* elemento,size_t tamElemento);
int desapilar(Pila* pp, void* elemento,size_t tamElemento);
int verTopeDePila(Pila* pp,void* elemento,size_t tamElemento);
int pilaVacia(Pila* pp);
int pilaLlena(const Pila* pp,size_t tamElemento);
void vaciarPila(Pila* pp);

#endif // PILA_H_INCLUDED
