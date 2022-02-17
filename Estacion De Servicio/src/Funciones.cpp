#include <iostream>
#include <cstring>
using namespace std;
#include "Funciones.h"

bool configuracion()
{
    const int TAM = 3;
    bool bandera = false, vecBand[TAM];
    int opc;

    bandera = archivos(TAM, vecBand);

    if(bandera != true)
    {

        do
        {
            system("cls");
            cout << endl;
            cout << "        CONFIGURACION          " << endl;
            cout << "===============================" << endl;
            cout << " (1) CANTIDAD DE TANQUES       " << endl;
            cout << " (2) CANTIDAD DE SURTIDORES    " << endl;
            cout << " (3) CONSUMIDOR FINAL          " << endl;
            cout << " (0) SALIR                     " << endl;
            cout << "===============================" << endl;
            cout << " OPC >> ";
            cin >> opc;

            switch(opc)
            {
            case 1:
                /// FUNCION PARA CONFIRMAR LA CANTIDAD DE TANQUES
                vecBand[0] = cargarTanques();
                system("pause");
                break;
            case 2:
                /// FUNCION CANTIDAD SURTIDORES
                cout << " SURTIDORES " << endl;
                vecBand[1] = cargarSurtidores();
                break;
            case 3:
                /// FUNCION CARGAR CONSUMIDOR FINAL
                vecBand[2] = cargaConsumidorFinal();
                system("pause");
                break;
            case 0:
                return controlBanderas(TAM, vecBand);
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
        while(opc != 0);
    }
    return bandera;
}

bool archivos(const int TAM, bool *vecBand)
{
    int i;
    bool ok = true;
    Surtidor sur;
    Cliente cli;
    TanqueManager tan;

    vecBand[0] = tan.CantTanques();
    vecBand[1] = sur.CantSurtidor();
    vecBand[2] = cli.cantClientes();

    for(i=0; i<TAM; i++)
    {
        if(vecBand[i] == false)
        {
            ok = false;
        }
    }

    return ok;
}
bool controlBanderas(const int TAM, bool *vecBand)
{
    bool b = true;
    int i;

    for(i=0; i<TAM; i++)
    {
        if(vecBand[i] == false)
        {
            b = false;
        }
    }
    return b;
}

bool cargarTanques()
{
    int cant, i;

    system ("cls");
    cout << endl;
    cout << "===============================" << endl;
    cout << "           TANQUES             " << endl;
    cout << "===============================" << endl;
    cout << " ¿CANTIDAD DE TANQUES?         " << endl;
    cout << " >> ";
    cin >> cant;
    system("cls");

    for (i=0; i <cant; i++)
    {
        float litros;
        TanqueManager aux;

        cout << " CAPACIDAD DEL TANQUE N° " << i+1 << " : ";
        cin >> litros;

        aux.CrearTanque();
        aux.setCapacidad(litros);
        aux.setDisponible(litros);

        if(i==0)
        {
            aux.setID(1);
            aux.crearArchivo();
        }
        else
        {
            aux.Guardar();
        }
    }
    return true;
}

bool cargarSurtidores()
{
    int cant, i;
    Surtidor sur;

    system ("cls");
    cout << endl;
    cout << "===============================" << endl;
    cout << "           SURTIDORES          " << endl;
    cout << "===============================" << endl;
    cout << " ¿CANTIDAD DE SURTIDORES?      " << endl;
    cout << " >> ";
    cin >> cant;
    system("cls");

    for(i=0; i<cant; i++)
    {
        if(i==0)
        {
            sur.setIDsurtidor(1);
            sur.crearArchivo();
        }
        else
        {
            sur.CrearSurtidor();
            sur.GrabarEnDisco();
        }
    }
    return true;
}

bool cargaConsumidorFinal()
{
    Cliente aux;
    int opc;

    system("cls");
    cout << endl;
    cout << " EL CONSUMIDOR FINAL SE CARGARA CON LOS SIGUETES DATOS: (*)" << endl;
    cout << endl;

    aux.setID(1);
    aux.setNombre("CONSUMIDOR FINAL ");
    aux.setCUIT(9999);
    aux.mostrarCliente();

    do
    {
        cout << endl;
        cout << "(*) POSIBIIDAD DE MODIFICAR NUMERO DE CUIT: " << endl;
        cout << endl;
        cout << "     ¿GUARDAR?          " << endl;
        cout << " (1) SI / (2) MODIFICAR " << endl;
        cout << " OPC >> ";
        cin >> opc;

        if (opc == 1)
        {
            if(aux.crearArchivo())
            {
                cout << " CARGADO " << endl;
                return true;
            }
            else
            {
                cout << " ERROR EN CARGA " << endl;
                system("pause");
                return false;
            }
        }
        else
        {
            long long int cuit;
            system("cls");
            cout << endl;
            cout << " NUEVO CUIT: ";
            cin >> cuit;
            aux.setCUIT(cuit);
            cout << endl;
            aux.mostrarCliente();

            if(aux.crearArchivo())
            {
                cout << endl;
                cout << " CARGADO " << endl;
                return true;
            }
            else
            {
                cout << endl;
                cout << " ERROR EN CARGA " << endl;
                system("pause");
                return false;
            }
        }
    }
    while (opc > 2 || opc < 1);
}



///===============================
///  FUNIONES PARA CLEINTES
///===============================
void menuClientes()
{
    int opc;
    do
    {
        cout << "       MENU CLIENTES       " << endl;
        cout << "===========================" << endl;
        cout << " (1) INGRESAR              " << endl;
        cout << " (2) MODIFICAR             " << endl;
        cout << " (3) MOSTRAR               " << endl;
        cout << " < 9 > MOSTRAR TODOS (BORAR OPC) " << endl; /// OPC PARA OCULTAR
        cout << " (0) VOLVER                " << endl;
        cout << "===========================" << endl;
        cout << " >> ";
        cin >> opc;
        system ("cls");

        switch(opc)
        {
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
    }
    while (opc != 0);
}

void cargarCliente()
{
    int opc;
    Cliente obj;
    obj.cargarCliente();
    do
    {
        cout << endl;
        cout << " DESEA GUARDAR EL CLIENTE. " << endl;
        cout << " (1) SI  / (2) NO          " << endl;
        cout << " >> ";
        cin >> opc;
        if(opc == 1)
        {
            if(obj.Guardar())
            {
                cout << endl;
                cout << " == CLIENTE GUARDADO == " << endl;
                cout << endl;
                system("pause");
                system("cls");
            }
            else
            {
                cout << " ERROR NO SE GUARDO " << endl;
            }
        }
        else
        {
            cout << " CLIENTE NO GUARDADO " << endl;
        }
    }
    while (opc < 0 || opc > 2);
}

void mostrarCliente()
{

    int num;
    Cliente obj;

    system ("cls");

    cout << " NUMERO DE CLIENTE : " << endl;
    cin >> num;

    if(obj.BuscarIDCliente(num) >= 0)
    {
        cout << endl;
        obj.mostrarCliente();
        cout << endl;
    }
    else
    {
        cout << " EL NUMERO DE CLIENTE NO EXISTE " << endl;
    }
}

void mostrarTodosClientes()
{
    cout << endl << endl;
    cout << " TODO EL ARCHIVO CLIENTE   " << endl;
    Cliente obj;
    int pos = 0;
    while(obj.leerdeDisco(pos++))
    {
        cout << "POS " << pos << endl;
        obj.mostrarCliente();
        cout << endl;
    }
}

void modificarCliente()
{
    int num, pos;
    Cliente obj;

    system ("cls");
    cout << endl;
    cout << " NUMERO DE CLIENTE : ";
    cin >> num;

    if((pos = obj.BuscarIDCliente(num)) >= 0)
    {

        datoModificar(obj).modificardeDisco(pos);
    }
    else
    {
        cout << " EL NUMERO DE CLIENTE NO EXISTE " << endl;
    }
}

Cliente datoModificar(Cliente cli)
{
    int opc, tel;
    long long cuit;
    float importe;
    string cambiar;
    do
    {
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

        switch (opc)
        {
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
            if(cli.getCuentaCorriente())
            {
                cout << endl;
                cout << " == CTA CTE DESACTIVADA == " << endl;
                cli.setCuentaCorriente(false);
            }
            else
            {
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
            if(cli.getEstadoCliente())
            {
                cout << " == DESACTIVADO == " << endl;
                cli.setEstadoCliete(false);
                system("pause");
                system ("cls");
            }
            else
            {
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

    }
    while (opc != 0);
}

///===============================
///  FUNIONES PARA VENTAS
///===============================
void venta()
{
    int opc;
    Cliente cli;

    do
    {
        system("cls");
        cout << endl;
        cout << " CLINETE O CONSUMIDOR FINAL    " << endl;
        cout << " ============================= " << endl;
        cout << " (1) SELECCIONAR CLIENTE       " << endl;
        cout << " (2) CONSUMIDOR FINAL          " << endl;
        cout << " ============================= " << endl;
        cout << " (0) CANCELAR                  " << endl;
        cout << endl;
        cout << " OPCION >> ";
        cin >> opc;

    }
    while(opc != 0);



}
///===============================
///  FUNIONES PARA COBRANZAS
///===============================

///===============================
///  FUNIONES PARA COMUSTIBLES
///===============================
void menuCombustibles()
{
    int opc;
    do
    {
        cout << endl;
        cout << "     COMBUSTIBLES          " << endl;
        cout << "===========================" << endl;
        cout << " (1) ALTA COMBUSTIBLE      " << endl;
        cout << " (2) MODIFICAR COMBUSTIBLE " << endl;
        cout << " (3) MOSTRAR COMBUSTIBLE   " << endl;
        cout << " < 9 > MOSTRAR TODOS LOS COMBUSTIBLES " << endl;
        cout << " (0) SALIR                 " << endl;
        cout << "===========================" << endl;
        cout << " >> ";
        cin >> opc;
        system("cls");

        switch(opc)
        {
        case 1:
            altaCombustible();
            break;
        case 2:
            modificarCombustible();
            break;
        case 3:
            mostrarCombustible();
            break;
        case 9:
            mostrarTodosCombustibles();
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
        }

    }
    while(opc != 0);
}

void altaCombustible()
{
    int opc;
    Nafta obj;
    obj.Cargar();
    do
    {
        cout << endl;
        cout << " ¿DESEA GUARDAR? " << endl;
        cout << " (1) SI  / (2) NO          " << endl;
        cout << " >> ";
        cin >> opc;
        if(opc == 1)
        {
            if(obj.GrabarEnDisco())
            {
                cout << endl;
                cout << " == GUARDADO == " << endl;
                cout << endl;
                system("pause");
                system("cls");
            }
            else
            {
                cout << " ERROR NO SE GUARDO " << endl;
            }
        }
        else
        {
            cout << " NO GUARDADO " << endl;
        }
    }
    while (opc < 0 || opc > 2);
}

void mostrarCombustible()
{
    int id;
    Nafta obj;

    system ("cls");

    cout << endl;
    cout << " ID COMUSTIBLE: ";
    cin >> id;
    cout << endl;

    if(obj.BuscarID(id) >= 0)
    {
        obj.Mostrar();
    }
    else
    {
        cout << " NO EXISTE EL ID DE COMBUSTIBLE " <<endl;
    }
}




void mostrarTodosCombustibles()
{
    Nafta obj;
    int pos = 0;

    system("cls");
    cout << endl;
    cout << " LISTADO DE COMBSTIBLES: " << endl;
    cout << endl;
    while(obj.LeerDeDisco(pos++))
    {
        obj.Mostrar();
        cout << endl<<endl;

    }
}

void modificarCombustible()
{
    int id, pos;
    Nafta obj;

    system ("cls");

    cout << endl;
    cout << " ID COMUSTIBLE: ";
    cin >> id;
    cout << endl;

    if((pos = obj.BuscarID(id)) >= 0)
    {
        obj.Mostrar();
        cout << endl;
        obj.modificarNafta();
        if(obj.ModificarEnDisco(pos))
        {
            cout << " MODIFICACION GUARDAD " << endl;
        }
        else
        {
            cout << " NO SE GUARDARON LOS CAMBIOS " << endl;
        }
    }
    else
    {
        cout << " NO EXISTE EL ID DE COMBUSTIBLE " <<endl;
    }
}


///===============================
///  FUNIONES PARA TANQUES
///===============================



void menuTanques()
{
    int opc;
    do
    {
        cout << endl;
        cout << "            TANQUES             " << endl;
        cout << "================================" << endl;
        cout << " (1) ASIGNAR NAFTA              " << endl;
        cout << " (2) MOSTRAR TANQUE             " << endl;
        cout << " (3) MOSTRAR TODO LOS TANQUES   " << endl;
        cout << " (4) INGRESAR COMBUSTIBLE       " << endl;
        cout << " (0) SALIR                      " << endl;
        cout << "================================" << endl;
        cout << " >> ";
        cin >> opc;
        system("cls");

        switch(opc)
        {
        case 1:
            asignarNafta();
            system ("cls");
            break;
        case 2:
            mostrarTanque();
            break;
        case 3:
            mostrarTodosLosTanques();
            system("cls");
            break;
        case 4:
            ingresarCombustible();
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
        }

    }
    while(opc != 0);
}




void mostrarTodosLosTanques()
{
    TanqueManager aux;
    int pos = 0;

    while(aux.leerdeDisco(pos++))
    {
        aux.Mostrar();
        cout << endl;
    }
    system ("pause");
}

void mostrarTanque()
{
    TanqueManager aux;
    int pos = 0,tan;

    cout << " ID DEL TANQUE: ";
    cin >> tan;

    while(aux.leerdeDisco(pos++))
    {

        if(aux.getID()==tan)
        {

            aux.Mostrar();

        }
    }


    system("pause");
    system("cls");
}



bool asignarNafta()
{
    TanqueManager aux;
    int tan;
    int pos=0;
    while(aux.leerdeDisco(pos++))
    {

        aux.Mostrar();
        cout<<endl;



    }

    cout<< "A QUE TANQUE QUIERE ASIGNARLE EL COMBUSTIBLE: ";
    cin>> tan;
    system("cls");
    mostrarTodosCombustibles();
    cout<<endl;

    int naf;
    cout<< "QUE NAFTA VA A CONTENER EL TANQUE: ";
    cin>> naf;

    pos=0;
    while(aux.leerdeDisco(pos++))
    {

        if(aux.getID()==tan)
        {
            system ("cls");
            aux.setIDNafta(naf);
            aux.modificardeDisco(pos-1);
            aux.Mostrar();
            cout<<endl<<"GUARDADO"<<endl;
            system("pause");
            return true;

        }
    }


    return false;
}


void ingresarCombustible()
{
    TanqueManager aux;


    mostrarTodosCombustibles();
    cout<<endl;

    int naf;
    cout<< "QUE COMBUSTIBLE QUIERE CARGAR: ";
    cin>> naf;
    float Litros;
    cout<< "CUANTOS LITROS VA A CARGAR: ";
    cin>> Litros;

    if (aux.CargarTanques(naf,Litros))
    {

        cout<<"CARGADO"<<endl;
    }
    else
    {
        cout<<"NO SE PUDO CARGAR"<<endl;

    }




}
///===============================
///  FUNIONES PARA INFORMES
///===============================
