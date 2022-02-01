#ifndef FECHA_H
#define FECHA_H

bool esCorrecta(int dia, int mes, int anio);
bool esBisiesto(int a);

class Fecha
{
    protected:
        int _dia,_mes,_anio,_horas,_minutos;
    public:
        Fecha();
        int getDia () {return _dia;}
        int getMes () {return _mes;}
        int getAnio () {return _anio;}
        int getHoras(){return _horas;}
        int getMinutos(){return _minutos;}

        bool operator <= (Fecha aux);
        void fechaSinDatos();

        bool cambiarFecha(int dia, int mes, int anio);

        void FechaActual();
        void MostrarFecha();
        void MostrarHora();
};

#endif // FECHA_H
