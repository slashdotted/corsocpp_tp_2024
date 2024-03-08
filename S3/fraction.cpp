#include "fraction.h"

// delegating constructors
//Fraction::Fraction() : Fraction(0,1) {
//}


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


