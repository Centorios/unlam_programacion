#ifndef LISTADOBLE_H_INCLUDED
#define LISTADOBLE_H_INCLUDED
#include <stdlib.h>
#include <mem.h>
#define min(a,b) ((a) < (b)? (a):(b))

enum
{
    VERDADERO,
    FALSO
} booleano;

enum
{
    TODO_OK=1,
    SIN_MEM=2,
    DUPLICADO=3
} eCODIGO;

typedef int(*Cmp)(const void*,const void*);
typedef void(*Accion)(void* elem, size_t tamElem, void* datosAccion);

typedef struct sNodoD
{
    struct sNodoD* anterior;
    void* elem;
    size_t tamElem;
    struct sNodoD* siguiente;
} NodoD;

typedef struct
{
    NodoD* primero;
    NodoD* actual;
} Iterador;

typedef NodoD* Lista;


void crearLista(Lista* pl);
NodoD* crearNodo(const void* elem,size_t tamElem);


int insertarEnListaOrdenada(Lista* pl,const void* elem, size_t tamElem,Cmp cmp);
int insertarEnListaAlPrincipio(Lista* pl, void* elem,size_t tamElem);
int insertarEnListaAlFinal(Lista*pl, void* elem,size_t tamElem);
//int insertarEnListaOrdenadaPropio(Lista* pl,const void* elem, size_t tamElem,Cmp cmp);

int eliminarDeListaOrdenada(Lista* pl, void* elem,size_t tamElem,Cmp cmp);
int eliminarDeListaDesordenada(Lista* pl, void* elem,size_t tamElem,Cmp cmp);


int buscarEnListaOrdenada(const Lista* pl, void* elem,size_t tamElem,Cmp cmp);

int listaVacia(Lista* pl);
int listaLlena(Lista* pl);
void VacialLista(Lista* pl);

void ordenarLista(Lista* pl, Cmp cmp);
void recorrerLista(Lista* pl, Accion accion,void* datosAccion);

int eliminarDeListaOrdDuplicados(Lista* pl, const void* elem,size_t tamElem);
int eliminarDeListaDesordDuplicados(Lista* pl, const void* elem,size_t tamElem);


//iter

int crearIterador(Iterador *it, const Lista*pl);
int primeroDeLista(Iterador *it, void* elem,size_t tamElem);
int siguienteDeLista(Iterador* it,void* elem,size_t tamElem);
int haySiguienteDeLista(Iterador* it);
int finLista(Iterador* it);





#endif // LISTADOBLE_H_INCLUDED
