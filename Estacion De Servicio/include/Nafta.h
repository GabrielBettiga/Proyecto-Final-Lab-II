#ifndef NAFTA_H
#define NAFTA_H
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;


class Nafta
{
private:
    int _IDtipoDeNafta;
    char _nombreDeCombustible[40];
    float _precio;



public:
    Nafta(int IDtipoDeNafta = 0, const char *nombreDeCombustible = "-", float precio = 0 );

    int getIDtipoDeNafta ()
    {
        return _IDtipoDeNafta;
    }
    void setIDtipoDeNafta (int x)
    {
        int pos=0;
        while (LeerDeDisco(pos))
        {
            if(x!= _IDtipoDeNafta)
            {
                _IDtipoDeNafta=x;
            }
        }
    }

    char* getnombreDeCombustible ()
    {
        return _nombreDeCombustible;
    }
    void setnombreDeCombustible (char *x)
    {
        strcpy(_nombreDeCombustible,x);
    }

    float getprecio ()
    {
        return _precio;
    }
    void setprecio(int x)
    {
        if(x>0)
        {
            _precio=x;
        }
        else
        {
            _precio=0;
        }
    }



    void Cargar ();
    void Mostrar ();

    bool GrabarEnDisco ();
    bool LeerDeDisco (int pos);
    bool ModificarEnDisco (int pos);

    int BuscarID(int NuevaID);
    int CantCombustible();

};

#endif // NAFTA_H
