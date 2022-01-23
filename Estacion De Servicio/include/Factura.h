#ifndef FACTURA_H
#define FACTURA_H
#include "Fecha.h"
#include "Nafta.h"
#include "Surtidor.h"
#include "Cliente.h"

class Factura
{
    public:



        Factura();
        void Facturar (Cliente cli,Nafta naf,Surtidor sur,float litros);
        int CantFactura();
        void Mostrar();
        bool Guardar();
        bool LeerDeDisco(int pos);


        int     getNumFac (){return _NumFac;}
        Fecha   getFecha (){return _Fecha;}
        int     getIDcliente (){return _IDcliente;}
        int     getIDnaft (){return _IDnaft;}
        float   getPrecio (){return _Precio;}
        char*   getDescripcion () {return _Descripcion;}
        int     getIDsurtidor  (){return _IDsurtidor;}
        float   getLitros  (){return _Litros;}
        float   getTotal (){return _Total;}
        bool    getPaga (){return _Paga;}

        /*void    setFecha (Fecha x){}
        void    setIDcliente (int IDcliente);
        void    setIDnaft (int IDnaf);
        void    setPrecio (float P);
        void    setIDsurtidor  (int sur);
        void    setLitros  (Flo);
        void    setTotal ();
        void    setPaga ();*/

    private:
        int     _NumFac;
        Fecha   _Fecha;
        int     _IDcliente;     ///CLASE CLIENTE
        int     _IDnaft;        ///CLASE NAFTA
        float   _Precio;        ///CLASE NAFTA
        char    _Descripcion [40];
        int     _IDsurtidor;    ///CLASE SURTIDOR
        float   _Litros;        ///CLASE SURTIDOR
        float   _Total;
        bool    _Paga;

};

#endif // FACTURA_H
