#include "mymath.h"
#include <iostream>

int multiply(int a, int b) {
    using namespace std;
    cout << "multiply global\n";
    return a*b*2;
}

namespace supsi {
int multiply(int a, int b) {
    // ********************************
    // Accessing a symbol in the global namespace
    // ********************************
    return ::multiply(a,b);
}
}

// ********************************
// Namespace alias
// ********************************
namespace fn = supsi;


void fun() {
    std::cout << fn::multiply(3,2) << std::endl;
}

int main() {
    using namespace std;
    cout << fn::multiply(3,2) << endl;
}


