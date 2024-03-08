#include <iostream>

int f(const int& x)
{
    std::cout << x << '\n';
    return x;
}

int g(int x)
{
    return x;
}

int main(void)
{
    int a{67};
    f(a);
    g(a);
    g(89);
    f(89);
    g(f(a));
    f(g(a));
}
