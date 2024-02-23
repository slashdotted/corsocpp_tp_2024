#include <iostream>
#include <string>

// ********************************
// Arguments with default value
// ********************************
// Default values go into the declaration
int sum(int a, int b = 0, int c = 0, int d = 0);

// ********************************
// Overloading
// ********************************
void sayHello() {
    std::cout << "Hello!\n";
}

void sayHello(int k) {
    for (int i=0; i<k; ++i) {
        std::cout << "Hello!\n";
    }
}

void fun(int, double) {

}

void fun(double, int) {

}

// ********************************
// Arguments with default value
// ********************************
int sum(int a, int b, int c, int d) {
    return a+b+c+d;
}


int main() {
    using namespace std;
    sayHello();
    sayHello(5);
    cout << "Hello world\n";
    cerr << "This error" << endl;
    fun(4,3.5);
    fun(3.14,8);

    // ********************************
    // Ambiguities with overloading
    // ********************************
    // fun(5,3); // Ambiguous
    fun(double(5),3); // We need to force a cast

    cout << sum(1,2) << '\n';
    cout << sum(1,2,3) << '\n';
    cout << sum(1,2,3,4) << '\n';

    std::string msg = "Hello C++";
    msg += "!!!";
    if (msg == "Hello C++!!!") {
        // String comparison
    }

    int x = 3;
    int y(8);
    int z{9};

    double pi = 3.14;
    int pi2 = 3.14;
    //int pi3{3.14};  // Error! Narrowing conversion (double->int)

    auto pi4{3.14};






}
