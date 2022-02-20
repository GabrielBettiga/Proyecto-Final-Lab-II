#ifndef CLIENTE_H
#define CLIENTE_H
#include <Cuenta.h>

class Cliente:public Cuenta
{
    public:

        Cliente();

        int getID();
        bool getCuentaCorriente();
        float getLimiteCredito();
        bool getEstadoCliente();

        void setID(int id);
        void setCuentaCorriente(bool x);
        void setLimiteCredito(float limite);
        void setEstadoCliete(bool activo);

        void cargarCliente();
        bool confirmarCtaCte();
        void mostrarCliente();
        int cantClientes();
        int BuscarIDCliente (int ID);
        int buscarClientexCUIT (int cuit);
        void modificarDatoCliente();

        bool crearArchivo();
        bool Guardar();
        bool leerdeDisco(int pos);
        bool modificardeDisco(int pos);

    protected:

    private:
        int     _ID;
        bool    _cuentaCorriente;
        float   _limiteCred;
        bool    _activo;
};

#endif // CLIENTE_H
