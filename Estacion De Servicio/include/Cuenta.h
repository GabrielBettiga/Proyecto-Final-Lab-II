#ifndef CUENTA_H
#define CUENTA_H
#include "Fecha.h"

class Cuenta
{
    public:
        Cuenta();

        string getNombre();
        string getDireccion();
        int getCUIT(){return _CUIT;}
        int getTelefono(){return _Telefono;}
        string getEmail();
        Fecha getFechaAlta(){return _Alta;}
        Fecha getFechaBaja(){return _Baja;}

        void setNombre(string nombre);
        void setDireccion(string direccion);
        void setCUIT (int CUIT);
        void setTelefono(int telefono);
        void setEmail(string coreo);
        void setFechaAlta(Fecha alta);
        void setFechaBaja(Fecha baja);

        void cargar();
        void mostrar();

    protected:
        char    _Nombre[50];        ///nombre o razon soial
        char	_Direccion[50];
        int     _CUIT;              ///ver si pasa a char o long long consultar
        int 	_Telefono;          ///ver si pasa a char
        char    _Email[50];
        Fecha	_Alta;
        Fecha	_Baja;

    private:
};

#endif // CUENTA_H
