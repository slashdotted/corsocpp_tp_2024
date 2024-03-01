#include <iostream>
using namespace std;
int main(void) {
    int myarray[] { 1,2,3,4,5,6 };

    for (int& i : myarray) {
        i++;
    }
    for (int& i : myarray) {
        cout << i << endl;
    }
}
