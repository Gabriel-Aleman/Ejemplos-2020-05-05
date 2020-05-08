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

namespace estacion
{
  void main()
  {
    Estacion estacion1(std::string("Estacion del Pacifico"));
    Tren tren1(&estacion1, 100);
    Mapa mapa;
    mapa.imprimirNombre(&estacion1);
  }
}