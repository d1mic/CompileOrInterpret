#include "funkcije.hpp"
#include <iostream>
#include <cmath>
using namespace std;

Funkcija::~Funkcija(){
}

void Const::ispisi() const {
    
    cout << value ;
}
UnOperator::~UnOperator(){
    delete _arg;
}

void Sin::ispisi() const {
    cout << "sin( ";
     _arg->ispisi();
    cout << " )";
}

void Cos::ispisi() const {
    
    cout << "cos( ";
     _arg->ispisi();
    cout << " )" ;
}

void IdenticFunc::ispisi() const {
     cout << "x" ;
}
BinOperator::~BinOperator(){
    delete _left;
    delete _right;
}

void Add::ispisi() const {
    cout << "( ";
    _left->ispisi();
    cout<< " + ";
    _right->ispisi();
    cout << ") ";
}
void Minus::ispisi() const {
     cout << "( ";
    _left->ispisi();
    cout<< " - ";
    _right->ispisi();
     cout << ") ";
}
void Mul::ispisi() const {
     cout << "( ";
    _left->ispisi();
    cout<< " * ";
    _right->ispisi();
     cout << ") ";
}
void Div::ispisi() const {
     cout << "( ";
    _left->ispisi();
    cout<< " / ";
    _right->ispisi();
     cout << ") ";
}
Funkcija* Add::izvod() const {
    return new Add(_left->izvod(), _right->izvod());
}
Funkcija* Minus::izvod() const {
    return new Minus(_left->izvod(), _right->izvod());
}
Funkcija* Mul::izvod() const {
    return new Add(
        new Mul(_left->izvod(), _right), 
        new Mul(_left, _right->izvod())
    );
}
Funkcija* Div::izvod() const {
    return new Div(
                new Minus(
                    new Mul(_left->izvod(), _right),
                    new Mul(_right->izvod(),_left)
                ),
                new Mul( _right, _right )
               );
}
Funkcija* Const::izvod() const {
    return new Const(0);
}

Funkcija* Sin::izvod() const {
   return new Mul(new Cos(_arg), _arg->izvod());
}

Funkcija* Cos::izvod() const {
    return new Mul(new Const(-1), new Mul(new Sin(_arg) , _arg->izvod()));
}

Funkcija* IdenticFunc::izvod() const {
     return new Const(1);
}

float Add::izracunaj( float t) const {
    return (_left->izracunaj(t) + _right->izracunaj(t));
}
float Minus::izracunaj( float t) const {
     return (_left->izracunaj(t) - _right->izracunaj(t));
}
float Mul::izracunaj( float t) const {
    return (_left->izracunaj(t) * _right->izracunaj(t));
}
float Div::izracunaj( float t) const {
     return (_left->izracunaj(t) / _right->izracunaj(t));
   }
float Const::izracunaj( float t) const {
    return value;
}

float Sin::izracunaj( float t) const {
    return sin(_arg->izracunaj(t));
}

float Cos::izracunaj( float t) const {
     return cos(_arg->izracunaj(t));
}

float IdenticFunc::izracunaj( float t) const {
     return t;
}
