#include <iostream>

using namespace std;

template<int n> // n y en el main se define el valor
struct A{
    int area = n * n;
};

template<int n = 3> // n con un valor por defecto
struct B{
    int area = n * 3;
};

template<auto k> // C++17; El placeholder puede ser de cualquier tipo auto :
//                   auto,auto&, auto **
struct C{};

int main(){
    A<5> a1; //Se crea un objeto usando la clase plantilla A;
    cout << a1.area << endl; // Resultado: 25
    B b1;// Se crea un objeto usando la clase plantilla B;
    cout << b1.area << endl; // Resultado: 9
    C<'a'> c1;
}