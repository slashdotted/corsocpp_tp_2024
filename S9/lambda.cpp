#include <string>
#include <iostream>
#include <functional>

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

    std::string greet{"Hallo"};
    std::string suffix{"!"};

    //         ret. type   arguments
    std::function<void(const std::string&)> copy = ciao;

    // greet is captured by reference
    // suffix is captured by value (copy)
    auto ciao2 = [&greet,suffix] (const std::string& name) {
        greet ="Hi hi hi";
        std::cout << greet << " "
                  << name << suffix << std::endl;
    };

    // everything is captured by value
    auto ciao3 = [=] (const std::string& name) {
        std::cout << greet << " "
                  << name << suffix << std::endl;
    };

    // everything is captured by reference
    auto ciao4 = [&] (const std::string& name) {
        std::cout << greet << " "
                  << name << suffix << std::endl;
    };


    // everything is captured by value, except greet (captured by ref)
    auto ciao5 = [=,&greet] (const std::string& name) {
        std::cout << greet << " "
                  << name << suffix << std::endl;
    };

    // everything is captured by reference, except green (captured by value)
    auto ciao6 = [&,greet] (const std::string& name) {
        std::cout << greet << " "
                  << name << suffix << std::endl;
    };

    ciao2("Clara");

    greet = "Hi";

    ciao2("Paul");











    ciao("Marco");

}
