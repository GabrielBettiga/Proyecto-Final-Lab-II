#include <iostream>
#include <cstring>
using namespace std;

#include "Cuenta.h"

Cuenta::Cuenta()
{
    strcpy(_Nombre, "SIN DATOS");
    strcpy(_Direccion, "SIN DATOS");
    _CUIT = 0;
    _Telefono = 0;
    strcpy(_Email, "SIN DATOS");
    _Baja.fechaSinDatos();

}

string Cuenta::getNombre (){
    string nombre = _Nombre;
    return nombre;
}
string Cuenta::getDireccion(){
    string dir = _Direccion;
    return dir;
}

string Cuenta::getEmail(){
    string coreo = _Email;
    return coreo;
}

void Cuenta::setNombre(string nombre){
    strcpy(_Nombre, nombre.c_str());
}

void Cuenta::setDireccion(string direccion){
    strcpy(_Direccion, direccion.c_str());
}

void Cuenta::setCUIT (long long CUIT){
    if(CUIT > 0){
        _CUIT = CUIT;
    }
    else{
        _CUIT = -1;
    }
}

void Cuenta::setTelefono(int telefono){
    if (telefono > 0){
        _Telefono = telefono;
    }
    else{
        _Telefono = telefono;
    }
}

void Cuenta::setEmail(string coreo){
    strcpy(_Email, coreo.c_str());
}

void Cuenta::setFechaAlta(Fecha alta){
Fecha aux;

    if(alta <= aux){
        _Alta = alta;
    }
}

void Cuenta::setFechaBaja(Fecha baja){
Fecha aux;
    if(baja <= aux && _Alta<=baja){
        _Baja = baja;
    }
}

void Cuenta::cargar(){
    long long cuit;
    int tel;
    string nom;
    string dir;
    string coreo;

    cout << "NOMBRE     : ";
    cin.ignore();
    getline(cin, nom);
    cout << "DIRECCION  : ";
    getline(cin, dir);
    cout << "CUIT       : ";
    cin >> cuit;
    cout << "TELEFONO   : ";
    cin >> tel;
    cout << "COREO      : ";
    cin.ignore();
    getline(cin, coreo);

    setNombre(nom);
    setDireccion(dir);
    setCUIT(cuit);
    setTelefono(tel);
    setEmail(coreo);
    _Alta.FechaActual();
}

void Cuenta::mostrar(){
    cout << "NOMBRE     : ";
    cout << _Nombre << endl;
    cout << "DIRECCION  : ";
    cout << _Direccion << endl;
    cout << "CUIT       : ";
    cout << _CUIT << endl;
    cout << "TELEFONO   : ";
    cout << _Telefono << endl;
    cout << "COREO      : ";
    cout << _Email << endl;

}
