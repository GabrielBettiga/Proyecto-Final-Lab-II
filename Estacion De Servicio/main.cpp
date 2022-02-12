#include <iostream>

using namespace std;
#include "Funciones.h"


int main(){

    if(configuracion() != true){
        return 0;
    }

    while (true){
        int opc;
        system ("cls");
        cout << "      MENU PRINCIPAL       " << endl;
        cout << "===========================" << endl;
        cout << " 1 > CLIENTES              " << endl;
        cout << " 2 > VENTAS                " << endl;
        cout << " 3 > COBRANZAS             " << endl;
        cout << " 4 > COMBUSTIBLES          " << endl;
        cout << " 5 > INFORMES              " << endl;
        cout << "===========================" << endl;
        cout << " 0 > SALIR                 " << endl;
        cout << " >> ";
        cin >> opc;
        system ("cls");

        switch(opc){
            case 1:
                menuClientes();
                break;
            case 2:
                venta();
                break;
            case 3:
                /// COBRANZAS
                break;
            case 4:
                menuCombustibles();
                break;
            case 5:
                /// INFORMES
                break;
            case 0:
                cout << "== FIN ==" << endl;
                return 0;
                break;
            default:
                cout << "====================" << endl;
                cout << " OPCION INCORRECTA  " << endl;
                cout << "====================" << endl;
                system("pause");
                system ("cls");
                break;
        }
    }

return 0;
}





