#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <memory>

struct Foo {
    ~Foo() {
        std::cout << "Foo è stato distrutto\n";
    }

};

void printFruits(const std::vector<std::string>& fruits, unsigned int limit) {
    //Foo *f{new Foo};
    auto f{std::make_unique<Foo>()};
    for(int i{0}; i<limit; ++i) {
        if (i >= fruits.size()) {
            throw std::out_of_range("Indice non valido");
        }
        std::cout << fruits[i] << '\n';
    }
    //delete f;
}

void printFruits2(const std::vector<std::string>& fruits, unsigned int limit) noexcept {
    for(int i{0}; i<limit; ++i) {
        if (i >= fruits.size()) {
            throw "printFruits2: Indice non valido";
        }
        std::cout << fruits[i] << '\n';
    }
}

void printFruits3(const std::vector<std::string>& fruits, unsigned int limit) {
    for(int i{0}; i<limit; ++i) {
        if (i >= fruits.size()) {
            throw 42;
        }
        std::cout << fruits[i] << '\n';
    }
}

int main() {
    std::vector<std::string> fruits{"apple", "orange", "strawberry", "pineapple", "ananas"};

    for(const auto& f : fruits) {
        std::cout << f << '\n';
    }

    std::cout << "Capacity:" << fruits.capacity() << " Size:" << fruits.size() << '\n';

    fruits.push_back("dragonfruit");
    std::cout << "Capacity:" << fruits.capacity() << " Size:" << fruits.size() << '\n';
    fruits.erase(fruits.begin() + 2);
    std::cout << "Capacity:" << fruits.capacity() << " Size:" << fruits.size() << '\n';
    fruits.shrink_to_fit();
    std::cout << "Capacity:" << fruits.capacity() << " Size:" << fruits.size() << '\n';

    for(int i{0}; i<7; ++i) {
        // std::cout << fruits[i] << '\n';
        try {
            std::cout << fruits.at(i) << '\n';
        } catch (const std::out_of_range& e) {
            std::cout << "Exception: " << e.what() << '\n';
        }
    }

    try {
        printFruits(fruits, 7);
        //printFruits2(fruits, 7);
        //printFruits3(fruits, 7);
    } catch (const std::out_of_range& e) {
        std::cout << "Exception: " << e.what() << '\n';
    } catch (const char* m) {
        std::cout << "Exception: " << m << '\n';
    } catch (...) {
        std::cout << "Exception!" << '\n';
        throw;
    }

}
