#include <iostream>

struct Zoo /* final */ {
    virtual ~Zoo() noexcept {
        std::cout << "Distruggo Zoo\n";
    }
    virtual void feedAnimals() {}
};

struct Bar : Zoo {
    ~Bar() noexcept {
        std::cout << "Distruggo Bar\n";
    }
    void feedAnimals() override /*final*/ {}
};

struct Foo : Bar {
    //Foo() {}
    Foo() = default;
    Foo(int i) : m_i{new int{i}} {}
    ~Foo() override { std::cout << "Distruggo Foo\n"; delete m_i; }
    Foo(const Foo& o) : m_i{o.m_i ? new int{*o.m_i} : nullptr} {}
    Foo& operator=(const Foo& o) {
        if (o.m_i) {
            *m_i = *o.m_i;
        }
        return *this;
    }
    void feedAnimals() override {}
private:
    int* m_i{nullptr};
};

struct Foo2 : Bar {
    Foo2(int i) : m_i{new int{i}} {}
    ~Foo2() override { std::cout << "Distruggo Foo2\n"; delete m_i; }

    Foo2(const Foo2& o) = delete;
    Foo2& operator=(const Foo2& o) = delete;

    void feedAnimals() override {}
private:
    int* m_i{nullptr};
};

void distruggi(Bar* b) {
    delete b;
}

int main() {
    Bar *b{new Bar};
    Foo *f{new Foo};
    distruggi(b);
    distruggi(f);
}
