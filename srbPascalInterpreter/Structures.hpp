#ifndef __STRUCTURES__
#define __STRUCTURES__
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/* Classes for E(xpressions) */

class Expression {
public:
    virtual float value() const = 0;
    virtual ~Expression();
};

class BinOperator : public Expression{
public:
    BinOperator(Expression *left , Expression *right)
    :_left(left) , _right(right)
    {}
    ~BinOperator();
private:
    Expression& operator=(const Expression &other);
    BinOperator( const Expression &other);
protected:
    Expression *_left;
    Expression *_right;
};

class UnOperator : public Expression{
public:
    ~UnOperator();
private:
    Expression& operator=(const Expression &other);
    UnOperator( const Expression &other);
protected:
    Expression *_arg;
};


class Constant : public Expression{
public:
    Constant(float cnst)
    :_cnst(cnst)
    {}
    float value() const;
private:
    float _cnst;
};

class Sum : public BinOperator{
public:
    Sum(Expression *left , Expression *right)
    :BinOperator(left, right)
    {}
    float value() const ;
};


class Sub : public BinOperator{
public:
    Sub(Expression *left , Expression *right)
    :BinOperator(left, right)
    {}
    float value() const ;
};

class Mul : public BinOperator{
public:
    Mul(Expression *left , Expression *right)
    :BinOperator(left, right)
    {}
    float value() const ;
};

class Div : public BinOperator{
public:
    Div(Expression *left , Expression *right)
    :BinOperator(left, right)
    {}
    float value() const ;
};

/* Statement */

class Statement{
public:
    virtual ~Statement(); 
    virtual void execute() const =0 ;
};

class PrintString : public Statement{
public:
    PrintString(string s)
    :_str(s)
    {}
    void execute() const;
private:
    string _str;
};

class PrintExpression : public Statement {
    
public:
    PrintExpression(Expression *exp)
    :_exp(exp)
    {}
    ~PrintExpression();
    void execute() const;
private:
    PrintExpression& operator=(const PrintExpression &other);
    PrintExpression(const PrintExpression &other);
    Expression *_exp;
};

class  Block : public Statement{
public:
    Block(vector<Statement*> stmts)
    :_block(stmts)
    {}
    ~Block();
    void execute() const;
private:
    Block& operator=(const Block &other);
    Block(const Block &other);
    
    vector<Statement *> _block; 
};
class Declaration : public Statement{
public:
    Declaration(string id , Expression *exp)
    : _id(id), _exp(exp)
    {}
    ~Declaration();
     void execute() const;
private:
    Declaration& operator=(const Declaration &other);
    Declaration(const Declaration &other);
    
    string _id;
    Expression *_exp;
};

class PrintVariable : public Statement{
public:
    PrintVariable(string id)
    :_id(id)
    {}
    void execute() const;
private:
    string _id;
};

class IfStmt : public Statement{
public:
    IfStmt(Expression *exp , Statement *s1)
    :_exp(exp) , _stmt(s1)
    {}
    ~IfStmt();
    void execute() const;
private:
    IfStmt& operator=(const IfStmt &other);
    IfStmt(const IfStmt &other);
    
    Expression *_exp;
    Statement *_stmt;
};

class IfElseStmt : public Statement{
public:
    IfElseStmt(Expression *exp , Statement *s1 , Statement *s2)
    :_exp(exp) , _stmt1(s1), _stmt2(s2)
    {}
    ~IfElseStmt();
    void execute() const;
private:
    IfElseStmt& operator=(const IfElseStmt &other);
    IfElseStmt(const IfElseStmt &other);
    
    Expression *_exp;
    Statement *_stmt1;
    Statement *_stmt2;
};

class WhileStmt : public Statement {
public:
    WhileStmt(Expression *exp , Statement *s)
    :_exp(exp) , _stmt(s)
    {}
    ~WhileStmt();
    void execute() const;
private:
    WhileStmt& operator=(const WhileStmt &other);
    WhileStmt(const WhileStmt &other);
    
    Expression *_exp;
    Statement *_stmt;
};


#endif