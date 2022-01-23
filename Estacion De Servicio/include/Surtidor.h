#ifndef SURTIDOR_H
#define SURTIDOR_H
#include "Fecha.h"


class Surtidor
{
private:
    int _IDsurtidor;


public:
    Surtidor(int IDsurtidor = 0);



    int getIDsurtidor ()
    {
        return _IDsurtidor;
    }
    void setIDsurtidor (int x )
    {
        _IDsurtidor=x;
    }
///METODOS
    int CantSurtidor();
    void MostraCarga(bool Carga,int IDnafta, float Litros);
    bool Cargar(int IDnafta, float Litros);
    float CombertirLitros (int IDnafta, float Pesos);
    void CrearSurtidor ();
    bool GrabarEnDisco ();
    bool LeerDeDisco (int pos);
    bool ModificarEnDisco (int pos);


};





#endif // SURTIDOR_H
