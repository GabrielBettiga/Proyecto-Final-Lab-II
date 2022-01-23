#ifndef FECHA_H
#define FECHA_H


class Fecha
{
    protected:
        int _Dia,_Mes,_Anio,_Horas,_Minutos;
    public:
        Fecha();

       int getDia () {return _Dia;}
       void setDia (int x){_Dia=x;}

       int getMes () {return _Mes;}
       void setMes (int x) {_Mes=x;}

       int getAnio () {return _Anio;}
       void setAnio (int x) {_Anio=x;}

       int getHoras(){return _Horas;}
       void setHoras(int x){_Horas=x;}

       int getMinutos(){return _Minutos;}
       void setMinutos(int x){_Minutos=x;}


       //void Cargar ();
       void Mostrar ();
};

#endif // FECHA_H
