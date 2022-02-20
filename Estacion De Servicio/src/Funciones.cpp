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
        aux.setDisponible();

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
        obj.modificarDatoCliente();
        obj.modificardeDisco(pos);
    }
    else
    {
        cout << " EL NUMERO DE CLIENTE NO EXISTE " << endl;
    }
}
///===============================
///  FUNIONES PARA VENTAS
///===============================
void venta()
{
    int opc;
    do
    {
        system("cls");
        cout << endl;
        cout << "           VENTA               " << endl;
        cout << " ============================= " << endl;
        cout << "  CLINETE O CONSUMIDOR FINAL   " << endl;
        cout << " ============================= " << endl;
        cout << " (1) SELECCIONAR CLIENTE       " << endl;
        cout << " (2) CONSUMIDOR FINAL          " << endl;
        cout << " ============================= " << endl;
        cout << " (0) CANCELAR                  " << endl;
        cout << endl;
        cout << " OPCION >> ";
        cin >> opc;

        switch(opc){
            case 1:
                facturarxClietete();
                break;
            case 2:
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
    while(opc != 0);
}
void facturarxClietete(){
    Factura fac;
    Cliente cli;
    Surtidor sur;
    Nafta naf;
    int posCli, posNaf, posSur;

    float litros;



    if((posCli = seleccionarClietete()) == true ){
            if((posNaf = seleccionarNafta()) != -1){
                cli.leerdeDisco(posCli);
                naf.LeerDeDisco(posNaf);
                sur = cargarCombustible(naf.getIDtipoDeNafta());
            }
    }

    cout << "NUMERO:";
    cout << sur.getIDsurtidor() << endl;
    cout << "litros :";
    cout << sur.getLitros() << endl;



    //cli.mostrar();
    //naf.Mostrar();
    system("pause");




}

int seleccionarClietete(){
    Cliente cli;
    int numero, pos;
    bool ok;

    do {
        system("cls");
        cout << endl;
        cout << " NUMERO DE CLIENTE / CUIT : ";
        cin >> numero;

        if((pos = cli.BuscarIDCliente(numero)) > -1){
            return pos;
        }
        else {
            if((pos = cli.buscarClientexCUIT(numero)) > -1){
                return pos;
            }
        }

        system("cls");
        cout << " ============================ " << endl;
        cout << " NUMERO DE CLIENTE INCORECTOR " << endl;
        cout << " ============================ " << endl;
        cout << " (1) INGRESAR OTRO NUMERO     " << endl;
        cout << " (0) CANCELAR CARGA           " << endl;
        cout << " ============================ " << endl;
        cout << " >> ";
        cin >> ok;

    }while(ok);
    return ok;
}

int seleccionarNafta(){
    Nafta naf;
    int id, pos;
    bool ok;

    do {
        system("cls");
        cout << endl;
        cout << " ID NAFTA: ";
        cin >> id;

        if((pos = naf.BuscarID(id)) > -1){
            return pos;
        }

        system("cls");
        cout << " ============================ " << endl;
        cout << "       EL ID NO EXISTE        " << endl;
        cout << " ============================ " << endl;
        cout << " (1) INGRESAR OTRO NUMERO     " << endl;
        cout << " (0) CANCELAR CARGA           " << endl;
        cout << " ============================ " << endl;
        cout << " >> ";
        cin >> ok;

    }while(ok);
    return -1;
}

Surtidor cargarCombustible(int IDnaf){
    int opc, numero;
    Surtidor sur;
    float pesos, litros;


    system("cls");

    cout << " ============================ " << endl;
    cout << "  INDIQUE NUMERO DE SURTIDOR  " << endl;
    cout << " ============================ " << endl;
    cout << " >> ";
    cin >> numero;

    while(sur.buscarPorID(numero) < -1){
        system("cls");
        cout << " ============================ " << endl;
        cout << "  N DE SURTIDOR NO EXISTE     " << endl;
        cout << " ============================ " << endl;
        cout << " INGRESE OTRO                 " << endl;
        cout << " >> ";
        cin >> numero;
    }

    do{
    system("cls");
    cout << " SURTIDOR N " << sur.getIDsurtidor() << ": "<<endl;
    cout << " ===================== " << endl;
    cout << " (1) CARGAR POS PESOS  " << endl;
    cout << " (2) CARGAR POR LITROS " << endl;
    cout << " (0) SALIR             " << endl;
    cout << " ===================== " << endl;
    cout << " OPC >> ";
    cin >> opc;

    if(opc == 1){
        system("cls");
        cout << endl;
        cout << " PESOS A CARGAR : ";
        cin >> pesos;

        while(pesos < 1){
            system("cls");
            cout << " = INGRESE UN IMORTE MAYOR A 0 = " << endl;
            cout << " PESOS A CARGAR : ";
            cin >> pesos;
        }
        sur.CombertirLitros(IDnaf,pesos);
        return sur;
    }
    else {
        if(opc == 2){
            system("cls");
            cout << endl;
            cout << " LITROS A CARGAR : ";
            cin >> litros;

            while(litros < 1){
            system("cls");
            cout << " = INGRESE UN IMORTE MAYOR A 0 = " << endl;
            cout << " PESOS A CARGAR : ";
            cin >> litros;
            }
            sur.setLitros(litros);
            return sur;
        }
        else {
            if(opc != 0){
                system ("cls");
                cout << " ========================= " << endl;
                cout << "       OPCION INCORECTA    " << endl;
                cout << " ========================= " << endl;
                system ("pause");
            }
        }
    }

    }while (opc != 0);
    sur.setIDsurtidor(-1);
    sur.setLitros(0);
    return sur;

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
        cout << " (5) VACIAR TANQUE              " << endl;
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
            system ("cls");
            break;
        case 3:
            mostrarTodosLosTanques();
            system("pause");
            system("cls");
            break;
        case 4:
            ingresarCombustible();
            system ("cls");
            break;
        case 5:
            vaciarTanque();
            system ("cls");
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

}

void mostrarTanque()
{
    ///REVISAR ESTA SIN TERMINAR
    TanqueManager aux;
    int pos = 0,tan;
    cout<<endl<< " ID DEL TANQUE: ";
    cin >> tan;
    pos=aux.BuscarIDtanque(tan);
    while(pos<0)
    {
        system("cls");
        cout << "ID INCORRECTA ";
        cout << " INGRESE OTRA ID: ";
        cin >> tan;
        pos=aux.BuscarIDtanque(tan);

    }
    cout<<endl;
    aux.Mostrar();

    system("pause");
    system("cls");
}



bool asignarNafta()
{
    TanqueManager aux;
    int opc;
    int pos=0;
    int tan;
    int ok;



    do
    {
        pos=0;
        while(aux.leerdeDisco(pos++))
        {
            aux.Mostrar();
            cout<<endl;
        }
        cout<< "A QUE TANQUE QUIERE ASIGNARLE EL COMBUSTIBLE: ";
        cin>> tan;


        while(ok=aux.BuscarIDtanque(tan)==-1)
        {
            system("cls");
            cout<< "ID DE TANQUE INCORRECTA, INGRESE OTRO: ";
            cin>> tan;
        }
        if(aux.getTanque().getOcupacion()!=0)
        {

            cout<< "EL TANQUE CONTIENE COMBUSTIBLE, NO SE PUEDE ASIGNAR COMBUSTIBLE "<<endl;
            cout<< "VACIE EL TANQUE PARA PODER ASIGNAR COMBUSTIBLE "<<endl;
            system("pause");
            ok=-1;
        }

        system("cls");
    }
    while (ok==-1);


    mostrarTodosCombustibles();
    cout<<endl;

    int naf;
    Nafta auxNaf;
    cout<< "QUE NAFTA VA A CONTENER EL TANQUE: ";
    cin>> naf;

    while(auxNaf.BuscarID(naf)==-1)
    {
        system("cls");
        mostrarTodosCombustibles();
        cout<<endl;
        cout<< "EL COMBUSTIBLE NO EXISTE ";
        cout<< "INGRESE OTRO ID COMBUSTIBLE : ";
        cin>> naf;
    }

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
    Nafta naf;
    int id;

    system("cls");
    mostrarTodosCombustibles();
    cout<<endl;
    cout<< "QUE COMBUSTIBLE QUIERE CARGAR: ";
    cin>> id;

    while(naf.BuscarID(id)==-1)
    {

        mostrarTodosCombustibles();
        cout<<endl;
        cout<< "NO EXISTE LA ID DE COMBUSTIBLE INGRESADA.  "<<endl;
        cout<< "INGRESE NUEVA ID : ";
        cin>> id;

    }

    float Litros;
    cout<< "CUANTOS LITROS VA A CARGAR: ";
    cin>> Litros;

    if (aux.CargarTanques(id,Litros))
    {
        cout<<"CARGO"<<endl;
        system("pause");
    }
    else
    {
        cout<<"EXCEDE LA CAPACIDAD DE ALMACENAMIENTO"<<endl;
        system("pause");
    }
}


void vaciarTanque()
{
    TanqueManager aux;
    int tan,pos;

    mostrarTodosLosTanques();
    cout<<endl;
    cout<< "SELECCIONE UN TAQUE: ";
    cin>> tan;

    while((pos=aux.BuscarIDtanque(tan))==-1)
    {

        mostrarTodosLosTanques();
        cout<<endl;
        cout<< "NO EXISTE LA ID DE TANQUE INGRESADO.  "<<endl;
        cout<< "INGRESE NUEVA ID : ";
        cin>> tan;

    }

    aux.vaciarTanque();
    aux.modificardeDisco(pos);
    aux.Mostrar();
    system("pause");



}
///===============================
///  FUNIONES PARA INFORMES
///===============================
