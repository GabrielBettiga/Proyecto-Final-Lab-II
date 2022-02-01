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

    _dia = f->tm_mday;
    _mes = f->tm_mon + 1;
    _anio = f->tm_year + 1900;
    _horas = f->tm_hour;
    _minutos = f->tm_min;

   }


///METODOS
///========================================================================================================

void Fecha::FechaActual(){
    time_t t;
    struct tm *f;
    time(&t);
    f = localtime(&t);

    _dia = f->tm_mday;
    _mes = f->tm_mon + 1;
    _anio = f->tm_year + 1900;
    _horas = f->tm_hour;
    _minutos = f->tm_min;

}

void Fecha::MostrarFecha(){
    if(_dia<10){cout<<"0"<<_dia<<"/";}
    else {cout<<_dia<<"/";}
    if(_mes<10){cout<<"0"<<_mes<<"/";}
    else {cout<<_mes<<"/";}
    if(_anio<10){cout<<"0"<<_anio<<endl;}
    else {cout<<_anio<<endl;}

}

void Fecha::MostrarHora(){
    if(_horas<10){cout<<"0"<<_horas<<":";}
    else {cout<<_horas<<":";}
    if(_minutos<10){cout<<"0"<<_minutos<<endl;}
    else {cout<<_minutos<<endl;}
}


bool Fecha::operator <= (Fecha aux){
    if(_anio <= aux._anio){
        if(_mes <= aux._mes){
            if(_dia <= aux._dia){
                return true;
            }
            return false;
        }
        return false;
    }
    return false;
}

void Fecha::fechaSinDatos(){
    _dia = _mes = _anio = _horas = _minutos = 0;
}

bool Fecha::cambiarFecha(int dia, int mes, int anio){
    if(esCorrecta(dia,mes,anio)){
        _dia = dia;
        _mes = mes;
        _anio = anio;
        return true;
    }
    else {
        _dia = _mes = _anio = 0;
        return false;
    }
}

bool esCorrecta(int d, int m, int a){
    unsigned int arrayDiasMes[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
    if(a==0) return false;
    if(d<=0||d>31) return false;
    if(m<=0||m>12) return false;
    if(m==2 && d>29) return false;
    if(arrayDiasMes[m-1]<d) return false;
    if(m==2 && d==29 && !esBisiesto(a)) return false;
    return true;

}
bool esBisiesto(int a){
    if ((a%4==0)||(a%400==0)&&(a%100!=0)) return true;
    else return false;
}
