#ifndef _REGEX_
#define _REGEX_

#include <iostream>
#include <string>
using namespace std;

class Regex {
public:
    virtual void print() const = 0;
    virtual int minlen() const = 0;
    virtual ~Regex();
};


class Letter : public Regex {
public:
    Letter(char letter)
    :_letter(letter)
    {}
    void print() const;
    int minlen() const;
private:
    char _letter;
};

class UnOperator : public Regex{
public:
    UnOperator(Regex *arg)
    :_arg(arg)
    {}
    ~UnOperator();
private:
    UnOperator& operator=(const UnOperator &other );
    UnOperator(const UnOperator &other); 
protected:
    Regex *_arg;
    
};

class BinOperator : public Regex{
public:
    BinOperator(Regex *left, Regex *right)
    :_left(left) , _right(right)
    {}
    ~BinOperator();
private:
    BinOperator& operator=(const BinOperator &other );
    BinOperator(const BinOperator &other); 
protected:
    Regex *_left;
    Regex *_right;
    
};
class Concatenate : public BinOperator{
public:
    Concatenate(Regex *left, Regex *right)
    :BinOperator(left,right)
    {}
    void print() const;
    int minlen() const;
};

class Disjunction : public BinOperator{
public:
    Disjunction(Regex *left, Regex *right)
    :BinOperator(left,right)
    {}
    void print() const;
    int minlen() const;
};

class Kleene : public UnOperator{
public:
    Kleene(Regex *arg)
    :UnOperator(arg)
    {}
    void print() const;
    int minlen() const;
};

class Plus : public UnOperator{
public:
    Plus(Regex *arg)
    :UnOperator(arg)
    {}
    void print() const;
    int minlen() const;
};

class CharacterClass : public Regex{
public:
    CharacterClass(char begin, char end)
    :_begin(begin) , _end(end)
    {}
    void print() const;
    int minlen() const;
private:
    char _begin;
    char _end;
};

#endif