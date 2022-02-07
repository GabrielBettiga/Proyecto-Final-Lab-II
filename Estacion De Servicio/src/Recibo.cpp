#include <iostream>
using namespace std;

#include "Recibo.h"

Recibo::Recibo()
{
    setTipoDocumento ('R');

    _numRecibo = 0;

    for(int i=0; i<_TAMFAC; i++){
        _numFactura[i] = 0;
        _importePagado [i] = 0;
    }

    _saldoRecibo = 0;
    _cerrado = false;
}

void Recibo::mostrarRecibo(){

    Documento::mostrarDocumento();

    cout << "NUMERO RECIBO: ";
    cout << _numRecibo << endl;
    for(int i=0; i < _TAMFAC; i++){
        cout << "FACTUR " << i+1 << " : ";
        cout << _numFactura[i] << endl;
        }
    cout << "IMPORTE PAGADO: " << endl;
    for(int i=0; i < _TAMFAC; i++){
        cout << "FACTUR P " << i+1 << " : ";
        cout << _importePagado[i] << endl;
        }

    cout << "SALDO RECIBO : ";
    cout << _saldoRecibo << endl;
    cout << "ESTADO: ";
    if(_cerrado == true){
        cout << "CERRADO. " << endl;
    }
    else {
        cout << "ABIERTO. " << endl;
    }
}

bool Recibo::Guardar(){
    FILE *p;
    p = fopen("Recibos.dat", "ab");                  ///ABRE EL ARCHIVO DESDE EL FINAL, SI NO EXISTE LO CREA.

    if(p == NULL){
        return false;
    }

    if(fwrite(this, sizeof(Recibo), 1, p)){         ///ESCRIBE EL ARCHIVO.
        fclose(p);
        return true;                                ///SI SE GUARDA CONFIRMA /// el mensaje fuera de la clase
    }
    else{
        fclose(p);
        return false;                               ///SI NO SE GUARDA NIEGA /// el mensaje fuera de la clase
    }
}

bool Recibo::leerdeDisco(int pos){
    FILE *p;
    p = fopen("Recibos.dat","rb");                   ///abre el archivo desde el byte 0.

    if (p == NULL){
        return false;
    }

    fseek(p, sizeof(Recibo)*pos, SEEK_SET);         ///posiciona el PUNTEOR / CABEZAL en la direcion que se le mando.

    if(fread(this, sizeof(Recibo), 1, p)){
        fclose(p);
        return true;                                ///SI SE ABRE CONFIRMA /// el mensaje fuera de la clase
    }
    else{
        fclose(p);
        return false;                               ///SI NO SE ABRE NIEGA /// el mensaje fuera de la clase
    }
}

bool Recibo::modificardeDisco(int pos){
    FILE *p;
    p = fopen("Recibos.dat","rb+");                   ///ABRE EL ARCHIVO DESDE 0 Y PUEDE ESCRIBIR Y MODIFICAR.

    if (p == NULL){
        return false;
    }

    fseek(p, sizeof(Recibo)*pos, SEEK_SET);         ///posiciona el PUNTEOR / CABEZAL en la direcion que se le mando.

    if(fwrite(this, sizeof(Recibo), 1, p)){
        fclose(p);
        return true;                                ///SI SE ABRE CONFIRMA /// el mensaje fuera de la clase
    }
    else{
        fclose(p);
        return false;                               ///SI NO SE ABRE NIEGA /// el mensaje fuera de la clase
    }
}
