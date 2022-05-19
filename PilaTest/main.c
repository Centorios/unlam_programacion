#include <stdio.h>
#include <stdlib.h>
#include "../pila.h"
#define TAM_RES 2001
#define aBin(n) (n - '0')
#define aChar(n) (n + '0')

int apilarCeros(Pila* pp, unsigned cantCeros);
int apilarNumero(Pila *pp, const char* numero);
int desapilarNumero(Pila *pp,char* numero,size_t tamNumero);
a
int main(int argc,const char* argv[])
{
    Pila p1,p2,pr;
    crearPila(&p1);
    crearPila(&p2);
    crearPila(&pr);

    int cantDigitosN1 = strlen(argv[1]);
    int cantDigitosN2 = strlen(argv[2]);

    int difDig = cantDigitosN1 - cantDigitosN2;


    if(!apilarCeros((difDig < 0 ? &p1 : &p2), abs(difDig)))
    {
        puts("no hay memoria");
        return ERR_PILA_LLENA;
    }

    if(!apilarNumero(&p1,argv[1]) || !apilarNumero(&p2,argv[2]))
    {
        puts("no hay memoria");
        return ERR_PILA_LLENA;
    }


    int dr, ac=0;
    char d1c,d2c,drc,ac1='1';


    while(!pilaVacia(&p1))
    {
        desapilar(&p1,&d1c,sizeof(char));
        desapilar(&p2,&d2c,sizeof(char));

        dr = aBin(d1c) + aBin(d2c) + ac;
        //ac = dr >= 10? 1:0;
        ac = dr / 10;
        drc = aChar(dr % 10);
        if(!apilar(&pr,&drc,sizeof(char)))
        {
            return ERR_PILA_LLENA;
        }
    }

    if(ac > 0)
        if(!apilar(&pr,&ac1,sizeof(char)))
            return ERR_PILA_LLENA;



    char numeroRes[TAM_RES];

    if(desapilarNumero(&pr,numeroRes,TAM_RES))
        return ERR_PILA_LLENA;

    puts(numeroRes);

    return 0;

}




int apilarCeros(Pila* pp, unsigned cantCeros)
{
    char cero = '0';
    unsigned int i;

    for(i=0; i<cantCeros; i++)
    {
        if(!apilar(pp,&cero,sizeof(char)))
            return FALSO;
    }

    return VERDADERO;
}



int apilarNumero(Pila *pp ,const char* numero)
{
    const char* i = numero;
    while(*i)
    {
        if(!apilar(pp,i,sizeof(char)))
            return FALSO;
        i++;
    }

    return VERDADERO;

}


int desapilarNumero(Pila *pp,char* numero,size_t tamNumero)
{
    char* carAct = numero;
    char* ultCar = numero+ tamNumero -1;
    while(!pilaVacia(pp) && (carAct < ultCar))
    {
        desapilar(pp,carAct,sizeof(char));
        carAct++;
    }

    if(pilaVacia(pp))
    {
        return FALSO;
    }

    *carAct = '\0';

    return VERDADERO;
}

