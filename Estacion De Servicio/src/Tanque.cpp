#include <iostream>
using namespace std;

#include "Tanque.h"

Tanque::Tanque()
{
    _IDTanque = 0;
    _IDnafta = 0;
    _capacidadMaxima = 0;
    _ocupacion = 0;
    _disponible = 0;

}
///GETS
///=================================================================================
int Tanque::getIDtanque(){
    return _IDTanque;
}
int Tanque::getIDnafta(){
    return _IDnafta;
}
float Tanque::getCapacidad(){
    return _capacidadMaxima;
}
float Tanque::getOcupacion(){
    return _ocupacion;
}
float Tanque::getDisponible(){
    return _disponible;
}
///SETS
///=================================================================================

void Tanque::setID(int IDtanque){
    _IDTanque = IDtanque;
}
void Tanque::setIDnafta(int IDnafta){
    _IDnafta = IDnafta;
}
void Tanque::setCapacidadMaxima(float litros){
    if(litros >= 0){
        _capacidadMaxima = litros;
    }
    else {
        _capacidadMaxima = 0;
    }
}
void Tanque::setOcupacion(float litros){
    if(litros >= 0 && _capacidadMaxima > litros){
        _ocupacion = litros;
    }
    else {
        _ocupacion = 0;
    }
}
void Tanque::setDisponible(float x){
    _disponible = x;
}
///METODOS
///=================================================================================

bool Tanque::operator == (int IDNfta){
    if( _IDnafta == IDNfta){
        return true;
    }
    else {
        return false;
    }
}

bool Tanque::operator < (Tanque aux){
    if(_IDTanque < aux._IDTanque){
        if(_IDnafta == aux._IDnafta){
            return true;
        }
    }
    return false;
}

bool Tanque::DescontarLitros(float litros){
    if(litros > 0 && _ocupacion >= litros){
        _ocupacion -= litros;
        _disponible = _capacidadMaxima - _ocupacion;
        return true;
    }
    else {
        return false;
    }
}
bool Tanque::Llenar(float litros){
    if(litros > 0 && _disponible >= litros){
        _ocupacion += litros;
        _disponible = _capacidadMaxima - _ocupacion;
        return true;
    }
    else {
        return false;
    }
}

float Tanque::VaciarTodo(){
    float aux;
    aux = _ocupacion;
    _ocupacion = 0;
    _disponible = _capacidadMaxima;
    return aux;
}

