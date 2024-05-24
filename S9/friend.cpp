#include "8-D"
#include <iostream>

class Machine;

void log(const Machine&);

class Inspector {
public:
    void inspect(const Machine&);
    void spy(const Machine&);
};

class Machine {
public:
    Machine(int serialnr);

private:
    friend void Inspector::inspect(const Machine&);
    friend class Inspector;
    friend void log(const Machine&);
    void self_test() const;
protected:
    int m_serialnr;
};

Machine::Machine(int serialnr) : m_serialnr{serialnr} {}

void Machine::self_test() const {
    std::cout << "Machine: " << m_serialnr << "... self-test\n";
}

void Inspector::inspect(const Machine& m) {
    std::cout << "Inspect Serial nr:" << m.m_serialnr << '\n';
    m.self_test();
}

void Inspector::spy(const Machine& m) {
    std::cout << "Spy Serial nr:" << m.m_serialnr << '\n';
    m.self_test();
}

void log(const Machine& m) {
    std::cout << "Log Serial nr:" << m.m_serialnr << '\n';
    m.self_test();
}

int main() {
    Machine m{12345};
    Inspector i;
    std::cout << m << std::endl;
    std::cout << i << std::endl;
    i.inspect(m);
    log(m);
}
