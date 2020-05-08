#include <iostream>
using namespace std;

template <class T>
// T es el parámetro de tipo. Dentro de la definición de la clase,
// T funciona como un tipo (como int, o char).
class Nodo
{
private:
    T valor;
    Nodo<T> *siguiente; // Nótese que el puntero es a un nodo del mismo tipo.
public:
    Nodo<T>(T valor)
    {
        this->siguiente = nullptr;
        this->valor = valor;
    }

    ~Nodo<T>()
    {
        if (siguiente != nullptr)
        {
            delete siguiente;
        }
    }

    void establecerSiguiente(Nodo<T> *nodo)
    {
        siguiente = nodo;
    }

    Nodo<T> *obtenerSiguiente()
    {
        return siguiente;
    }

    T obtenerValor()
    {
        return valor;
    }
};

template <class T>
class Lista
{
private:
    Nodo<T> *inicial; // Nótese que el puntero es a un nodo del mismo tipo.
public:
    Lista<T>()
    {
        inicial = nullptr;
    }

    ~Lista<T>()
    {
        if (inicial != nullptr)
        {
            delete inicial;
        }
    }

    bool buscar(T valor)
    {
        Nodo<T> *actual = inicial;
        while (actual != nullptr)
        {
            if (actual->obtenerValor() == valor)
            {
                return true;
            }
            actual = actual->obtenerSiguiente();
        }
        return false;
    }

    void agregar(T valor)
    {
        Nodo<T> *nuevo = new Nodo<T>(valor);
        Nodo<T> *actual = inicial;
        if (actual == nullptr)
        {
            inicial = nuevo;
        }
        else
        {
            while (actual->obtenerSiguiente() != nullptr)
            {
                actual = actual->obtenerSiguiente();
            }
            actual->establecerSiguiente(nuevo);
        }
    }

    void eliminar(T valor)
    {
        if (inicial == nullptr)
        {
            return;
        }
        if (inicial->obtenerValor() == valor)
        {
            Nodo<T> *temp = inicial;
            inicial = inicial->obtenerSiguiente();
            temp->establecerSiguiente(nullptr);
            delete temp;
            return;
        }

        Nodo<T> *anterior = inicial;
        Nodo<T> *actual = inicial->obtenerSiguiente();
        while (actual != nullptr)
        {
            if (actual->obtenerValor() == valor)
            {
                anterior->establecerSiguiente(actual->obtenerSiguiente());
                actual->establecerSiguiente(nullptr);
                delete actual;
                return;
            }
            else
            {
                anterior = actual;
                actual = actual->obtenerSiguiente();
            }
        }
    }
};

namespace listas
{
void main()
{
    Lista<int> lista;
    cout << lista.buscar(10); // Imprime false
    lista.agregar(1);
    lista.agregar(2);
    lista.agregar(3);
    cout << lista.buscar(2); // Imprime true
    cout << lista.buscar(5); // Imprime false
    lista.eliminar(2);
    cout << lista.buscar(2); // Imprime false
}
} // namespace listas