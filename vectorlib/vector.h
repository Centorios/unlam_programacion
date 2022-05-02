#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

#define CAPACIDADMAXIMA_VECTOR 5

typedef struct
{
    int vec[CAPACIDADMAXIMA_VECTOR];
    int cantElementosCargados;
} Vector;
int existeValorEnVector(const Vector *vector, int valorABuscar);
int insertarEnVectorAlFinal(Vector *vec, int valorAInsertar);
int insertarEnVectorAlInicio(Vector *vec, int valorAInsertar);
int insertarEnVectorEnOrdenConDuplicado(Vector *vector, int valorAInsertar);
int insertarEnVectorEnOrdenSinDuplicado(Vector *vector, int valorAInsertar);
int buscarIndicePorValorEnVectorOrdenado(const Vector *vector, int valor);
int eliminarDeVectorOrdenadoPorValor(Vector *vector, int valorAEliminar);
void mostrarVector(const Vector *vec);
void crearVector(Vector *vec);
#endif // VECTOR_H_INCLUDED
