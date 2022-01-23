#include "Factura.h"

#include <cstdio>
#include <iostream>
using namespace std;
Factura::Factura()
{
    _IDcliente=0;
    _IDnaft=0;
    _NumFac=0;
    _IDsurtidor=0;
    _Litros=0;
    _Precio=0;
    _Total=0;
    _Paga=false;
}

bool Factura::Guardar()
{
    FILE *p;
    bool Escribio;

    p=fopen("Facturas.dat","ab");
    if (p==NULL)
    {
        cout<<"NO SE PUDO ABRIR/CREAR EL ARCHIVO"<<endl;
        return false;
    }

    Escribio=fwrite(this,sizeof(Factura),1,p);

    fclose (p);

    return Escribio;

}

bool Factura::LeerDeDisco(int pos)
{
    FILE *p;
    bool Leyo;

    p=fopen("Facturas.dat","rb");

    if (p==NULL)
    {
        return false;
    }


    fseek (p,sizeof(Factura)*pos,0);

    Leyo=fread(this,sizeof(Factura),1,p);

    fclose(p);

    return Leyo;

}



int Factura::CantFactura()
{
    int bytes, cant;

    FILE *p;
    p = fopen("Factura.dat", "rb");

    if (p == NULL)
    {
        return 0;
    }

    fseek(p, 0, SEEK_END);///Lo posiciona en el final
    bytes = ftell(p);
    fclose(p);
    cant = bytes / sizeof(Factura);
    return cant;
}


void Factura::Facturar (Cliente cli,Nafta naf,Surtidor sur,float litros){
    _Fecha.FechaActual();
    _NumFac=CantFactura()+1;
    _IDcliente=cli.getID();
    _IDnaft=naf.getIDtipoDeNafta();
    strcpy (_Descripcion,naf.getnombreDeCombustible());
    _Precio=naf.getprecio();
    _IDsurtidor=sur.getIDsurtidor();
    _Litros=litros;
    _Total=_Litros*_Precio;
    _Paga=false; /// ANTES DE GUARDAR LA FACTURA CONSULTAR SI PAGO O NO

}


void Factura::Mostrar(){
    cout<<"Fecha: ";
    _Fecha.Mostrar();
    cout<<"Factura N: "<<_NumFac<<endl;
    cout<<"Surtidor N: "<<_IDsurtidor<<endl;
    cout<<"Codigo De Nafta: "<<_IDnaft<<endl;
    cout<<"Producto: "<<_Descripcion<<endl;
    cout<<"Precio Por Litro: $"<<_Precio<<endl;
    cout<<"Litros: "<<_Litros<<endl;
    cout<<"TOTAL FACTURA: $"<<_Total<<endl;


}
