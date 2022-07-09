#ifndef RECTA_H
#define RECTA_H
#include "Punto.h"
#include <ostream>
class Recta : public Punto
{
    public:
        Punto punto2;
        Recta(Punto p1,Punto p2);
        friend Punto operator&&(Recta r1,Recta r2);
        friend std::ostream& operator<<(std::ostream& os,Recta r);
        friend double operator-(Recta r,Punto p);

    protected:

    private:
};


#endif // RECTA_H
