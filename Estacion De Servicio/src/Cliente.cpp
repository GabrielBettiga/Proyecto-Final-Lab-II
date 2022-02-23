#include <iostream>
using namespace std;
#include "Cliente.h"

Cliente::Cliente(){
    _ID = 0;
    _cuentaCorriente = false;
    _limiteCred = 0;
    _activo = true;
}
int Cliente::getID(){
    return _ID;
}

bool Cliente::getCuentaCorriente(){
    return _cuentaCorriente;
}

float Cliente::getLimiteCredito(){
    return _limiteCred;
}

bool Cliente::getEstadoCliente(){
    return _activo;
}

void Cliente::setLimiteCredito(float limite){
    if(limite >= 0){
        _limiteCred = limite;
    }
    else {
        _limiteCred = 0;
    }
}

void Cliente::setID(int id){
    _ID = id;
}

void Cliente::setCuentaCorriente(bool x){
    _cuentaCorriente = x;
}

void Cliente::setEstadoCliete(bool activo){
    if(activo){
        _activo = true;
    }
    else {
        _activo = false;
        Cuenta::_Baja.FechaActual();
    }
}
void Cliente::cargarCliente(){

    _ID = cantClientes()+1;
    _activo = true;
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

void Cliente::mostrarCliente(){
    cout << "ID         : ";
    cout << _ID << endl;
    cout << "ESTADO     : ";
    if(_activo){
        cout << "ACTIVO. " << endl;
    }
    else {
        cout << "INACTIVA. " << endl;
    }
    Cuenta::mostrar();
    cout << "CTA. CTE.  : ";
    if(_cuentaCorriente){
        cout << "SI. " << endl;
    }
    else {
        cout << "NO. " << endl;
    }
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

int Cliente::buscarClientexCUIT (int cuit){
    int pos = 0;

    while(leerdeDisco(pos++)){
        if(_CUIT == cuit){
            return pos -1;
        }
    }
    return -1;
}

void Cliente::modificarDatoCliente(){
    int opc, tel;
    long long cuit;
    float importe;
    string cambiar;
    do
    {
        system("cls");
        cout << endl;
        mostrarCliente();
        cout << endl;
        cout << "===========================" << endl;
        cout << "SELECCIONE DATO A MODIFICAR" << endl;
        cout << "===========================" << endl;
        cout << " (1) NOMBRE.               " << endl;
        cout << " (2) DIRECCION.            " << endl;
        cout << " (3) CUIT.                 " << endl;
        cout << " (4) TELEFONO.             " << endl;
        cout << " (5) CORREO.               " << endl;
        cout << " (6) CUENTA CORRIENTE.     " << endl;
        cout << " (7) LIMITE DE CREDITO.    " << endl;
        cout << " (8) ACTIVAR / DESACTIVAR. " << endl;
        cout << "===========================" << endl;
        cout << " (0) SALIR.                " << endl;
        cout << endl;
        cout << " OPC >> ";
        cin >> opc;

        switch (opc)
        {
        case 1:
            cout << " NOMBRE: " << endl;
            cin.ignore();
            getline(cin,cambiar);
            setNombre(cambiar);
            break;
        case 2:
            cout << " DIRECCION: " << endl;
            cin.ignore();
            getline(cin,cambiar);
            setDireccion(cambiar);
            break;
        case 3:
            cout << " CUIT: " << endl;
            cin >> cuit;
            setCUIT(cuit);
            break;
        case 4:
            cout << " TELEFONO: " << endl;
            cin >> tel;
            setTelefono(tel);
            break;
        case 5:
            cout << " CORREO: " << endl;
            cin.ignore();
            getline(cin,cambiar);
            setEmail(cambiar);
            break;
        case 6:
            cout << " CUENTA CORRIENTE: " << endl;
            if(getCuentaCorriente())
            {
                cout << endl;
                cout << " == CTA CTE DESACTIVADA == " << endl;
                setCuentaCorriente(false);
            }
            else
            {
                cout << endl;
                cout << " == CTA CTE ACTIVA == " << endl;
                setCuentaCorriente(true);
            }
            break;
        case 7:
            cout << " LIMITE DE CREDITO: " << endl;
            cin >> importe;
            setLimiteCredito(importe);
            break;
        case 8:
            cout << " CLIENTE: " << endl;
            if(getEstadoCliente())
            {
                cout << " == DESACTIVADO == " << endl;
                setEstadoCliete(false);
                system("pause");
                system ("cls");
            }
            else
            {
                cout << " == ACTIVADO == " << endl;
                setEstadoCliete(true);
                system("pause");
                system ("cls");
            }
            break;
        case 0:
            system ("cls");
            return;
            break;
        default:
            cout << "====================" << endl;
            cout << "  OPCION INCORECTA  " << endl;
            cout << "====================" << endl;
            system("pause");
            system ("cls");
            break;
        }
    }
    while (opc != 0);
}

bool Cliente::crearArchivo(){
    FILE *p;
    p = fopen("Clientes.dat", "wb");                  ///DESTRUYE E ARCHIVO, LO CREA SI NO EXISTE
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
