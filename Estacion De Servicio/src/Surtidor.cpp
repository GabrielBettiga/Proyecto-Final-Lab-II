#include "Surtidor.h"
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;
#include "Fecha.h"
#include "TanqueManager.h"
#include "Nafta.h"


///COSTRUCTOR
///========================================================================================================

Surtidor::Surtidor(int IDsurtidor)
{
    _IDsurtidor=IDsurtidor;

}


///DISCO
///========================================================================================================
bool Surtidor::crearArchivo(){
    FILE *p;
    bool Escribio;

    p=fopen("Surtidores.dat","wb");
    if (p==NULL)
    {
        cout<<"NO SE PUDO ABRIR/CREAR EL ARCHIVO"<<endl;
        return false;
    }

    Escribio=fwrite(this,sizeof(Surtidor),1,p);

    fclose (p);

    return Escribio;

}

bool Surtidor::GrabarEnDisco()
{
    FILE *p;
    bool Escribio;

    p=fopen("Surtidores.dat","ab");
    if (p==NULL)
    {
        cout<<"NO SE PUDO ABRIR/CREAR EL ARCHIVO"<<endl;
        return false;
    }

    Escribio=fwrite(this,sizeof(Surtidor),1,p);

    fclose (p);

    return Escribio;

}

bool Surtidor::LeerDeDisco(int pos)
{
    FILE *p;
    bool Leyo;

    p=fopen("Surtidores.dat","rb");

    if (p==NULL)
    {
        return false;
    }


    fseek (p,sizeof(Surtidor)*pos,0);

    Leyo=fread(this,sizeof(Surtidor),1,p);

    fclose(p);

    return Leyo;

}

bool Surtidor::ModificarEnDisco(int pos)
{
    FILE *p;
    bool Modifico;

    p=fopen("Surtidores.dat","rb+");
    if (p==NULL)
    {
        cout<<"NO SE PUDO ABRIR/CREAR EL ARCHIVO"<<endl;
        return false;
    }

    fseek(p,sizeof(Surtidor)*pos,0);

    Modifico=fwrite(this,sizeof(Surtidor),1,p);

    fclose (p);

    return Modifico;

}


///METODOS
///========================================================================================================



void Surtidor::CrearSurtidor ()
{

    setIDsurtidor (CantSurtidor()+1);

}

int Surtidor::CantSurtidor()
{
    int bytes, cant;

    FILE *p;
    p = fopen("Surtidores.dat", "rb");

    if (p == NULL)
    {
        return 0;
    }

    fseek(p, 0, SEEK_END);///Lo posiciona en el final
    bytes = ftell(p);
    fclose(p);
    cant = bytes / sizeof(Surtidor);
    return cant;
}



bool Surtidor::Cargar(int IDnafta, float Litros)
{
    TanqueManager aux;

    if (aux.Surtidor(IDnafta,Litros))
    {

        return true;
    }
    else
    {
        return false;
    }

}





void Surtidor::MostraCarga(bool Carga,int IDnafta, float Litros)
{
    Nafta Naf;
    Naf.LeerDeDisco(Naf.BuscarID(IDnafta));

    if(Carga)
    {
        cout<< "Combustible     : "<< Naf.getnombreDeCombustible()<<endl;
        cout<< "Precio Por Litro: "<< Naf.getprecio()<<endl;
        cout<< "Litros Cargados : "<<Litros<<endl;
        cout<< "Precio Total    : " << Litros*Naf.getprecio()<<endl;
        return;

    }

    cout<<"NO CARGO"<<endl;
    system("pause");
    return;
}





float Surtidor::CombertirLitros (int IDnafta, float Pesos)
{
    Nafta Naf;

    Naf.LeerDeDisco(Naf.BuscarID(IDnafta));

    return Pesos/Naf.getprecio();

}

