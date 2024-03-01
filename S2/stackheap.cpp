#include <string>

void stackAllocation() {
    int i{7};
    double pi{3.14};
    auto pi2{3.14};
    auto msg{std::string{"hello world"}};
    auto msg2{"hello world"};
}

void heapAllocation() {
    int* x{nullptr};
    int* i{new int{42}};
    std::string* s{new std::string{"Hi"}};

    // auto or auto* are ok for pointers
    auto* i2{new int{42}};
    auto s2{new std::string{"Hi"}};

    auto array{new double[9]};
    auto array2{new std::string[3]};

    delete i;
    delete s;
    delete i2;
    delete s2;
    delete[] array;
    delete[] array2;
}

void javaLikeCode() {
    //std::string* k = new std::string{"Bla bla bla"};
    std::string k{"Bla bla bla"};
    std::string p;

    // String p2;
    std::string* p2;
    // std::string p3 = new std::string; // Error!

    //delete k;
}

int main() {
    stackAllocation();
    heapAllocation();
    javaLikeCode();
}
