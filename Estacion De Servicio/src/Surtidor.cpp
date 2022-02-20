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
    _litros = 0;

}

void Surtidor::setLitros(float litros){
    if(litros > 0){
        _litros = litros;
    }
}

int Surtidor::buscarPorID(int id){
    int pos = 0;
    while (LeerDeDisco(pos++))
    {
        if (_IDsurtidor == id)
        {
            return pos-1;
        }
    }
return -1;
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



bool Surtidor::Cargar(int IDnafta)
{
    TanqueManager aux;

    if (aux.Surtidor(IDnafta,_litros))
    {

        return true;
    }
    else
    {
        return false;
    }

}





void Surtidor::MostraCarga(bool Carga,int IDnafta)
{
    Nafta Naf;
    Naf.LeerDeDisco(Naf.BuscarID(IDnafta));

    if(Carga)
    {
        cout<< "Combustible     : "<< Naf.getnombreDeCombustible()<<endl;
        cout<< "Precio Por Litro: "<< Naf.getprecio()<<endl;
        cout<< "Litros Cargados : "<< _litros <<endl;
        cout<< "Precio Total    : " << _litros * Naf.getprecio()<<endl;
        return;

    }

    cout<<"NO CARGO"<<endl;
    system("pause");
    return;
}





void Surtidor::CombertirLitros (int IDnafta, float Pesos)
{
    Nafta Naf;

    Naf.LeerDeDisco(Naf.BuscarID(IDnafta));

    _litros = Pesos/Naf.getprecio();

}

