#include "fraction.h"

// delegating constructors
//Fraction::Fraction() : Fraction(0,1) {
//}

Fraction& Fraction::operator+=(const Fraction& x) {
    int temp_num { x.m_num *
                       m_den };
    m_den *= x.m_den;
    m_num *= x.m_den;
    m_num += temp_num;
    return *this;
}

Fraction& Fraction::operator-=(const Fraction& x) {
    int temp_num { x.m_num *
                 m_den };
    m_den *= x.m_den;
    m_num *= x.m_den;
    m_num -= temp_num;
    return *this;
}

/*Fraction Fraction::operator+(const Fraction& x) {
    auto t{x};
    t += *this;
    return t;
}*/

Fraction Fraction::operator-(const Fraction& x) {
    auto t{x};
    t += *this;
    return t;
}






Fraction::Fraction(int num, int den)
    : m_num{num}, m_den{den}{
    if (m_den == 0) {
        m_den = 1;
    }
}

void Fraction::setNum(int num) {
    this->m_num = num;
}

int Fraction::getNum() const {
    return m_num;
}

int Fraction::getDen() const
{
    return m_den;
}

void Fraction::setDen(int value) {
    if (value != 0)
        m_den = value;
}


