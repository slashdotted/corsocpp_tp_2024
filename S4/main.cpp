#include <string>
#include <iostream>

struct Orange {
    Orange(const std::string& n) : m_name{n} {
        ++m_orange_counter;
        std::cout << "Creating Orange " << m_name << std::endl;
    }

    static int getOrangeCount() {
        return m_orange_counter;
    }

    ~Orange() {
        --m_orange_counter;
        std::cout << "Destroying Orange " << m_name << std::endl;
    }

private:
    std::string m_name;
    static int m_orange_counter;
};

int Orange::m_orange_counter{0};

void howManyOranges() {
    std::cout << Orange::getOrangeCount() << '\n';
}

struct Box {
    Box() : m_o{new Orange{"Another Orange"}}, m_i{"My Orange"}{
        std::cout << "Creating Box " << std::endl;
    }

    Box(const Box& x) : m_o{new Orange{*x.m_o}}, m_i{x.m_i} {
        std::cout << "Creating copy of Box " << std::endl;
    }

    Box& operator=(const Box& b) {
        *m_o = *b.m_o;
        m_i = b.m_i;
        return *this;
    }

    ~Box() {
        delete m_o;
        std::cout << "Destroying Box " << std::endl;
    }

    Orange *m_o;
    Orange m_i;
};

void take(Box x) {

}

int main() {
    Box b;
    take(b);
    Box c;
    b = c;

    /*Orange a{"A"};
    howManyOranges();
    {
        Orange c{"C"};
        howManyOranges();
    }
    howManyOranges();
    Orange *d{new Orange{"D"}};
    howManyOranges();
    delete d;
    howManyOranges();*/

}
