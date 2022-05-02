#ifndef EMPLEADOSTRUCT_H_INCLUDED
#define EMPLEADOSTRUCT_H_INCLUDED


typedef struct{
    int dia;
    int mes;
    int anio;
}Fecha;



typedef struct{
    int dni;
    char apyn [200];
    Fecha fNacimiento;
    char sexo;
    float sueldo;
}Empleado;




#endif // EMPLEADOSTRUCT_H_INCLUDED
