#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED


typedef enum
{
    VERDADERO,
    FALSO
}booleano;

typedef enum eCODIGO
{
    TODO_OK,
    SIN_MEM,
    DUPLICADO
};

typedef int(*Cmp)(const void*,const void*);
typedef void(*Accion)(void* elem, size_t tamElem, void* datosAccion);
typedef struct sNodo
{
    struct sNodo* siguiente;
    size_t tamElem;
    void* elem;
}Nodo;

typedef Nodo* Lista;



void crearLista(Lista* pl);
int insertarEnListaOrdenada(Lista* pl,const void* elem, size_t tamElem,Cmp cmp);
int insertarAlInicio();
int insertarAlFinal();
int insertarEnPosicion();
int eliminarDeListaOrdenada(Lista* pl, const void* elem,size_t tamElem,Cmp cmp);
int eliminarDeListaDesordenada();
int eliminarDeListaPorPosicion();
int eliminarDeListaPrimero();
int eliminarDeListaUltimo();
int eliminarDeListaDuplicados(Lista* pl, const void* elem,size_t tamElem);
int buscarEnListaOrdenada(const Lista* pl, void* elem,size_t tamElem,Cmp cmp);
int buscarEnListaDesordenada();
int buscarEnListaPorPosicion();
void verPrimeroEnLista();
void verUltimoEnLista();
void ordenarLista(Lista* pl, Cmp cmp);
void VacialLista(Lista* pl);
void recorrerLista(Lista* pl, Accion accion,void* datosAccion);

#endif // LISTA_H_INCLUDED
