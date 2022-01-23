#ifndef GESTIONTANQUES_H
#define GESTIONTANQUES_H
#include "Tanque.h"

class TanqueManager
{
    public:
        ///LOGICA
        ///=================
        void CrearTanque();
        int CantTanques();

        bool CargarTanques(int IDNafta, float litros);
        float DisponibleAllenarxNafta(int IDNafta);
        void DistribuirNaftaTanques(int IDNafta, float litros);

        bool Surtidor (int IDNafta, float litros);
        float DisponiblexCombustible(int IDNafta);
        void AcomodarTanque (int IDNafta,float litros);

        int BuscarIDtanque (int IDTanque);

        ///USUARIO
        ///=================
        void Cargar();
        void Mostrar();

        bool Guardar();
        bool leerdeDisco(int pos);
        bool modificardeDisco(int pos);


    protected:

    private:
        Tanque _aux;
};

#endif // GESTIONTANQUES_H
