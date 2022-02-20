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
    _Paga = false;
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
    p = fopen("Facturas.dat", "rb");

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


void Factura::Facturar (Cliente cli,Nafta naf,Surtidor sur)
{

    setCliente(cli);
    _Fecha.FechaActual();

    _NumFac = (CantFactura()+1);
    _IDnaft = naf.getIDtipoDeNafta();
    _Precio = naf.getprecio();
    strcpy (_Descripcion,naf.getnombreDeCombustible());
    _IDsurtidor = sur.getIDsurtidor();
    _Litros = sur.getLitros();
    _Saldo = _Total = _Litros * _Precio;
    _Paga = false; /// ANTES DE GUARDAR LA FACTURA CONSULTAR SI PAGO O NO
}


void Factura::MostrarFactura()
{
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

void Factura::modificarSaldo (Recibo r)
{
    int i;
    int pos = 0;

    for(i=0; i<r.getTam(); i++)
    {
        if(r.getNumFactura()[i] != 0)
        {
            pos = buscarPorNumero(r.getNumFactura()[i]);
                  if(pos > 0)
            {
                _Saldo -= r.getImportePago()[i];
                if(_Saldo == 0)
                {
                    _Paga = true;
                }

                modificardeDisco(pos);
            }
        }
    }
}



int Factura::buscarPorNumero (int num)
{
    int pos = 0;

    while(LeerDeDisco(pos))
    {
        if(num == _NumFac)
        {
            return pos;
        }
        pos++;
    }
    return -1;
}

bool Factura::modificardeDisco(int pos)
{
    FILE *p;
    p = fopen("Factura.dat","rb+");                   ///ABRE EL ARCHIVO DESDE 0 Y PUEDE ESCRIBIR Y MODIFICAR.

    if (p == NULL)
    {
        return false;
    }

    fseek(p, sizeof(Factura)*pos, SEEK_SET);         ///posiciona el PUNTEOR / CABEZAL en la direcion que se le mando.

    if(fwrite(this, sizeof(Factura), 1, p))
    {
        fclose(p);
        return true;                                ///SI SE ABRE CONFIRMA /// el mensaje fuera de la clase
    }
    else
    {
        fclose(p);
        return false;                               ///SI NO SE ABRE NIEGA /// el mensaje fuera de la clase
    }
}

