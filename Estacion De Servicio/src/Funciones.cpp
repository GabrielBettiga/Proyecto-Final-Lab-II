#include <iostream>
#include <cstring>
using namespace std;
#include "Funciones.h"

///===============================
///  FUNIONES PARA CLEINTES
///===============================
void clientes(){
    int opc;
    do{
        cout << "       MENU CLIENTES       " << endl;
        cout << "===========================" << endl;
        cout << " 1 > INGRESAR              " << endl;
        cout << " 2 > MODIFICAR             " << endl;
        cout << " 3 > MOSTRAR               " << endl;
        cout << " 9 > MOSTRAR TODOS (BORAR OPC) " << endl; /// OPC PARA OCULTAR
        cout << " 0 > VOLVER                " << endl;
        cout << "===========================" << endl;
        cout << " >> ";
        cin >> opc;
        system ("cls");

        switch(opc){
        case 1:
            cargarCliente();
            break;
        case 2:
            modificarCliente();
            break;
        case 3:
            mostrarCliente();
            break;
        case 9:
            mostrarTodosClientes();
            break;
        case 0:
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
    }while (opc != 0);
}

void cargarCliente(){
    int opc;
    Cliente obj;
    obj.cargarCliente();
    do {
        cout << endl;
        cout << " DESEA GUARDAR EL CLIENTE. " << endl;
        cout << " (1) SI  / (2) NO          " << endl;
        cout << " >> ";
        cin >> opc;
        if(opc == 1){
            if(obj.Guardar()){
                cout << endl;
                cout << " == CLIENTE GUARDADO == " << endl;
                cout << endl;
                system("pause");
                system("cls");
            }
            else {
                cout << " ERROR NO SE GUARDO " << endl;
            }
        }
        else {
            cout << " CLIENTE NO GUARDADO " << endl;
        }
    }while (opc < 0 || opc > 2);
}

void mostrarCliente(){

    int num;
    Cliente obj;

    system ("cls");

    cout << " NUMERO DE CLIENTE : " << endl;
    cin >> num;

    if(obj.BuscarIDCliente(num) >= 0){
        cout << endl;
        obj.mostrarCliente();
        cout << endl;
    }
    else {
        cout << " EL NUMERO DE CLIENTE NO EXISTE " << endl;
    }
}

void mostrarTodosClientes(){
    cout << endl << endl;
    cout << " TODO EL ARCHIVO CLIENTE   " << endl;
    Cliente obj;
    int pos = 0;
    while(obj.leerdeDisco(pos++)){
        cout << "POS " << pos << endl;
        obj.mostrarCliente();
        cout << endl;
    }
}

void modificarCliente(){
    int num, pos;
    Cliente obj;

    system ("cls");
    cout << endl;
    cout << " NUMERO DE CLIENTE : ";
    cin >> num;

    if((pos = obj.BuscarIDCliente(num)) >= 0){

            datoModificar(obj).modificardeDisco(pos);
    }
    else {
        cout << " EL NUMERO DE CLIENTE NO EXISTE " << endl;
    }
}

Cliente datoModificar(Cliente cli){
    int opc, tel;
    long long cuit;
    float importe;
    string cambiar;
    do{
        cout << endl;
        cli.mostrarCliente();
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

        switch (opc){
        case 1:
            cout << " NOMBRE: " << endl;
            cin.ignore();
            getline(cin,cambiar);
            cli.setNombre(cambiar);
            break;
        case 2:
            cout << " DIRECCION: " << endl;
            cin.ignore();
            getline(cin,cambiar);
            cli.setDireccion(cambiar);
            break;
        case 3:
            cout << " CUIT: " << endl;
            cin >> cuit;
            cli.setCUIT(cuit);
            break;
        case 4:
            cout << " TELEFONO: " << endl;
            cin >> tel;
            cli.setTelefono(tel);
            break;
        case 5:
            cout << " CORREO: " << endl;
            cin.ignore();
            getline(cin,cambiar);
            cli.setEmail(cambiar);
            break;
        case 6:
            cout << " CUENTA CORRIENTE: " << endl;
            if(cli.getCuentaCorriente()){
                cout << endl;
                cout << " == CTA CTE DESACTIVADA == " << endl;
                cli.setCuentaCorriente(false);
            }
            else {
                cout << endl;
                cout << " == CTA CTE ACTIVA == " << endl;
                cli.setCuentaCorriente(true);
            }
            break;
        case 7:
            cout << " LIMITE DE CREDITO: " << endl;
            cin >> importe;
            cli.setLimiteCredito(importe);
            break;
        case 8:
            cout << " CLIENTE: " << endl;
            if(cli.getEstadoCliente()){
                cout << " == DESACTIVADO == " << endl;
                cli.setEstadoCliete(false);
                system("pause");
                system ("cls");
            }
            else {
                cout << " == ACTIVADO == " << endl;
                cli.setEstadoCliete(true);
                system("pause");
                system ("cls");
            }
            break;
        case 0:
            system ("cls");
            return cli;
            break;
        default:
            cout << "====================" << endl;
            cout << "  OPCION INCORECTA  " << endl;
            cout << "====================" << endl;
            system("pause");
            system ("cls");
            break;
        }

    }while (opc != 0);
}

///===============================
///  FUNIONES PARA VENTAS
///===============================


