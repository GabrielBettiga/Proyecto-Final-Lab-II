#ifndef FACTURA_H
#define FACTURA_H
#include "Fecha.h"
#include "Nafta.h"
#include "Surtidor.h"
#include "Cliente.h"
#include "Documento.h"
#include "Recibo.h"

class Factura:public Documento
{
    public:

        Factura();
        void Facturar (Cliente cli,Nafta naf,Surtidor sur);
        int CantFactura();
        void MostrarFactura();
        bool Guardar();
        bool LeerDeDisco(int pos);
        bool modificardeDisco(int pos);

        int buscarPorNumero (int num);

        void modificarSaldo (Recibo r);

        int     getNumFac (){return _NumFac;}
        int     getIDnaft (){return _IDnaft;}
        float   getPrecio (){return _Precio;}
        char*   getDescripcion () {return _Descripcion;}
        int     getIDsurtidor  (){return _IDsurtidor;}
        float   getLitros  (){return _Litros;}
        float   getTotal (){return _Total;}
        float   getSaldo (){return _Saldo;}
        bool    getPaga (){return _Paga;}

    private:
        int     _NumFac;
        int     _IDnaft;        ///CLASE NAFTA
        float   _Precio;        ///CLASE NAFTA
        char    _Descripcion [40];
        int     _IDsurtidor;    ///CLASE SURTIDOR
        float   _Litros;        ///CLASE SURTIDOR
        float   _Total;
        float   _Saldo;
        bool    _Paga;

};

#endif // FACTURA_H
