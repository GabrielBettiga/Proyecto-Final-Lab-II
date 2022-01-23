#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;
#include "TanqueManager.h"
#include "Surtidor.h"
#include "Nafta.h"


int main()
{
Surtidor A;
Nafta B;
TanqueManager C;
float Pesos,Litro;
int IDnaf;

/*
 B.Cargar(); ///NAFTA
  B.GrabarEnDisco();

  C.CrearTanque(); ///TANQUE
  C.Cargar();
  C.Guardar();
*/
///A.CrearSurtidor();
/*  cout<<"INGRESE PESOS: "<<endl;
  cin>>Pesos;
  cout<<"INGRESE tipo nafta: "<<endl;
  cin>>IDnaf;
Litro=A.CombertirLitros(IDnaf,Pesos);
A.MostraCarga(A.Cargar(IDnaf,Litro),IDnaf,Litro);
*/
cout<<"INGRESE LITROS: "<<endl;
  cin>>Litro;
  cout<<"INGRESE tipo nafta: "<<endl;
  cin>>IDnaf;
A.MostraCarga(A.Cargar(IDnaf,Litro),IDnaf,Litro);



cout<<"===================="<<endl;
int pos=0;
while (C.leerdeDisco(pos)){C.Mostrar(); pos++;cout<<"===================="<<endl;}

/*
int pos=0;
while (B.LeerDeDisco(pos)){cout<<pos<<endl;B.Mostrar();
cout<<endl;pos++;}
*/
return 0;
}


