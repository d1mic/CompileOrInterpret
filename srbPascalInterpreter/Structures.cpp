#include "Structures.hpp"
#include <iostream>
#include <map>
#include <string>
using namespace std;


Expression::~Expression(){
    
}

BinOperator::~BinOperator(){
    delete _left;
    delete _right;
}

UnOperator::~UnOperator(){
    delete _arg;
}

float Constant::value() const{
    return _cnst;
}

float Sum::value() const {
    return _left->value() + _right->value();
}


float Sub::value() const {
    return _left->value() - _right->value();
}

float Mul::value() const {
    return _left->value() * _right->value();
}

float Div::value() const {
    return _left->value() / _right->value();
}
Statement::~Statement(){
}
void PrintString::execute() const {
    cout << _str << endl;
}
void PrintExpression::execute() const {
    cout << _exp->value() << endl;
}
PrintExpression::~PrintExpression(){
    delete _exp;
}

Block::~Block(){
    for(unsigned i = 0 ; i < _block.size() ; i++){
       delete _block[i];
    }
}
void Block::execute() const {
    for(unsigned i = 0 ; i < _block.size() ; i++){
        _block[i]->execute();
    }
}

Declaration::~Declaration(){
    delete _exp;
}
extern map<string,float> symbol_table;
void Declaration::execute() const {
    symbol_table[_id] = _exp->value();
}

void PrintVariable::execute() const{
    cout << symbol_table[_id] << endl;
    
}

IfStmt::~IfStmt(){
    delete _exp;
    delete _stmt;
}

void IfStmt::execute() const{
    if(_exp->value()){
        _stmt->execute();
    }
}


IfElseStmt::~IfElseStmt(){
    delete _exp;
    delete _stmt1;
    delete _stmt2;
}

void IfElseStmt::execute() const{
    if(_exp->value()){
        _stmt1->execute();
    }
    else{
        _stmt2->execute();
    }
}
WhileStmt::~WhileStmt(){
    delete _exp;
    delete _stmt;
}

void WhileStmt::execute() const{
    while(_exp->value()){
        _stmt->execute();
    }
}