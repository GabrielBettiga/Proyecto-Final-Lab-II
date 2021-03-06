#ifndef RECIBO_H
#define RECIBO_H

#include "Documento.h"
#include "Cliente.h"

class Recibo:public Documento
{
    public:

        Recibo();
        void cargarRecibo(Cliente cli, int *fac, float *impo, float pago);
        void cargarRecibo(int numFac);
        void mostrarRecibo();

        int CantRecibo();

        void setSaldo(float x){_saldoRecibo = 0;}
        void setEstado(bool x){_cerrado = x;}

        bool Guardar();
        bool leerdeDisco(int pos);
        bool modificardeDisco(int pos);

        int getTam(){return _TAMFAC;}
        int getNumRecibo(){return _numRecibo;}
        int * getNumFactura(){return _numFactura;}
        float * getImportePago(){return _importePagado;}
        float getSaldoRecibo(){return _saldoRecibo;}
        float getTotal(){return _total;}
        bool getEstadoRecibo(){return _cerrado;}

    protected:

    private:
        int     _numRecibo;
        static const int _TAMFAC = 5;       //MANEJA LA CANTIDAD DE FACTURAS Q PUEDE MANEJAR EL RECIBO/SE EXTIENDE A TODA LA CLASE
        int     _numFactura[_TAMFAC];
        float   _importePagado[_TAMFAC];
        float   _saldoRecibo;
        float   _total;
        bool    _cerrado;
};

#endif // RECIBO_H
