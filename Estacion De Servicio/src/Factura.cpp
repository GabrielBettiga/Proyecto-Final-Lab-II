#include "Factura.h"

#include <cstdio>
#include <iostream>
using namespace std;
Factura::Factura()
{
    setTipoDocumento('F');

    _NumFac = 0;
    _IDnaft = 0;
    _Precio = 0;
    strcpy(_Descripcion, "SIN DATOS");
    _IDsurtidor = 0;
    _Litros = 0;
    _Total = 0;
    _Saldo = 0;
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

    setCliente(cli);
    _Fecha.FechaActual();

    _NumFac = CantFactura()+1;
    _IDnaft = naf.getIDtipoDeNafta();
    _Precio = naf.getprecio();
    strcpy (_Descripcion,naf.getnombreDeCombustible());
    _IDsurtidor = sur.getIDsurtidor();
    _Litros = litros;                                       ///VER XQ SE PASAN LOS LITROS SOLOS ????
    _Saldo = _Total = _Litros * _Precio;
    _Paga = false; /// ANTES DE GUARDAR LA FACTURA CONSULTAR SI PAGO O NO
}


void Factura::MostrarFactura(){
    Documento::mostrarDocumento();
    cout << "FATURA N   : " << _NumFac << endl;
    cout << "SURTIDOR N : " << _IDsurtidor << endl;
    cout << "COD. NAFTA : " << _IDnaft << endl;
    cout << "PRODUCTO   : " << _Descripcion << endl;
    cout << "$ X LITROS : $ " << _Precio << endl;
    cout << "LITROS     : " << _Litros << endl;
    cout << "TOTAL      : $ " << _Total << endl;
    cout << "SALDO      : " << _Saldo << endl;


}
