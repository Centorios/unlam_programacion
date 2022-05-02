#include <stdio.h>
#include <stdlib.h>
#include "truncate.h"
int main()
{
    float x;
    int decimals;
    printf("INgrese un numero con coma:");
    fflush(stdin);
    scanf("%f",&x);
    printf("ingrese el numero de decimales a mantener:");
    fflush(stdin);
    scanf("%d",&decimals);
    x=truncate(x,decimals);
    printf("el numero truncado es: %f",x);
    return 0;
}
