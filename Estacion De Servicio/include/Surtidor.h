#ifndef SURTIDOR_H
#define SURTIDOR_H
#include "Fecha.h"
#include "Nafta.h"


class Surtidor
{
private:
    int _IDsurtidor;
    float _litros;
    int _IDNafta;

public:
    Surtidor(int IDsurtidor = 0);

    void setIDsurtidor(int ID);
    void setLitros(float litros);
    void setNafta(Nafta naf);

    int getIDsurtidor (){return _IDsurtidor;}
    float getLitros(){return _litros;}
    Nafta getNafta();

///METODOS
    int CantSurtidor();
    void CrearSurtidor ();
    void MostraCarga();
    bool Cargar();
    void CombertirLitros (float importe);

    int buscarPorID(int id);

    bool crearArchivo();
    bool GrabarEnDisco ();
    bool LeerDeDisco (int pos);
    bool ModificarEnDisco (int pos);

};





#endif // SURTIDOR_H
