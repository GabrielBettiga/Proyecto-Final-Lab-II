#ifndef SURTIDOR_H
#define SURTIDOR_H
#include "Fecha.h"


class Surtidor
{
private:
    int _IDsurtidor;
    float _litros;

public:
    Surtidor(int IDsurtidor = 0);
    void setLitros(float litros);

    float getLitros(){return _litros;}



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
    void CrearSurtidor ();
    void MostraCarga(bool Carga,int IDnafta);
    bool Cargar(int IDnafta);
    void CombertirLitros (int IDnafta, float Pesos);

    int buscarPorID(int id);

    bool crearArchivo();
    bool GrabarEnDisco ();
    bool LeerDeDisco (int pos);
    bool ModificarEnDisco (int pos);


};





#endif // SURTIDOR_H
