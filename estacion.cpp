#include <string>
#include <iostream>
using namespace std;

class Estacion
{
private:
    string nombre;

public:
    Estacion(string nombre)
    {
        this->nombre = nombre;
    }

    string obtenerNombre()
    {
        return nombre;
    }
};

class Tren
{
private:
    int numero;
    Estacion *estacionActual;

public:
    Tren(Estacion *estacionActual, int numero)
    {
        this->estacionActual = estacionActual;
        this->numero = numero;
    }
};

class Mapa
{
public:
    void imprimirNombre(Estacion *estacion)
    {
        cout << estacion->obtenerNombre() << "\n";
    }
};