#ifndef CADENA_H
#define CADENA_H


class Cadena
{
    private:
        char* cadena;
    public:
        Cadena();
        Cadena(const char* cadena);
        ~Cadena();
        Cadena(const Cadena& other);
        Cadena& operator=(const Cadena& other);
        Cadena operator+(const Cadena& other) const;
    protected:


};

#endif // CADENA_H
