#include <iostream>
#include "fraction.h"

void display(const Fraction& f) {
    f.print();
}

Fraction makeFraction() {
    return Fraction{};
}

int main() {
    Fraction* f = new Fraction{};
    f->setNum(4);
    f->setDen(0);
    display(*f);
    delete f;

    Fraction f2;
    f2.setNum(4);
    f2.setDen(2);
    display(f2);

    display(makeFraction());
}
