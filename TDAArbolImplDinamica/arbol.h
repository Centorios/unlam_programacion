#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED


#define VERDADERO 1
#define FALSO 0
#define SIN_MEM 2
#define DUPLICADO 3

typedef int (*Cmp)(const void *, const void *);
typedef int (*Accion)(void *elem, void *datosAccion);
typedef int(*Actualizar)(void* elem,const void* dato);
typedef int(*Imprimir)(void* elem,const void* dato,int nivel);
typedef struct sNodo
{
    void *elem;
    size_t tamElem;
    struct sNodo *izq;
    struct sNodo *der;
} NodoA;

typedef NodoA *Arbol;

typedef enum
{
    COMPLETO,
    BALANCEADO,
    AVL,
    DESBALANCEADO
} TipoArbol;

void crearArbol(Arbol *pa);
NodoA *crearNodo(void *dato, size_t tamElem);
int insertarEnArbolRecursivo(Arbol *pa, void *dato, size_t tamElem, Cmp cmp,Actualizar actualizar);
int insertarEnArbolIterativo(Arbol *pa, void *dato, size_t tamElem, Cmp cmp, Actualizar actualizar);
int buscarNodo(Arbol *pa, void *dato, size_t tamElem, Cmp cmp, void *dst);
int arbolVacio(Arbol *pa);
void recorrerArbolPreOrden(Arbol *pa, Accion accion, void *datosAccion);
void recorrerArbolEnOrden(Arbol *pa, Accion accion, void *datosAccion);
void recorrerArbolPosOrden(Arbol *pa, Accion accion, void *datosAccion);
void vaciarArbol(Arbol *pa);
int esArbolCompleto(const Arbol *pa);
int esArbolBalanceado(const Arbol *pa);
int esArbolAVL(const Arbol *pa);
TipoArbol tipoArbol(const Arbol *pa);
void imprimirArbolRecursiva(Arbol *pa, Imprimir accion, void *datosAccion, int nivel);
void imprimirArbol(Arbol *pa, Imprimir accion, void *datosAccion, int nivel);

#endif // ARBOL_H_INCLUDED
