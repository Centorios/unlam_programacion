#include "Punto.h"

Punto::Punto(double x,double y)
{
    this->x = x;
    this->y = y;
}



std::ostream& operator<<(std::ostream& os,Punto p)
{
    return os << "(" << p.x << "," << p.y << ")";
}



Punto::Punto()
{
    this->x = 0;
    this->y = 0;
}
