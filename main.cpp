#include <string>
#include "estacion.cpp"

int main()
{
  Estacion estacion1(std::string("Estacion del Pacifico"));
  Tren tren1(&estacion1, 100);
  Mapa mapa;
  mapa.imprimirNombre(&estacion1);
}