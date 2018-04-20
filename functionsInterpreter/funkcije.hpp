#ifndef _FUNCTION_
#define _FUNCTION_



class Funkcija {
public:
    virtual void ispisi() const = 0;
    virtual ~Funkcija();
    virtual Funkcija* izvod() const = 0;
    virtual float izracunaj(float t) const = 0;
};

class Const : public Funkcija {
public:
    Const(float v)
    :value(v)
    {}
    void ispisi() const;
    Funkcija* izvod() const;
    float izracunaj(float t) const;
private:
    float value;    
};

class UnOperator : public Funkcija {
public:
    UnOperator(Funkcija *f)
    :_arg(f)
    {}
    ~UnOperator();
private:
    UnOperator& operator= (const UnOperator &other);
    UnOperator(const UnOperator &other);
protected:
    Funkcija *_arg;
};


class Sin : public UnOperator{
public:
    Sin(Funkcija *f)
    :UnOperator(f)
    {}
    void ispisi() const;
    Funkcija* izvod() const;
    float izracunaj(float t) const;
};

class Cos : public UnOperator{
public:
    Cos(Funkcija *f)
    :UnOperator(f)
    {}
    void ispisi() const;
    Funkcija* izvod() const;
    float izracunaj(float t) const;
};


class IdenticFunc : public Funkcija{
public:
    void ispisi() const;
    Funkcija* izvod() const;
    float izracunaj(float t) const;
};

class BinOperator : public Funkcija {
public:
    BinOperator(Funkcija * f1 , Funkcija *f2)
    :_left(f1) , _right(f2)
    {}
    ~BinOperator();
protected:
    Funkcija *_left;
    Funkcija *_right;
private:
    BinOperator& operator=(const BinOperator &other);
    BinOperator( const BinOperator &other);
};

class Add : public BinOperator{
public:
    Add(Funkcija *f1 , Funkcija *f2)
    :BinOperator(f1,f2)
    {}
    void ispisi() const ;
    Funkcija* izvod() const;
    float izracunaj(float t) const;
};


class Minus : public BinOperator{
public:
    Minus(Funkcija *f1 , Funkcija *f2)
    :BinOperator(f1,f2)
    {}
    void ispisi() const ;
    Funkcija* izvod() const;
    float izracunaj(float t) const;
};

class Mul : public BinOperator{
public:
    Mul(Funkcija *f1 , Funkcija *f2)
    :BinOperator(f1,f2)
    {}
    void ispisi() const ;
    Funkcija* izvod() const;
    float izracunaj(float t) const;
};

class Div : public BinOperator{
public:
    Div(Funkcija *f1 , Funkcija *f2)
    :BinOperator(f1,f2)
    {}
    void ispisi() const ;
    Funkcija* izvod() const;
    float izracunaj(float t) const;
};
#endif