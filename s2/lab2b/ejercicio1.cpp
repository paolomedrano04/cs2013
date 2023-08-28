//El código que compartiste es un programa en C++ que muestra un ejemplo de un videojuego
// donde los personajes tienen puntos de vida y pueden ser curados utilizando diferentes tipos de objetos.
//
// Datos de Entrada:
// En primer lugar, se definen las estructuras Item, Carne, Agua y Magia.
// La estructura Item es una clase abstracta que tiene:
// 1. Una variable de vida
// 2. Función virtual usar() que debe ser implementada por las clases derivadas.
// Subclases:
// 1. Carne
// 2. Agua
// 3. Magia son subclases de Item.
// Cada una de ellas inicializa la variable de vida se acuerdo a su tipo.
// Además, cada una de estas clases implementa la función usar() que imprime un mensaje indicando:
// 1. El tipo de objeto.
// 2. Los puntos de vida que se ganan al usarlo.
//
// Luego, se define la clase Pj (personaje) que tiene variables:
// STRING ->Nombre
// STRING ->raza
// INT -> vida
// INT -> ataque.
// En el constructor de la clase Pj, se inicializan estas variables y también se definen los operadores:
// + : un personaje pueda obtener los beneficios de usar un objeto.
//     Recibe un objeto Item por referencia y llama a la función curar() del personaje,
//     pasándole el objeto como argumento.
// >>: Un personaje pueda transferir vida a otro personaje.
//     Recibe una referencia a otro objeto Pj y trasfiere la mitad de la vida actual del personaje a ese objeto.
//
// Luego, se sobrecarga el operador de inserción << en la clase Pj. Esto permite imprimir los detalles del personaje utilizando el operador de flujo cout.
// FUNCIONES:
//1. En la función curar() de la clase Pj, se imprime un mensaje indicando el nombre del personaje y el objeto que está utilizando. A continuación, se incrementa la vida del personaje sumando los puntos de vida del objeto utilizado.
//2. En la función main(), se crean tres personajes (pj1, pj2, pj3) y tres objetos (carne, agua, magia).
// Luego, se imprime la información de los personajes utilizando el operador <<.
// Después, cada personaje utiliza un objeto para curarse llamando a la función curar(). Finalmente, se vuelve a imprimir la información de los personajes.
// Datos de Salida : mostrará la información de los personajes antes y después de ser curados, con los puntos de vida actualizados.
//
//
//
#include <iostream>

using namespace std;

struct Item{
    int vida;
    virtual void usar() = 0;
};

struct Carne: public Item{
    Carne(): Item(){this->vida = 10;};
    void usar(){cout << "Carne (+10)" << endl;};
};

struct Agua: public Item{
    Agua(): Item(){this->vida = 5;};
    void usar(){cout << "Agua (+5)" << endl;};
};

struct Magia: public Item{
    Magia(): Item(){this->vida = 8;};
    void usar(){cout << "Magia (+8)" << endl;};
};

class Pj{
friend ostream& operator<<(ostream& os, const Pj& pj);
private:
    string nombre;
    string raza;
    int vida;
    int ataque;
public:
    Pj(string n, string r, int v, int a): nombre(n), raza(r), vida(v), ataque(a){};
    void operator+(Item& item);
    void operator>>(Pj& pj);
    void curar(Item& item);
};

ostream& operator<<(ostream& os, const Pj& pj){
    os << "----------------------------------------" << endl;
    os << "Name: " << pj.nombre << endl;
    os << "Type:  " << pj.raza << endl;
    os << "Vida: " << pj.vida << endl;
    os << "Ataque: " << pj.ataque << endl;
    os << "----------------------------------------" << endl;
    return os;
}

void Pj::curar(Item& item){
    cout << "----------------------------------------" << endl;
    cout << this->nombre << " se cura con ";
    item.usar();
    cout << "----------------------------------------" << endl;
    this->vida += item.vida;
}

int main(){
    Pj pj1("Orgrim", "Orco", 100, 20);
    Pj pj2("Legolas", "Elfo", 60, 35);
    Pj pj3("Aragorn", "Humano", 80, 25);

    Carne carne;
    Agua agua;
    Magia magia;

    cout << pj1 << pj2 << pj3;

    pj1.curar(carne);
    pj2.curar(magia);
    pj3.curar(agua);

    cout << pj1 << pj2 << pj3;

    return 0;
}
    
