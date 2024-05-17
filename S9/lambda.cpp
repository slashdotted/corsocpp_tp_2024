#include <string>
#include <iostream>

struct Greeter {
    Greeter(const std::string& g) : m_greet{g} {}
    /*void greet(const std::string& name) const {
        std::cout << m_greet << " " << name << std::endl;
    }*/
    void operator()(const std::string& name) {
        std::cout << m_greet << " " << name << std::endl;
        if (!m_last.empty()) {
            std::cout << "I just greeted " << m_last << std::endl;
        }
        m_last = name;
    }

private:
    std::string m_last;
    std::string m_greet;
};

int main() {
    Greeter hi{"Hi"};
    Greeter hello{"Hello"};
    hello("Alice");
    hi("John");
    hi("Alice");

    auto ciao = [] (const std::string& name) {
        std::cout << "Ciao " << name << std::endl;
    };

    ciao("Marco");

}
