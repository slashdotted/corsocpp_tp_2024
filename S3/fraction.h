#pragma once
#include <iostream>

class Fraction { // we could use struct Fraction (and the default access level would be public)
public:
    //Fraction();
    Fraction(int num = 0, int den = 1);

    void setNum(int num);
    int getNum() const;
    int getDen() const;
    void setDen(int value);
    void print() const { // this is inline
        std::cout << m_num << "/" << m_den << '\n';
    }
private:
    int m_num;
    int m_den;

protected:
};
