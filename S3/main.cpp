#include <iostream>
#include "fraction.h"

struct Container {
    explicit Container(int capacity) {}
    explicit Container(const Fraction&) {}
};

void display(const Fraction& f) {
    f.print();
}

void fill(const Container& c) {

}

Fraction makeFraction() {
    return Fraction{};
}

Fraction operator+(Fraction a, const Fraction& b) {
    a += b;
    return a;
}

int main() {
   /* Fraction* f = new Fraction{};
    f->setNum(4);
    f->setDen(0);
    display(*f);
    delete f; */

    Fraction k;
    k = 8; // becomes k = Fraction{8} using the conversion/converting constructor
    k = 6.7; // converts double to int and then uses the conversion/converting constructor
    k = {6,7}; // becomes k = Fraction{6,7}
    k.print();
    display(7); // becomes display(Fraction{7}) using the conversion/converting constructor

    fill(Container{9});

    Container c{6};
    c = Container{k};

    Fraction l = new Fraction{5,3};
    /*Fraction* l1 = new Fraction{5,3};
    Fraction l2 = l1;
    display(*l1);
    delete l;*/


    Fraction f,g,h;
    auto t{f};
    h = (t += g);

    h = f+g; // h = f.operator+(g);
    f = h+6;
    f = 6+h;


}
