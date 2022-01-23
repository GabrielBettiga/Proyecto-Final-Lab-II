#ifndef CLIENTE_H
#define CLIENTE_H
#include <Cuenta.h>

class Cliente:public Cuenta
{
    public:

        int getID();
        bool getCuentaCorriente();
        float getLimiteCredito();

        void setCuentaCorriente(bool x);
        void setLimiteCredito(float limite);

        void cargar();
        bool confirmarCtaCte();
        void mostrar();

        int cantClientes();
        int BuscarIDCliente (int ID);

        bool Guardar();
        bool leerdeDisco(int pos);
        bool modificardeDisco(int pos);

    protected:

    private:
        int     _ID;
        bool    _cuentaCorriente;
        float   _limiteCred;
};

#endif // CLIENTE_H
