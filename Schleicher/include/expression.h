#ifndef EXPRESSION_H
#define EXPRESSION_H

template<class T>
class expression
{
    public:
        expression();
        virtual ~expression();
    protected:
    private:

    T loperand;
    T roperand;

    string op;      //operator

};

#endif // EXPRESSION_H
