#include "../pila.h"
#include <stdio.h>
#include <mem.h>



int pilaVacia(Pila* pp)
{
    return pp->tope == 0;
}

void vaciarPila(Pila* pp)
{
    pp->tope = 0;
}

void crearPila(Pila * pp){
    pp->tope = 0;
}

int apilar(Pila * pp,const void* elemento,size_t tamElemento)
{
    if(tamElemento+sizeof(size_t)>TAM_PILA-pp->tope)
    {
        return FALSO;
    }
    memcpy(pp->vPila+pp->tope,elemento,tamElemento);
    pp->tope+=tamElemento;
    *(size_t*)(pp->vPila+pp->tope)=tamElemento;
    pp->tope+=sizeof(size_t);
    return VERDADERO;
}


int desapilar(Pila *pp,void* elemento,size_t tamElemento)
{
    if(pp->tope == 0)
    {
        return FALSO;
    }
    pp->tope-=sizeof(size_t);
    size_t tamElementoApilado=*(size_t*)(pp->tope+pp->vPila);
    pp->tope-=tamElementoApilado;
    memcpy(elemento,pp->vPila+pp->tope,min(tamElemento,tamElementoApilado));
    return VERDADERO;
}


int pilaLlena(const Pila* pp,size_t tamElemento)
{
    return tamElemento + sizeof(size_t) > TAM_PILA - pp->tope;
}

int verTopePila(const Pila* pp,void* elemento,size_t tamElemento)
{
    if(pp->tope==0)
    {
        return FALSO;
    }
    unsigned int tope = pp->tope;
    tope-= sizeof(size_t);
    size_t tamElementoApilado=*(size_t*)(pp->vPila+tope);
    tope-=tamElemento;
    memcpy(elemento,pp->vPila+tope,min(tamElemento,tamElementoApilado));
    return VERDADERO;
}
