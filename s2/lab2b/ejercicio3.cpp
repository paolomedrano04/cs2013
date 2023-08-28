#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class Forma{
    friend ostream& operator<<(ostream& os, const Forma& forma);
protected:
    double area;
public:
    Forma(): area(0){};
    Forma(int a): area(a){};
    virtual void calcularArea() = 0;
};
ostream& operator<<(ostream& os, const Forma& forma){
    os << forma.area;
    return os;
}

class Cuadrado: public Forma{
private:
    int lado;
public:
    Cuadrado(): lado(0){};
    Cuadrado(int l): lado(l){};
    void calcularArea(){
        area = pow(lado,2);
    };
};

class Triangulo:public Forma{
private:
    int base;
    int altura;
public:
    Triangulo():base(0),altura(0){};
    Triangulo(int b,int a): base(b),altura(a){};
    void calcularArea(){
        area= (base*altura)/2;}
    ;

};

class Circulo:public Forma{
private:
    const int pi=3.141516;
    double radio;
public:
    Circulo():radio(0){};
    Circulo(int r): radio(r){};
    void calcularArea(){
        area= pi*pow(radio,2);
    };

};


int main () {
    vector<Forma*> formas;
    Cuadrado cuadrado(2);
    Triangulo triangulo(2, 3);
    Circulo circulo(2);
    formas.push_back(&cuadrado);
    formas.push_back(&triangulo);
    formas.push_back(&circulo);
    for (Forma* forma : formas) {
        forma->calcularArea();
        cout << *forma << endl;
    }
    return 0;
}
