#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
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
typedef struct sNodo
{
    struct sNodo* siguiente;
    size_t tamElem;
    void* elem;
} Nodo;

typedef struct
{
    Nodo* primero;
    Nodo* actual;
} Iterador;

typedef Nodo* Lista;


void crearLista(Lista* pl);
Nodo* crearNodo(const void* elem,size_t tamElem);


int insertarEnListaOrdenada(Lista* pl,const void* elem, size_t tamElem,Cmp cmp);
int insertarEnListaAlPrincipio(Lista* pl, void* elem,size_t tamElem);
int insertarEnListaAlFinal(Lista*pl, void* elem,size_t tamElem);
//int insertarEnListaOrdenadaPropio(Lista* pl,const void* elem, size_t tamElem,Cmp cmp);

int eliminarDeListaOrdenada(Lista* pl, void* elem,size_t tamElem,Cmp cmp);
int eliminarDeListaDesordenada(Lista* pl, void* elem,size_t tamElem,Cmp cmp);


int buscarEnListaOrdenada(const Lista* pl, void* elem,size_t tamElem,Cmp cmp);

int listaVacia(Lista* pl);
int listaLlena(Lista* pl,size_t tamElem);
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




#endif // LISTA_H_INCLUDED
