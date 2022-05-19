#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED

typedef struct sNodo
{
    struct sNodo* siguiente;
    void* elem;
    size_t tamElem;
}Nodo;


typedef struct
{
    Nodo* inicio;
    Nodo* fin;
}Cola;



void crearCola(Cola* pc);
int encolar(Cola* pc, const void* elem, size_t tamElem);
int desencolar(Cola* pc,void* elem, size_t tamElem);
int verFrenteDeCola(Cola* pc, void* elem,size_t tamElem);
void vaciarCola(Cola* pc);
int colaLlena(Cola* pc);
int colaVacia(Cola* pc);

#endif // COLA_H_INCLUDED
