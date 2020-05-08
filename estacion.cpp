#include <string>
#include <iostream>
using namespace std;

namespace estacion
{
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
    Tren(Estacion *parametro, int numero)
    {
        this->estacionActual = parametro;
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

void main()
{
    Estacion estacion1(std::string("Estacion del Atlantico"));
    Tren tren1(&estacion1, 100);
    Mapa mapa;
    mapa.imprimirNombre(&estacion1);
}
} // namespace estacion