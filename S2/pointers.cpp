#include <iostream>
using namespace std;

void no_swap(int x, int y) {
    int temp{x};
    x = y;
    y = temp;
}

void swap(int* x, int* y) {
    int temp{*x};
    *x = *y;
    *y = temp;
}

int main(void) {
    int a{13}, b{17};
    cout << "a=" << a << " b=" << b << endl;
    no_swap(a, b); // This copies x and y, does not swap!
    cout << "a=" << a << " b=" << b << endl;
    swap(&a,&b);
    cout << "a=" << a << " b=" << b << endl;
}
