#include <iostream>

using namespace std;
#include "Funciones.h"


int main(){
    while (true){
        int opc;
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
                clientes();
                break;
            case 2:
                //ventas();
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
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





