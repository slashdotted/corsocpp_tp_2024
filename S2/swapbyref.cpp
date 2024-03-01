#include <iostream>
using namespace std;

void cswap(int* x, int* y) {
    int temp{*x};
    *x = *y;
    *y = temp;
}

void swap(int& x, int& y) {
    int temp{x};
    x = y;
    y = temp;
}

int main(void) {
    int a{13}, b{17};
    cout << "a=" << a << " b=" << b << endl;
    swap(a, b);
    cout << "a=" << a << " b=" << b << endl;
}
