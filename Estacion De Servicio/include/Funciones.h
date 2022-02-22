#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <iomanip>
#include "Cliente.h"
#include "Nafta.h"
#include "Surtidor.h"
#include "TanqueManager.h"
#include "Factura.h"
#include "Recibo.h"

bool archivos(const int TAM, bool *vec);
bool configuracion();
bool controlBanderas(const int T, bool *vec);
bool cargarTanques();
bool cargarSurtidores();
bool cargaConsumidorFinal();

///===============================
///  FUNIONES PARA CLEINTES
///===============================
void menuClientes();
void cargarCliente();
void mostrarCliente();
void mostrarTodosClientes();
void modificarCliente();

///===============================
///  FUNIONES PARA VENTAS
///===============================
void venta();
Surtidor cargarCombustible();
int seleccionarNafta();
int seleccionarClietete();
int seleccionarSurtidor();
void hacerFactura(Cliente cli, Surtidor sur, bool mostrar = false, bool cobrar = false);

///===============================
///  FUNIONES PARA COBRANZAS
///===============================
void menuCobranzas();
void listFacCli(Cliente cli, bool estado);
float deudaxCliente(Cliente cli);
void deuda();
void hacerPago();
void emitirRecibo();



///===============================
///  FUNIONES PARA COMUSTIBLES
///===============================
void menuCombustibles();
void altaCombustible();
void mostrarCombustible();
void mostrarTodosCombustibles();
void modificarCombustible();

///===============================
///  FUNIONES PARA TANQUES
///===============================
void menuTanques();
void mostrarTodosLosTanques();
void mostrarTanque();
bool asignarNafta();
void ingresarCombustible();
void vaciarTanque();
///===============================
///  FUNIONES PARA INFORMES
///===============================
void menuInfores();

void informeCombustibles();


#endif // FUNCIONES_H_INCLUDED
