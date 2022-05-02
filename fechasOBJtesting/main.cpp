#include <iostream>
#include "../fechalibOBJ/fecha.h"

using namespace std;
using namespace fecha;

int main()
{
    Fecha fecha1(1, 1, 2000);
    Fecha fecha2(25, 12, 2020);
    Fecha fecha3(1, 1, 2000);
    Fecha* fecha4 = new Fecha(1, 1, 2000);
    Fecha fecha3;

    int dif = fecha1.difEnDias(&fecha2);
    int dif2 = fecha1 - &fecha2; // el objeto de la izquierda es el objeto "llamador"

    Fecha fsuma = fecha1.sumarDias(60);
    cout << dif2 << endl;
    cout << dif << endl;

    return 0;
}
