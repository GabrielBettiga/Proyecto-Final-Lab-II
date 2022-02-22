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
    _IDNafta = 0;

}
void Surtidor::setIDsurtidor(int ID){
    _IDsurtidor = ID;
}

void Surtidor::setLitros(float litros){
    if(litros > 0){
        _litros = litros;
    }
}

void Surtidor::setNafta(Nafta naf){
    _IDNafta = naf.getIDtipoDeNafta();
}

Nafta Surtidor::getNafta(){
    Nafta aux;
    aux.LeerDeDisco(aux.BuscarID(_IDNafta));
    return aux;
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



bool Surtidor::Cargar()
{
    TanqueManager aux;

    if (aux.Surtidor(_IDNafta,_litros))
    {
        return true;
    }
    else
    {
        return false;
    }

}

void Surtidor::MostraCarga(){

    cout << " COMBUSTIBLE : "<< getNafta().getnombreDeCombustible() <<endl;
    cout << " PRECIO : "<< getNafta().getprecio() <<endl;
    cout << " LITROS : "<< _litros <<endl;
    cout << " ================== " << endl;
    cout << " TOTAL  : " << _litros * getNafta().getprecio() <<endl;
}

void Surtidor::CombertirLitros (float Pesos){

    _litros = Pesos/getNafta().getIDtipoDeNafta();

}

