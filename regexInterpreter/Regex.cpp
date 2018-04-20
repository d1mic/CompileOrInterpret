#include "Regex.hpp"


Regex::~Regex(){
}

BinOperator::~BinOperator(){
    delete _left;
    delete _right;
}
UnOperator::~UnOperator(){
    delete _arg;
}
void Letter::print() const {
    cout << _letter;
}
void Concatenate::print() const {
    cout << "( ";
    _left->print();
    cout << " )";
    cout << "( ";
    _right->print();
    cout << " )";
}

void Disjunction::print() const {
    cout << "( ";
    _left->print();
    cout << " )";
    cout << "|";
    cout << "( ";
    _right->print();
    cout << " )";
}

void Kleene::print() const {
    cout << "( ";
    _arg->print();
    cout << " )";
    cout << "*";
}

void Plus::print() const {
     cout << "( ";
    _arg->print();
    cout << " )";
    cout << "( ";
    _arg->print();
    cout << " )";
    cout << "*";
}

void CharacterClass::print() const {
    if( _begin > _end){
        cerr << "Bad character class" << endl;
    }
    for(char c = _begin ; c != _end ; c++){
        cout << "( " << c  << " )" << "|";
    }
    cout << "( " << _end  << " )";
}
int Letter::minlen() const {
    return 1;
    cout << _letter;
}
int Concatenate::minlen() const {
   return _left->minlen() + _right->minlen();
}

int Disjunction::minlen() const {
    return (_left->minlen() < _right->minlen()) ? _left->minlen() : _right->minlen();
}

int Kleene::minlen() const {
   return 0;
}

int Plus::minlen() const {
    return _arg->minlen();
}

int CharacterClass::minlen() const {
    return 1;
}
