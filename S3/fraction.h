#pragma once
#include <iostream>

class Fraction { // we could use struct Fraction (and the default access level would be public)
public:
    //Fraction();
    Fraction(int num = 0, int den = 1);

    // This works but is a BAD idea
    // Note: your lecturer will cut your fingers if you write this in a test/exam
    Fraction(Fraction* f) : m_num{f->m_num}, m_den{f->m_den} {
        delete f;
    };

    void setNum(int num);
    int getNum() const;
    int getDen() const;
    void setDen(int value);
    void print() const { // this is inline
        std::cout << m_num << "/" << m_den << '\n';
    }

    Fraction& operator+=(const Fraction& x);
    Fraction& operator-=(const Fraction& x);
   // Fraction operator+(const Fraction& x);
    Fraction operator-(const Fraction& x);
private:
    int m_num;
    int m_den;

protected:
};
