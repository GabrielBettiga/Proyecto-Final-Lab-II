#include <iostream>
using namespace std;

#include "TanqueManager.h"

///=================================================
/// METODOS
///=================================================

///LOGICA
///=================

void TanqueManager::CrearTanque(){
    _aux.setID(CantTanques()+1);
}

int TanqueManager::CantTanques(){
    int bytes, cant;

    FILE *p;
    p = fopen("Tanques.dat", "rb");

    if (p == NULL){
        return 0;
    }

    fseek(p, 0, SEEK_END);
    bytes = ftell(p);
    fclose(p);
    cant = bytes / sizeof(Tanque);
    return cant;
}

bool TanqueManager::CargarTanques(int IDNafta, float litros){

    if( DisponibleAllenarxNafta(IDNafta)>= litros && litros > 0){
        DistribuirNaftaTanques(IDNafta, litros);
        return true;
    }
    else {
        return false;
    }
}

float TanqueManager::DisponibleAllenarxNafta(int IDNafta){
    int pos = 0;
    float cantidad = 0;
    while(leerdeDisco(pos)){
        if( _aux == IDNafta){                           /// == OPERADOR SOBRECARGA EN CLASE TANQUE
            cantidad += _aux.getDisponible();
        }
 pos++;   }
    return cantidad;                                    ////LA CANTIDAD DE LITROS Q PUEDE ENTRAR X NAFTA EN LOS TANQUES
}

void TanqueManager::DistribuirNaftaTanques(int IDNafta,float litros){

    ///CARGA LOS TANQUES A SU MAXIMA CAP X COMBUSTIBE, DESCONTANDO DEL TOTAL DE LITROS ENVIDOS A CARGAR.
    ///LITROS ES EL DESACUMULADOR

    int pos = 0;
    while (leerdeDisco(pos++)){
        if( _aux == IDNafta && litros > 0){             /// == OPERADOR SOBRECARGA EN CLASE TANQUE

            if(_aux.getDisponible() <= litros){         ///CONSULTA EL DISPNIBLE DEL TANQUE

                float cargo = 0;
                cargo = _aux.getDisponible();           ///GUARDAMOS LO Q LE VAMOS A DESCONTAR A LITROS

                if(_aux.Llenar(_aux.getDisponible())){  ///LLENAMOS EL TANQUE CON EL Q ESTAMOS TRABAJANDO

                    litros = litros - cargo;            ///DESCONTAMOS DE LISTROS
                    modificardeDisco(pos-1);            ///GUARDAMOS X TANQUE
                }
            }
            else {

                _aux.Llenar(litros);
                litros = litros - litros;
                modificardeDisco(pos-1);
                return;
            }
        }
    }
}

bool TanqueManager::Surtidor (int IDNafta, float litros){
    if(DisponiblexCombustible(IDNafta) >= litros && litros > 0){
        AcomodarTanque(IDNafta, litros);
        return true;
    }
    else {
        return false;
    }

}

float TanqueManager::DisponiblexCombustible(int IDNafta){
    int pos = 0;
    float cantidad = 0;
    while(leerdeDisco(pos++)){
        if( _aux == IDNafta){                           /// == OPERADOR SOBRECARGA EN CLASE TANQUE
            cantidad += _aux.getOcupacion();
        }
    }
    return cantidad;
}

void TanqueManager::AcomodarTanque(int IDNafta,float litros){
    int pos = 0;
    while (leerdeDisco(pos++)){
        if( _aux == IDNafta && litros > 0){             /// == OPERADOR SOBRECARGA EN CLASE TANQUE

            if(_aux.getOcupacion() >= litros){
                _aux.DescontarLitros(litros);
                modificardeDisco(pos-1);
                return;
            }
            else {
                float cant = _aux.getOcupacion();
                _aux.DescontarLitros(_aux.getOcupacion());
                modificardeDisco(pos-1);
                litros -= cant;
            }
        }
    }
}

float TanqueManager::vaciarTanque(){

return _aux.VaciarTodo();

}

int TanqueManager::BuscarIDtanque (int IDTanque){

    int pos = 0;

    while(leerdeDisco(pos++)){
        if(_aux.getIDtanque() == IDTanque){
            return pos-1;
        }
    }
    return -1;
}

void TanqueManager::setCapacidad(float litros){
    _aux.setCapacidadMaxima(litros);
}
void TanqueManager::setDisponible (){

_aux.setDisponible();

}

void TanqueManager::setID (int id){
    _aux.setID(id);
}

int TanqueManager::getID (){


return _aux.getIDtanque();
}

float TanqueManager::getCapacidad(){



return _aux.getCapacidad();
}

void TanqueManager::setIDNafta (int x){

    _aux.setIDnafta(x);
}

Tanque TanqueManager::getTanque (){

return _aux;

}

///USUARIO
///=================

/*void TanqueManager::Cargar(){

    float CapMax, Ocup;
    int idNafta;

    cout << "ID NAFTA: ";
    cin >> idNafta;
    cout << "CAPACIDAD MAXIMA: ";
    cin >> CapMax;
    cout << "OCUPACION: ";
    cin >> Ocup;

    _aux.setIDnafta(idNafta);
    _aux.setCapacidadMaxima(CapMax);
    _aux.setOcupacion(Ocup);
    _aux.setDisponible(0);
}*/

void TanqueManager::Mostrar(){
    Nafta aux;

    cout << "ID TANQUE  : ";
    cout << _aux.getIDtanque() << endl;
    cout << "ID NAFTA   : ";
    cout << _aux.getIDnafta()  << endl;
    if(aux.BuscarID(_aux.getIDnafta()) != -1){
        cout << "NOMBRE     : ";
        cout << aux.getnombreDeCombustible() <<endl;
    }
    cout << "MAXIMA CAP : ";
    cout << _aux.getCapacidad() << endl;
    cout << "OCUPACION  : ";
    cout << _aux.getOcupacion() << endl;
    cout << "DISPONIBLE : ";
    cout << _aux.getDisponible() << endl;
}

///=================================================
/// ARCHIVOS
///=================================================
bool TanqueManager::crearArchivo(){
    FILE *p;
    p = fopen("Tanques.dat", "wb");                  ///DESTRUYE E ARCHIVO, LO CREA SI NO EXISTE

    if(p == NULL){
        return false;
    }

    if(fwrite(this, sizeof(Tanque), 1, p)){         ///ESCRIBE EL ARCHIVO.
        fclose(p);
        return true;                                ///SI SE GUARDA CONFIRMA /// el mensaje fuera de la clase
    }
    else{
        fclose(p);
        return false;                               ///SI NO SE GUARDA NIEGA /// el mensaje fuera de la clase
    }
}
bool TanqueManager::Guardar(){
    FILE *p;
    p = fopen("Tanques.dat", "ab");                  ///ABRE EL ARCHIVO DESDE EL FINAL, SI NO EXISTE LO CREA.

    if(p == NULL){
        return false;
    }

    if(fwrite(this, sizeof(Tanque), 1, p)){         ///ESCRIBE EL ARCHIVO.
        fclose(p);
        return true;                                ///SI SE GUARDA CONFIRMA /// el mensaje fuera de la clase
    }
    else{
        fclose(p);
        return false;                               ///SI NO SE GUARDA NIEGA /// el mensaje fuera de la clase
    }
}

bool TanqueManager::leerdeDisco(int pos){
    FILE *p;
    p = fopen("Tanques.dat","rb");                   ///abre el archivo desde el byte 0.

    if (p == NULL){
        return false;
    }

    fseek(p, sizeof(Tanque)*pos, SEEK_SET);         ///posiciona el PUNTEOR / CABEZAL en la direcion que se le mando.

    if(fread(this, sizeof(Tanque), 1, p)){
        fclose(p);
        return true;                                ///SI SE ABRE CONFIRMA /// el mensaje fuera de la clase
    }
    else{
        fclose(p);
        return false;                               ///SI NO SE ABRE NIEGA /// el mensaje fuera de la clase
    }
}
bool TanqueManager::modificardeDisco(int pos){
    FILE *p;
    p = fopen("Tanques.dat","rb+");                   ///ABRE EL ARCHIVO DESDE 0 Y PUEDE ESCRIBIR Y MODIFICAR.

    if (p == NULL){
        return false;
    }

    fseek(p, sizeof(Tanque)*pos, SEEK_SET);         ///posiciona el PUNTEOR / CABEZAL en la direcion que se le mando.

    if(fwrite(this, sizeof(Tanque), 1, p)){
        fclose(p);
        return true;                                ///SI SE ABRE CONFIRMA /// el mensaje fuera de la clase
    }
    else{
        fclose(p);
        return false;                               ///SI NO SE ABRE NIEGA /// el mensaje fuera de la clase
    }
}


