#include <iostream>
#include <ctime>

using namespace std;
#include "Fecha.h"


///CONSTRUCTOR
///========================================================================================================

Fecha::Fecha (){

    time_t t;
    struct tm *f;
    time(&t);
    f = localtime(&t);

    _Dia = f->tm_mday;
    _Mes = f->tm_mon + 1;
    _Anio = f->tm_year + 1900;
    _Horas = f->tm_hour;
    _Minutos = f->tm_min;

   }


///METODOS
///========================================================================================================

void Fecha::FechaActual(){
    time_t t;
    struct tm *f;
    time(&t);
    f = localtime(&t);

    _Dia = f->tm_mday;
    _Mes = f->tm_mon + 1;
    _Anio = f->tm_year + 1900;
    _Horas = f->tm_hour;
    _Minutos = f->tm_min;

}

   void Fecha::Mostrar (){
    if(_Dia<10){cout<<"0"<<_Dia<<"/";}
    else {cout<<_Dia<<"/";}
    if(_Mes<10){cout<<"0"<<_Mes<<"/";}
    else {cout<<_Mes<<"/";}
    if(_Anio<10){cout<<"0"<<_Anio<<endl;}
    else {cout<<_Anio<<endl;}

    if(_Horas<10){cout<<"0"<<_Horas<<":";}
    else {cout<<_Horas<<":";}
    if(_Minutos<10){cout<<"0"<<_Minutos<<endl;}
    else {cout<<_Minutos<<endl;}
}

bool Fecha::operator < (Fecha aux){
    if(_Anio < aux._Anio){
        if(_Mes < aux._Mes){
            if(_Dia < aux._Dia){
                return true;
            }
            return false;
        }
        return false;
    }
    return false;
}

void Fecha::fechaSinDatos(){
    _Dia = _Mes = _Anio = _Horas = _Minutos = 0;
}
