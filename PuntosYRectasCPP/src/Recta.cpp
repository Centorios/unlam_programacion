#include "Recta.h"
#include "Punto.h"
#include <stdlib.h>
#include <cmath>

Recta::Recta(Punto p1, Punto p2)
{
    this->x = p1.x;
    this->y = p1.y;
    this->punto2.x = p2.x;
    this->punto2.y = p2.y;
}


Punto operator&&(Recta r1,Recta r2)
{
    double resX=((r1.x*r1.punto2.y-r1.y*r1.punto2.x)*(r2.x-r2.punto2.x) - (r1.x - r1.punto2.x)*(r2.x*r2.punto2.y - r2.y*r2.punto2.x)   )/((r1.x-r1.punto2.x)*(r2.y - r2.punto2.y)-(r1.y - r1.punto2.y)*(r2.x - r2.punto2.x));
    double resY=((r1.x*r1.punto2.y - r1.y*r1.punto2.x)*(r2.y-r2.punto2.y)-(r1.y-r1.punto2.y)*(r2.x*r2.punto2.y - r2.y*r2.punto2.x))/((r1.x-r1.punto2.x)*(r2.y - r2.punto2.y)-(r1.y - r1.punto2.y)*(r2.x - r2.punto2.x));
    return Punto(resX,resY);
}

double operator-(Recta r,Punto p)
{
    double numerador = abs(((r.punto2.y-r.y)*p.x)-((r.punto2.x-r.x)*p.y)+(r.punto2.x*r.y)-(r.punto2.y*r.x));
    double denominador = sqrt((r.punto2.y-r.y)*(r.punto2.y-r.y)+(r.punto2.x-r.x)*(r.punto2.x-r.x));
    return numerador/denominador;
}


std::ostream& operator<<(std::ostream& os,Recta r)
{
    return os << "[" << r.x << ";" << r.y << "]" << "[" << r.punto2.x << ";" << r.punto2.y << "]";
}
