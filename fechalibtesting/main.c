#include <stdio.h>
#include <stdlib.h>
#include "../fechaslib/fechastruct.h"

int main()
{
    Fecha fecha1,fecha2;
    InputYear(&fecha1);
    InputMonth(&fecha1);
    InputDay(&fecha1);
    InputYear(&fecha2);
    InputMonth(&fecha2);
    InputDay(&fecha2);
    showFecha(&fecha1);
    showFecha(&fecha2);
    dateDifferenceInDays(&fecha1,&fecha2);

    return 0;
}
