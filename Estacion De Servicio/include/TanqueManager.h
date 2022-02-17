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
        float DisponibleAllenarxNafta(int IDNafta);             /// CAPACIDAD A GUARDAD
        void DistribuirNaftaTanques(int IDNafta, float litros);

        bool Surtidor (int IDNafta, float litros);
        float DisponiblexCombustible(int IDNafta);              /// LO Q TENEMOS X COMBUSTIBLE
        void AcomodarTanque (int IDNafta,float litros);

        int BuscarIDtanque (int IDTanque);
        void setCapacidad(float litros);
        void setDisponible (float Disponible);
        void setID (int id);

        int getID ();
        float getCapacidad();
        int setIDNafta (int x);

        ///USUARIO
        ///=================
        void Cargar();
        void Mostrar();

        bool crearArchivo();
        bool Guardar();
        bool leerdeDisco(int pos);
        bool modificardeDisco(int pos);

    protected:

    private:
        Tanque _aux;
};

#endif // GESTIONTANQUES_H
