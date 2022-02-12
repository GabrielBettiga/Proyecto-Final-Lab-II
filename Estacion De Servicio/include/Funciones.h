#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include "Cliente.h"
#include "Nafta.h"

bool configuracion();
bool controlBanderas(const int tam, bool *vec);

///===============================
///  FUNIONES PARA CLEINTES
///===============================
void menuClientes();
void cargarCliente();
void mostrarCliente();
void mostrarTodosClientes();
void modificarCliente();
Cliente datoModificar(Cliente cli);

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
///  FUNIONES PARA INFORMES
///===============================


#endif // FUNCIONES_H_INCLUDED
