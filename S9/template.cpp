#include "mylist.h"
#include <iostream>

int main() {
    MyList<int> l{10};
    for(unsigned int i{0}; i<10; ++i) {
        l[i] = i;
    }

    std::cout << "Size is: " << l.size();

    for(unsigned int i{0}; i<10; ++i) {
        std::cout << l[i] << '\n';
    }


}
