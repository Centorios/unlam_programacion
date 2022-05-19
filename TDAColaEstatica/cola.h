#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED
#include <stdio.h>
#include <mem.h>
#define FALSO 0
#define VERDADERO 1
#define ERR_COLA_LLENA 2
#define TAM_COLA 500
#define min(a,b) ((a) < (b) ? (a) : (b))

typedef struct
{
    char vCola[TAM_COLA];
    unsigned frente;
    unsigned fondo;
    size_t tamDisponible;
}Cola;

void crearCola(Cola* pc);
int encolar(Cola* pc, const void* elemento,size_t tamElemento);
int desEncolar(Cola* pc, void* elemento,size_t tamElemento);
int verFrenteDeCola(Cola* pc,void* elemento,size_t tamElemento);
int colaVacia(Cola* pc);
int colaLlena(const Cola* pc,size_t tamElemento);
void vaciarCola(Cola* pc);






#endif // COLA_H_INCLUDED
