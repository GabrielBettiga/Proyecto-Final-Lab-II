#include <iostream>
using namespace std;
#include "Cliente.h"


int Cliente::getID(){
    return _ID;
}

bool Cliente::getCuentaCorriente(){
    return _limiteCred;
}

float Cliente::getLimiteCredito(){
    return _limiteCred;
}

void Cliente::setLimiteCredito(float limite){
    if(limite >= 0){
        _limiteCred = limite;
    }
    else {
        _limiteCred = 0;
    }
}

void Cliente::setCuentaCorriente(bool x){
    if(x){
        _cuentaCorriente = true;
    }
    else {
        _cuentaCorriente = false;
    }
}

void Cliente::cargar(){

    _ID = cantClientes()+1;
    Cuenta::cargar();
    cout << "CUENTA CORRIENTE: SI (1) / NO (2)" << endl;

    if(confirmarCtaCte()){
            float limite;

            cout << "LIM. CREDIT: ";
            cin >> limite;
            setLimiteCredito(limite);

    }
    else {
        setLimiteCredito(0);
    }
}

bool Cliente::confirmarCtaCte(){
    int cuenta;
    cout << ">> ";
    cin >> cuenta;

    while(true){
        switch (cuenta){
        case 1:
            setCuentaCorriente(true);
            return true;
            break;
        case 2:
            setCuentaCorriente(false);
            return false;
            break;
        default:
            cout << " CODIGO INCORECTO " << endl;
            break;
        }
    cout << "CUENTA CORRIENTE: SI (1) / NO (2)";
    cin >> cuenta;
    }
    return false;
}

void Cliente::mostrar(){
    cout << "ID         : ";
    cout << _ID << endl;
    Cuenta::mostrar();
    cout << "LIM. CREDIT: ";
    cout << _limiteCred << endl;
}

int Cliente::cantClientes(){
    int bytes, cant;

    FILE *p;
    p = fopen("Clientes.dat", "rb");

    if (p == NULL){
        return 0;
    }

    fseek(p, 0, SEEK_END);
    bytes = ftell(p);
    fclose(p);
    cant = bytes / sizeof(Cliente);
    return cant;
}

int Cliente::BuscarIDCliente (int ID){
    int pos = 0;

    while(leerdeDisco(pos++)){
        if(_ID == ID){
            return pos -1;
        }
    }
    return -1;
}

bool Cliente::Guardar(){
    FILE *p;
    p = fopen("Clientes.dat", "ab");                  ///ABRE EL ARCHIVO DESDE EL FINAL, SI NO EXISTE LO CREA.

    if(p == NULL){
        return false;
    }

    if(fwrite(this, sizeof(Cliente), 1, p)){         ///ESCRIBE EL ARCHIVO.
        fclose(p);
        return true;                                ///SI SE GUARDA CONFIRMA /// el mensaje fuera de la clase
    }
    else{
        fclose(p);
        return false;                               ///SI NO SE GUARDA NIEGA /// el mensaje fuera de la clase
    }
}

bool Cliente::leerdeDisco(int pos){
    FILE *p;
    p = fopen("Clientes.dat","rb");                   ///abre el archivo desde el byte 0.

    if (p == NULL){
        return false;
    }

    fseek(p, sizeof(Cliente)*pos, SEEK_SET);         ///posiciona el PUNTEOR / CABEZAL en la direcion que se le mando.

    if(fread(this, sizeof(Cliente), 1, p)){
        fclose(p);
        return true;                                ///SI SE ABRE CONFIRMA /// el mensaje fuera de la clase
    }
    else{
        fclose(p);
        return false;                               ///SI NO SE ABRE NIEGA /// el mensaje fuera de la clase
    }
}

bool Cliente::modificardeDisco(int pos){
    FILE *p;
    p = fopen("Clientes.dat","rb+");                   ///ABRE EL ARCHIVO DESDE 0 Y PUEDE ESCRIBIR Y MODIFICAR.

    if (p == NULL){
        return false;
    }

    fseek(p, sizeof(Cliente)*pos, SEEK_SET);         ///posiciona el PUNTEOR / CABEZAL en la direcion que se le mando.

    if(fwrite(this, sizeof(Cliente), 1, p)){
        fclose(p);
        return true;                                ///SI SE ABRE CONFIRMA /// el mensaje fuera de la clase
    }
    else{
        fclose(p);
        return false;                               ///SI NO SE ABRE NIEGA /// el mensaje fuera de la clase
    }
}
