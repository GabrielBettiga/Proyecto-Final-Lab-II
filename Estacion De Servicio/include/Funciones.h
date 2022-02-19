#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include "Cliente.h"
#include "Nafta.h"
#include "Surtidor.h"
#include "TanqueManager.h"

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
///===============================
///  FUNIONES PARA COBRANZAS
///===============================

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


#endif // FUNCIONES_H_INCLUDED
