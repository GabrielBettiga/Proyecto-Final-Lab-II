#include <iostream>
using namespace std;

#include "Documento.h"

Documento::Documento()
{
    _IDCliente = 0;
    _Fecha.fechaSinDatos();
    _TipoDoc = 'X';
}

void Documento::setCliente(Cliente cliente){
    _IDCliente = cliente.getID();
}
void Documento::setFecha(Fecha fecha){
    _Fecha = fecha;
}
void Documento::setTipoDocumento(char tipo){
    _TipoDoc = tipo;
}

void Documento::mostrarDocumento(){
    cout << "CLIENTE    : ";
    cout << _IDCliente << endl;
    cout << "FECHA      : ";
    _Fecha.MostrarFecha();
}
