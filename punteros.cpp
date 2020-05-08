#include <iostream>
using namespace std;

int crearNumero()
{
    // Esta funcion puede ser compleja y tomar datos
    // que no se conocen al momento de compilación.
    // Por ejemplo, podría leerlos de un archivo.
    int numero = 5;
    return numero;
}

void imprimir(int *numero)
{
    if (numero != nullptr)
    {
        cout << *numero << "\n";
    }
}

void mainPunteros()
{
  int *puntero = nullptr;
  imprimir(puntero); // No imprime
  int valor = crearNumero();
  puntero = &valor;
  imprimir(puntero); // Imprime 5
}
