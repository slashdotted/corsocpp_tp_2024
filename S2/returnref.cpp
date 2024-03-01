#include <iostream>
using namespace std;
int &right(int &x, int &y) { return x > y ? x : y; }

int &wrong(int &x, int &y) {
  int temp;
  if (x > y)
    temp = x;
  else
    temp = y;
  return temp; // Error! Temp is a local variable!
}

int main(void) {
  int a{13}, b{17};
  cout << "a=" << a << " b=" << b << " max=" << right(a, b) << endl;
  cout << "a=" << a << " b=" << b << " max=" << wrong(a, b) << endl;
}
