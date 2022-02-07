#ifndef RECIBO_H
#define RECIBO_H

#include "Documento.h"

class Recibo:public Documento
{
    public:

        Recibo();
        void mostrarRecibo();

        bool Guardar();
        bool leerdeDisco(int pos);
        bool modificardeDisco(int pos);

        int getTam(){return _TAMFAC;}
        int getNumRecibo(){return _numRecibo;}
        int * getNumFactura(){return _numFactura;}
        float * getImportePago(){return _importePagado;}
        float getSaldoRecibo(){return _saldoRecibo;}
        bool getEstadoRecibo(){return _cerrado;}

    protected:

    private:
        int     _numRecibo;
        static const int _TAMFAC = 5;       //MANEJA LA CANTIDAD DE FACTURAS Q PUEDE MANEJAR EL RECIBO/SE EXTIENDE A TODA LA CLASE
        int     _numFactura[_TAMFAC];
        float   _importePagado[_TAMFAC];
        float   _saldoRecibo;
        bool    _cerrado;
};

#endif // RECIBO_H
