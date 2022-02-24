#include <iostream>
using namespace std;

#include "Recibo.h"
#include "Factura.h"

Recibo::Recibo()
{
    setTipoDocumento ('R');

    _numRecibo = 0;

    for(int i=0; i<_TAMFAC; i++){
        _numFactura[i] = 0;
        _importePagado [i] = 0;
    }

    _saldoRecibo = 0;
    _total = 0;
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
    cout << "TOTA RECIBO : ";
    cout << _total << endl;
    cout << "SALDO RECIBO : ";
    cout << _saldoRecibo << endl;
    cout << "ESTADO: ";
    if(_cerrado == true){
        cout << "CERRADO. " << endl;
    }
    else {
        cout << "ABIERTO. " << endl;
    }
    cout << endl;
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

/// LOS VECTORES DE FACTURA Y IMPORTE SE CARGAN EN LA FUNCION ANTERIOR, ESTAN ATADOS AL TAMAÑO DEL VECTOR DEL RECIBO
/// CON EL _TAMFAC.

void Recibo::cargarRecibo(Cliente cli, int *fac, float *impo, float pago){
    int i;
    float aplicado = 0;

    setCliente(cli);
    _Fecha.FechaActual();

    _numRecibo = CantRecibo() + 1;

    for(i=0; i<_TAMFAC; i++){
        _numFactura[i] = fac [i];
        aplicado += _importePagado [i] = impo [i];
    }
    if(aplicado > pago){
        _saldoRecibo = 0;
    }
    _total = pago;
    _saldoRecibo = _total - aplicado;

    if(_saldoRecibo == 0){
        _cerrado = true;
    }

}

void Recibo::cargarRecibo(int numFac){
    Factura aux;
    Cliente cli;
    aux.buscarPorNumero(numFac);
    cli.BuscarIDCliente(aux.getCliente());

    setCliente(cli);
    _Fecha.FechaActual();
    _numRecibo = CantRecibo() + 1;
    _numFactura[0] = numFac;
    _importePagado [0] = aux.getTotal();
    _saldoRecibo = 0;
    _total = aux.getTotal();
    _cerrado = true;

}

int Recibo::CantRecibo()
{
    int bytes, cant;

    FILE *p;
    p = fopen("Recibos.dat", "rb");

    if (p == NULL)
    {
        return 0;
    }

    fseek(p, 0, SEEK_END);///Lo posiciona en el final
    bytes = ftell(p);
    fclose(p);
    cant = bytes / sizeof(Recibo);
    return cant;
}

