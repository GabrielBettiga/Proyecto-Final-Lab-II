#ifndef DOCUMENTO_H
#define DOCUMENTO_H
#include "Fecha.h"
#include "Cliente.h"

class Documento
{
    public:
        Documento();

        void setCliente(Cliente cliente);
        void setFecha(Fecha fecha);
        void setTipoDocumento(char tipo);

        int getCliente(){return _IDCliente;}
        Fecha getFecha(){return _Fecha;}
        char getTipoDocumento(){return _TipoDoc;}

        void mostrar();

    protected:
        int     _IDCliente;
        Fecha   _Fecha;
        char    _TipoDoc;

    private:
};

#endif // DOCUMENTO_H
