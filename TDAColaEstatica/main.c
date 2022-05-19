#include "./cola.h"
void encolarSegmentado(Cola* pc,const void* dato,size_t tamDato);
void desEncolarSegmentado(Cola* pc, void* dato,size_t tamDato,size_t tamDatoEncolado);
void verFrenteSegmentado(const Cola* pc, void* dato,size_t tamDato,size_t tamDatoEncolado);

void crearCola(Cola* pc)
{
    pc->frente = pc->fondo = 0;
    pc->tamDisponible = TAM_COLA;
}


int encolar(Cola* pc, const void* elemento,size_t tamElemento)
{
    if(tamElemento + sizeof(size_t) > pc->tamDisponible)
        return FALSO;

    encolarSegmentado(pc,&tamElemento,sizeof(size_t));

//  memcpy(pc->vCola + pc->fondo, &tamElemento,sizeof(size_t));
//  pc->fondo+=sizeof(size_t)

    encolarSegmentado(pc,elemento,tamElemento);

//  memcpy(pc->vCola + pc->fondo, elemento,tamElemento);
//  pc->fondo+=tamElemento;


    return VERDADERO;
}



int desEncolar(Cola* pc, void* elemento,size_t tamElemento)
{
    if(pc->tamDisponible == TAM_COLA)
        return FALSO;


    size_t tamElemEncolado;

    desEncolarSegmentado(pc,&tamElemEncolado,sizeof(size_t),sizeof(size_t));
    desEncolarSegmentado(pc,elemento,tamElemento,tamElemEncolado);

    return VERDADERO;
}



int verFrenteDeCola(Cola* pc,void* elemento,size_t tamElemento)
{
    if(pc->tamDisponible == TAM_COLA)
        return FALSO;

    size_t tamElemEncolado;

    unsigned frente = pc->frente;

    desEncolarSegmentado(pc,&tamElemEncolado,sizeof(size_t),sizeof(size_t));
    verFrenteSegmentado(pc,&tamElemEncolado,tamElemento,tamElemEncolado);
    pc->frente = frente;

    return VERDADERO;
}



int colaVacia(Cola* pc)
{
    return pc->tamDisponible == TAM_COLA;
}



int colaLlena(const Cola* pc,size_t tamElemento)
{
    return tamElemento + sizeof(size_t) > pc->tamDisponible;
}



void vaciarCola(Cola* pc)
{
    pc->frente = pc->fondo = 0;
    pc->tamDisponible = TAM_COLA;
}


void encolarSegmentado(Cola* pc,const void* dato,size_t tamDato)
{
    size_t tamDisponibleContiguo;
    size_t cantACopiar1, cantACopiar2;

    tamDisponibleContiguo = pc->frente > pc->fondo? pc->tamDisponible : TAM_COLA-pc->fondo;

    cantACopiar1 = min(tamDato,tamDisponibleContiguo);
    cantACopiar2 = tamDato - cantACopiar1;

    memcpy(pc->vCola +   pc->fondo,dato,cantACopiar1);
    pc->fondo = (pc->fondo + cantACopiar1) % TAM_COLA;

    if(cantACopiar2 > 0)
    {
        memcpy(pc->vCola + pc->fondo,dato+cantACopiar1,cantACopiar2);
        pc->fondo += cantACopiar2;
    }
    pc->tamDisponible -= tamDato;

}


void desEncolarSegmentado(Cola* pc, void* dato,size_t tamDato,size_t tamDatoEncolado)
{
    size_t cantACopiarTotal,cantACopiar1,cantACopiar2;
    size_t tamDatoContiguo;

    cantACopiarTotal=min(tamDato,tamDatoEncolado);

    tamDatoContiguo = pc->frente > pc->fondo? min(tamDatoEncolado,TAM_COLA - pc->frente) : tamDatoEncolado;

    cantACopiar1 = min(tamDatoContiguo,cantACopiarTotal);
    cantACopiar2 = cantACopiarTotal - cantACopiar1;

    memcpy(dato,pc->vCola + pc->frente,cantACopiar1);
    pc->frente = (pc->frente +tamDatoContiguo) % TAM_COLA;


    if(cantACopiar2 > 0)
        memcpy(dato + cantACopiar1, pc->vCola, cantACopiar2);


    pc->frente += tamDatoEncolado - tamDatoContiguo;

    pc->tamDisponible += tamDatoEncolado;

}


void verFrenteSegmentado(const Cola* pc, void* dato,size_t tamDato,size_t tamDatoEncolado)
{
    size_t cantACopiarTotal,cantACopiar1,cantACopiar2;
    size_t tamDatoContiguo;
    unsigned frente = pc->frente;

    cantACopiarTotal=min(tamDato,tamDatoEncolado);

    tamDatoContiguo = frente > pc->fondo? min(tamDatoEncolado,TAM_COLA - frente) : tamDatoEncolado;

    cantACopiar1 = min(tamDatoContiguo,cantACopiarTotal);
    cantACopiar2 = cantACopiarTotal - cantACopiar1;

    memcpy(dato,pc->vCola + frente,cantACopiar1);

    if(cantACopiar2 > 0)
        memcpy(dato + cantACopiar1, pc->vCola, cantACopiar2);
}



