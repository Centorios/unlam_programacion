#include <stdio.h>
#include <math.h>

float truncate (float number,int decimals)
{
    float powedNumber,powed10;
    powed10=pow(10,decimals);
    powedNumber=powed10*number;
    int truncatedPowedNumber = powedNumber;
    if((powedNumber-truncatedPowedNumber >= 0.5))
    {
        return((powedNumber+1)/powed10);
    } else
    {
        return(powedNumber/powed10);
    }
}
