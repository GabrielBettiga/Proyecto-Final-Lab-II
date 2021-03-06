#include "Nafta.h"


///COSTRUCTOR
///========================================================================================================

Nafta::Nafta(int IDtipoDeNafta, const char *nombreDeCombustible, float precio)
{
    _IDtipoDeNafta=IDtipoDeNafta;
    strcpy (_nombreDeCombustible,nombreDeCombustible);
    _precio=precio;
}

///METODOS
///========================================================================================================

void Nafta::Cargar ()
{
    float precio;

    setIDtipoDeNafta (CantCombustible()+1);
    cout<<" NOMBRE   : ";
    cin>> _nombreDeCombustible;
    cout<<" PRECIO   : ";
    cin>> precio;
    setprecio (precio);
}

void Nafta::Mostrar ()
{
    cout<<" ID COMB  : "<<_IDtipoDeNafta<<endl;
    cout<<" NOMBRE   : "<<_nombreDeCombustible<<endl;
    cout<<" PRECIO   : "<<_precio;
}

void Nafta::modificarNafta(){
    int opc;
    string nombre;
    float precio;

    do{
        // system("cls");
        cout << " DATO A MODIFICAR  " << endl;
        cout << "===================" << endl;
        cout << " (1) NOMBRE.       " << endl;
        cout << " (2) PRECIO.       " << endl;
        cout << " (0) SALIR.        " << endl;
        cout << "===================" << endl;
        cout << " >> ";
        cin >> opc;

        switch(opc){
        case 1:
            system("cls");
            cout << " NOMBRE : ";
            cin >> nombre;
            setnombreDeCombustible(nombre);
            break;
        case 2:
            system("cls");
            cout << " PRECIO : ";
            cin >> precio;
            setprecio(precio);
            break;
        case 0:
            return;
            break;
        default:
            cout << endl;
            cout << " OPCION INCORECTA " << endl;
            cout << endl;
            system("pause");
            system("cls");
        }
    }while(opc != 0);
}



///DISCO
///========================================================================================================
bool Nafta::GrabarEnDisco()
{
    FILE *p;
    bool Escribio;

    p=fopen("Combustibles.dat","ab");
    if (p==NULL)
    {
        cout<<"NO SE PUDO ABRIR/CREAR EL ARCHIVO"<<endl;
        return false;
    }

    Escribio=fwrite(this,sizeof(Nafta),1,p);

    fclose (p);

    return Escribio;

}



bool Nafta::LeerDeDisco(int pos)
{
    FILE *p;
    bool Leyo;

    p=fopen("Combustibles.dat","rb");

    if (p==NULL)
    {
        return false;
    }


    fseek (p,sizeof(Nafta)*pos,0);

    Leyo=fread(this,sizeof(Nafta),1,p);

    fclose(p);

    return Leyo;

}


bool Nafta::ModificarEnDisco(int pos)
{
    FILE *p;
    bool Modifico;

    p=fopen("Combustibles.dat","rb+");
    if (p==NULL)
    {
        cout<<"NO SE PUDO ABRIR/CREAR EL ARCHIVO"<<endl;
        return false;
    }

    fseek(p,sizeof(Nafta)*pos,0);

    Modifico=fwrite(this,sizeof(Nafta),1,p);

    fclose (p);

    return Modifico;

}


int Nafta::BuscarID(int NuevaID)
{
    int pos=0;
    while (LeerDeDisco(pos++))
    {
        if (_IDtipoDeNafta==NuevaID)
        {
            return pos-1;
        }



    }

return -1;
}

int Nafta::CantCombustible()
{
    int bytes, cant;

    FILE *p;
    p = fopen("Combustibles.dat", "rb");

    if (p == NULL)
    {
        return 0;
    }

    fseek(p, 0, SEEK_END);///Lo posiciona en el final
    bytes = ftell(p);
    fclose(p);
    cant = bytes / sizeof(Nafta);
    return cant;
}
