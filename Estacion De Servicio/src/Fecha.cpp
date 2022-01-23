#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;
#include "Fecha.h"


///CONSTRUCTOR
///========================================================================================================

Fecha::Fecha (int Dia,int Mes,int Anio,int Horas, int Minutos){

   _Dia=Dia;
   _Mes=Mes;
   _Anio=Anio;
   _Horas=Horas;
   _Minutos=Minutos;

   }


///METODOS
///========================================================================================================
   void Fecha::Cargar (){
   cout<< "Dia: ";
   cin>> _Dia;
   cout<<"Mes: ";
   cin>>_Mes;
   cout<<"Anio: ";
   cin>>_Anio;
   cout << "Hora: ";
   cin >> _Horas;
   cout << "Minutos: ";
   cin >> _Minutos;
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
