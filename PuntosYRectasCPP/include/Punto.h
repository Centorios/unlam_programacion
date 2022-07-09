#ifndef PUNTO_H
#define PUNTO_H
#include <ostream>

class Punto
{
public:

    Punto(double x, double y);
    Punto();
    double x;
    double y;
    friend std::ostream& operator<<(std::ostream& os,Punto p);
protected:

private:
};

#endif // PUNTO_H
