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
    int pos;
    Cliente obj;

    system ("cls");

    if((pos = seleccionarClietete()) >= 0)
    {
        obj.leerdeDisco(pos);
        obj.mostrar();
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
    int pos;
    Cliente obj;

    system ("cls");

    if((pos = seleccionarClietete()) >= 0)
    {
        obj.leerdeDisco(pos);
        obj.modificarDatoCliente();
        obj.modificardeDisco(pos);
    }
}
///===============================
///  FUNIONES PARA VENTAS
///===============================

void venta()
{
    /// 1) CARGA => TE LA DA EL SURTIDOR
    /// 2) CLIENTE
    /// 3) FACTURAR
    /// 4) SI SE PAGA LA FACTURA O VA A CEUNTA.

    Surtidor sur;
    Cliente cli;
    int posCli;

    sur = cargarCombustible();
    if(sur.getIDsurtidor() < 0){
        return;
    }
    posCli = seleccionarClietete();
    cli.leerdeDisco(posCli);

    if(cli.getEstadoCliente() == false){
        cli.leerdeDisco(0);
    }

    if(situacionCliente(cli,( sur.getLitros() * sur.getNafta().getprecio()))){
        hacerFactura(cli, sur,true,true);
    }
    else {
        hacerFactura(cli, sur,true);
    }
}

Surtidor cargarCombustible()
{

    int posNaf, posSur, opc;
    float importe, litros;
    Surtidor sur;
    Nafta naf;

    if((posNaf = seleccionarNafta()) > -1)
    {
        if((posSur = seleccionarSurtidor()) > -1)
        {

            sur.LeerDeDisco(posSur);
            sur.setNafta(naf.BuscarID(posNaf));

            do
            {
                system("cls");
                cout << endl;
                cout << " =============== " << endl;
                cout << "  CARGAR POR :   " << endl;
                cout << " =============== " << endl;
                cout << " (1) IMPORTE     " << endl;
                cout << " (2) LITROS      " << endl;
                cout << " =============== " << endl;
                cout << " (0) SALIR "   << endl;
                cout << " >> ";
                cin >> opc;

                if(opc > 0 && opc < 3)
                {
                    if(opc == 1)
                    {
                        system("cls");
                        cout << endl;
                        cout << " IMPORTE : " ;
                        cin >> importe;

                        while(importe <=0 )
                        {
                            system("cls");
                            cout << " INGRESE UN NUMERO POSITIVO " << endl;
                            cout << " >> ";
                            cin >> importe;
                            system("pause");
                        }
                        sur.CombertirLitros(importe);
                            if(sur.Cargar()){
                                system("cls");
                                sur.MostraCarga();
                                system("pause");
                                return sur;
                            }
                            system ("cls");
                            cout << " ================= " << endl;
                            cout << "  SIN COMBUSTIBLE  " << endl;
                            cout << " ================= " << endl;
                            system("pause");
                            sur.setIDsurtidor(-2);
                            return sur;
                    }
                    else
                    {
                        if( opc == 2)
                        {
                            system("cls");
                            cout << endl;
                            cout << " LITROS : " ;
                            cin >> litros;

                            while(litros <=0 )
                            {
                                system("cls");
                                cout << " INGRESE UN NUMERO POSITIVO " << endl;
                                cout << " >> ";
                                cin >> litros;
                                system("pause");
                            }
                            sur.setLitros(litros);
                            if(sur.Cargar()){
                                system("cls");
                                sur.MostraCarga();
                                system("pause");
                                return sur;
                            }
                            system ("cls");
                            cout << " ================= " << endl;
                            cout << "  SIN COMBUSTIBLE  " << endl;
                            cout << " ================= " << endl;
                            system("pause");
                            sur.setIDsurtidor(-2);
                            return sur;
                        }
                    }
                }
                else
                {
                    if(opc != 0){
                        system("cls");
                        cout << endl;
                        cout << " ERROR EN OPCION " << endl;
                        system("pause");
                    }
                }
            }
            while (opc != 0);
        }
    }


    system("cls");
    cout << endl;
    cout << " ================= " << endl;
    cout << "  CARGA CANCELADA  " << endl;
    cout << " ================= " << endl;
    system("pause");
    sur.setIDsurtidor(-1);
    return sur;
}

void listFacCli(Cliente cli, bool estado)
{
    Factura aux;
    int pos = 0;

    cout << endl;
    cout << left;
    cout << setw(6) <<" NUM ";
    cout << setw(20) << " CLIENTE ";
    cout << setw(10) << " TOTAL ";
    cout << setw(10) << " SALDO ";
    cout << setw(6) << " ESTADO " << endl;
    cout << "========================================================= " << endl;

    while (aux.LeerDeDisco(pos++))
    {
        if(aux.getCliente() == cli.getID() && aux.getPaga() == estado){

            cout << left;
            cout << setw(6) << aux.getNumFac();
            cli.BuscarIDCliente(aux.getCliente());
            cout << setw(20) << cli.getNombre();
            cout << setw(10) << aux.getTotal();
            cout << setw(10) << aux.getSaldo();
            cout << setw(6) << aux.getPaga() << endl;
        }
    }
}

void mostFacturas(){
    Factura aux;
    Cliente cli;
    int pos = 0;

    cout << endl;
    cout << left;
    cout << setw(6) <<" NUM ";
    cout << setw(20) << " CLIENTE ";
    cout << setw(10) << " TOTAL ";
    cout << setw(10) << " SALDO ";
    cout << setw(6) << " ESTADO " << endl;
    cout << "========================================================= " << endl;

    while (aux.LeerDeDisco(pos++))
    {
        cout << left;
        cout << setw(6) << aux.getNumFac();
        cli.BuscarIDCliente(aux.getCliente());
        cout << setw(20) << cli.getNombre();
        cout << setw(10) << aux.getTotal();
        cout << setw(10) << aux.getSaldo();
        cout << setw(6) << aux.getPaga() << endl;
    }
    system("pause");
}

float deudaxCliente(Cliente cli){
    Factura aux;
    int pos = 0;
    float deuda = 0;

    while(aux.LeerDeDisco(pos++)){
        if(aux.getCliente() == cli.getID()){
            if(aux.getPaga() == false){
                deuda += aux.getSaldo();
            }
        }
    }
    return deuda;
}

float saldoSinAplicarPorCliente(Cliente cli){
    Recibo rc;
    int pos = 0;
    float resultado = 0;

    while(rc.leerdeDisco(pos++)){
        if(rc.getCliente() == cli.getID()){
            if(rc.getEstadoRecibo() == false){
                resultado += rc.getSaldoRecibo();
            }
        }
    }
    return resultado;
}

void deudaCli(){
    Cliente cli;
    int pos;
    float deuda, saldo;

    pos = seleccionarClietete();
    if(pos > -1){
        cli.leerdeDisco(pos);
        deuda = deudaxCliente(cli);
        saldo = saldoSinAplicarPorCliente(cli);

        system("cls");
        cout << endl;
        cout << " ID                : " << cli.getID() << endl;
        cout << " CLIENTE           : " << cli.getNombre() << endl;
        cout << " LA DEUDA          : " << deuda << endl;
        cout << " PAGOS SIN APLICAR : " << saldo << endl;
        cout << " DEUDA NETA        : " << (deuda - saldo) << endl;
        cout << "=========================================================" << endl;
        listFacCli(cli, false);
        system("pause");
    }
}

void hacerPago(){

    /// 1) PEDIR CLIENTE
    /// 2) MOSTRAMOS LA DEUDA
    /// 3) SELECCIONAR FACTURAS
    /// 4) HACER RECIBO

    Cliente cli;
    int pos;
    pos = seleccionarClietete();

    if(cli.leerdeDisco(pos)){
        if(cli.getEstadoCliente()){
            seleccionarFacturas(cli);
        }
        else{
            cout << " CUENTA INACTIVA " << endl;
            system("pause");
        }
    }

    return;
}

void mostrarRecibos(){
    Recibo aux;
    int pos = 0;

    while(aux.leerdeDisco(pos++)){
        aux.mostrarRecibo();
    }
    system("pause");
}

void seleccionarFacturas(Cliente cli){

    system("cls");
    Recibo rc;
    float total, saldo;
    bool opc;

    cout << left;
    cout << setw(20) << " CLIENTE : " << cli.getNombre();
    cout << setw(12) << " CUIT : " << cli.getCUIT();
    cout << setw(8) << " N CUENTA " << cli.getID() << endl;
    cout << "============================================================================" << endl;

    listFacCli(cli, false);
    cout << endl;
    cout << " TOTAL DEUDA : " << deudaxCliente(cli) << endl;
    cout << " TOTAL A FAVOR : " << (saldo = saldoSinAplicarPorCliente(cli)) << endl;
    cout << " APLICAR SALDO A FAVOR (1) SI / (0) NO " << endl;
    cout << " >> ";
    cin >> opc;
    cout << endl;
    cout << " TOTAL A PAGAR : ";
    cin >> total;

    vecRecibo(rc.getTam(), cli, total, saldo, opc);

    system("pause");
}

void vecRecibo(int TAM, Cliente cli,float total, float saldo, bool tomarSaldo){

    int *i;
    float *f;

    i = new int [TAM]{};
    f = new float [TAM]{};

    if (i==NULL){
        cout<<"ERROR"<<endl;
        system("pause");
        return;
    }
    if (f==NULL){
        cout<<"ERROR"<<endl;
        system("pause");
        return;
    }
    if(tomarSaldo == true){
        total += saldo;
    }

    int opc = -1;
    int pos = 0, numFac;
    float imp, acuTotal = total;
    Recibo rc;
    Factura fac;

    while(opc != 0 && opc != 2 && pos < TAM){
        cout << " PENDIENTE DE APLCIA : ";
        cout << acuTotal << endl;
        cout << " FACTRA N: ";
        cin >> numFac;
        cout << " IMPORTE : ";
        cin >>  imp;

        if(acuTotal >= imp)
        {
            if(controlRc(numFac, imp, i, TAM))
            {
                i[pos] = numFac;
                f[pos] = imp;
                acuTotal -= imp;
                cout << " CONTINUAR (1) / GUARDAR (2) / SALIR (0) - >> ";
                cin >> opc;
                pos++;
            }
            else {
                cout << " ERROR EN FACTURA - CONTINUAR (1) / GUARDAR (2) / SALIR (0) >> " << endl;
                cin >> opc;
            }

        }
        else
        {
            cout << " ERROR EN IMPORTE = CONTINUAR (1) / GUARDAR (2) / SALIR (0) " << endl;
            cout << " PENDIENTE DE APLICAR " << acuTotal << endl;
            cout << " >> ";
            cin >> opc;
        }
    }

    if(opc != 0){
        rc.cargarRecibo(cli, i, f, total);
        if(rc.Guardar()){
            if(tomarSaldo == true){
                cancelarSaldos(cli, rc.getNumRecibo());
            }
            rc.mostrarRecibo();
            fac.modificarSaldo(rc);
        }
        else
        {
            cout << "ERROR" << endl;
            system("pause");
        }
    }

    delete f;
    delete i;
}

bool controlRc(int numFac, float imp, int *vec, int vT){
    Factura aux;
    bool dos[2]{true, true};

    for(int i=0; i<vT; i++){
        if(vec[i] == numFac){
            dos[0] = false;
        }
    }
    cout << " dos 1: " << dos[0] << endl;
    system("pause");

    if(aux.buscarPorNumero(numFac) > -1){
        if(aux.getSaldo() < imp){
            dos[1] = false;
        }
    }
    else{
        dos[1] = false;
    }
    cout << " dos 2: " << dos[1] << endl;
    system("pause");


    if(dos[0] == true && dos[1] == true){
        return true;
    }
    else{
        return false;
    }
}

void cancelarSaldos(Cliente cli, int ultimoRc){
    Recibo rc;
    int pos = 0;

    while(rc.leerdeDisco(pos++)){
        if(rc.getCliente() == cli.getID()){
            if(rc.getNumRecibo() != ultimoRc){
                if(rc.getEstadoRecibo() == false){
                    rc.setEstado(true);
                    rc.setSaldo(0);
                    rc.modificardeDisco(pos-1);
                }
            }
        }
    }
}




int seleccionarClietete()
{
    Cliente cli;
    int numero, posID, posCUIT;
    bool ok;

    do
    {
        system("cls");
        cout << endl;
        cout << " ========================== " << endl;
        cout << " (1) PARA CONSUMIDOR FINAL  " << endl;
        cout << " ========================== " << endl;
        cout << " NUMERO DE CLIENTE / CUIT : ";
        cin >> numero;

        if(numero == 0){
            return 0;
        }

        if((posID = cli.BuscarIDCliente(numero)) > -1)
        {
            return posID;
        }
        else
        {
            if((posCUIT = cli.buscarClientexCUIT(numero)) > -1)
            {
                return posCUIT;
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

    }
    while(ok);
    return -1;
}

int seleccionarSurtidor()
{
    Surtidor sur;
    int id, pos;
    bool ok;

    do
    {
        system("cls");
        cout << endl;
        cout << " ID SURTIDOR: ";
        cin >> id;

        if((pos = sur.buscarPorID(id)) > -1)
        {
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

    }
    while(ok);
    return -1;
}

void hacerFactura(Cliente cli, Surtidor sur, bool mostrar, bool cobrar){
    Factura aux;
    Recibo rc;

    aux.Facturar(cli, sur);
    if(aux.Guardar()){
        if(mostrar){
            system("cls");
            aux.MostrarFactura();
            system("pause");
        }
        if(cobrar){
            rc.cargarRecibo(aux.getNumFac());
            rc.Guardar();
            aux.modificarSaldo(rc);
            cout << " COBRADO ( HACER LINDO RECIBO )" << endl;
            system("pause");
        }
    }
    else {
        cout << "ERROR EN EL GUARDDO " << endl;
        system("pase");
    }

}

bool situacionCliente(Cliente cli, float importe){
    //// TRUE => MOSTRAR Y COBRAR
    if(cli.getID() != 1){
        if(cli.getEstadoCliente() == true){
            if(cli.getCuentaCorriente() == true){
                if((cli.getLimiteCredito() - deudaxCliente(cli) + saldoSinAplicarPorCliente(cli)) >= importe){
                    return false;
                }
            }
        }
    }
    return true;
}

int seleccionarNafta()
{
    Nafta naf;
    int id, pos;
    bool ok;

    do
    {
        system("cls");
        cout << endl;
        cout << " ID NAFTA: ";
        cin >> id;

        if((pos = naf.BuscarID(id)) > -1)
        {
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

    }
    while(ok);
    return -1;
}



///===============================
///  FUNIONES PARA COBRANZAS
///===============================

void menuCobranzas(){

    int opc;

    do
    {
        system("cls");
        cout << endl;
        cout << " ========================= " << endl;
        cout << "         COBRANZA          " << endl;
        cout << " ========================= " << endl;
        cout << " (1) DEUDA POR CLIENTE     " << endl;
        cout << " (2) HACER RECIBO          " << endl;
        cout << " (3) FACTURAS (TODAS)      " << endl;
        cout << " (4) VER RECIBOS           " << endl;
        cout << "===========================" << endl;
        cout << " (0) SALIR                 " << endl;
        cout << " >> ";
        cin >> opc;
        system("cls");

        switch(opc)
        {
        case 1:
            deudaCli();
            break;
        case 2:
            hacerPago();
            break;
        case 3:
            mostFacturas();
            break;
        case 4:
            mostrarRecibos();
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
        cout << " (4) MOSTRAR TODOS         " << endl;
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
        case 4:
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

void menuInfores()
{
    int opc;
    do
    {
        cout << endl;
        cout << "         INFORMES          " << endl;
        cout << "===========================" << endl;
        cout << " (1) VENTAS                " << endl;
        cout << " (2) COMBUSTIBLE           " << endl;
        cout << " (3) TANQUES               " << endl;
        cout << " (0) SALIR                 " << endl;
        cout << "===========================" << endl;
        cout << " >> ";
        cin >> opc;
        system("cls");

        switch(opc)
        {
        case 1:

            break;
        case 2:
            informeCombustibles();
            break;
        case 3:

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

void informeCombustibles()
{

    Nafta aux;
    int pos = 0;

    int *vecIDNaft = NULL;
    float *vecDisponible = NULL;
    float *vecLitros = NULL;

    int TAM = aux.CantCombustible();

    vecIDNaft = new int [TAM];
    vecDisponible = new float [TAM];
    vecLitros = new float [TAM];

    if(vecIDNaft == nullptr)
    {
        cout << "NO MEMORIA VEC NAFTA" << endl;
        system("pause");
        return;
    }

    if(vecDisponible == nullptr)
    {
        cout << "NO MEMORIA VEC DISPONIBLE" << endl;
        system("pause");
        return;
    }
    if(vecLitros == nullptr)
    {
        cout << "NO MEMORIA VEC LITROS" << endl;
        system("pause");
        return;
    }

    for(int i=0; i<TAM; i++)
    {
        vecLitros[i] = 0;
        vecDisponible[i] = 0;
    }

    while(aux.LeerDeDisco(pos++))
    {
        vecIDNaft[pos-1] = aux.getIDtipoDeNafta();
    }

    TanqueManager tanMan;

    for(int i=0; i<TAM; i++)
    {
        vecDisponible[i] = tanMan.DisponibleAllenarxNafta(vecIDNaft[i]);
        vecLitros[i] = tanMan.DisponiblexCombustible(vecIDNaft[i]);
    }

    cout << left;
    cout << setw(4) <<" ID ";
    cout << setw(10) << " NOMBRE ";
    cout << setw(10) << " CAPACIDAD ";
    cout << setw(10) << " LITROS " << endl;
    cout << " ======================================================== " << endl;

    for(int i=0; i<TAM; i++)
    {
        cout << left;
        cout << setw(4) << vecIDNaft[i];
        aux.BuscarID(vecIDNaft[i]);
        cout << setw(10) << aux.getnombreDeCombustible();
        cout << right << fixed << setprecision(2);
        cout << setw(10) << vecDisponible[i];
        cout << setw(10) << vecLitros[i] << endl;
    }
    delete vecIDNaft;
    delete vecDisponible;
    delete vecLitros;
}


