#ifndef TANQUE_H
#define TANQUE_H


class Tanque
{
    public:
        Tanque();

        int getIDtanque();
        int getIDnafta();
        float getCapacidad();
        float getOcupacion();
        float getDisponible();

        void setID(int IDtanque);
        void setIDnafta(int IDnafta);
        void setCapacidadMaxima(float litros);
        void setOcupacion(float litros);
        void setDisponible(float x);

        bool operator == (int IDNfta);
        bool operator < (Tanque aux);

        bool DescontarLitros(float litros);
        bool Llenar(float litros);
        float VaciarTodo();

    protected:

    private:
        int     _IDTanque;
        int     _IDnafta;
        float   _capacidadMaxima;
        float   _ocupacion;
        float   _disponible;

};

#endif // TANQUE_H
