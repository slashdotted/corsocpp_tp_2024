#include <iostream>
using namespace std;
int main(void)
{
    int a;
    int b{13};
    int* bp{&b};

    int& c{a};

    a = 4;
    cout << "a=" << a << " b=" << b << " c=" << c <<
        endl;
    a = b;
    cout << "a=" << a << " b=" << b << " c=" << c << endl;
    c = 7;
    cout << "a=" << a << " b=" << b << " c=" << c <<
        endl;
}
