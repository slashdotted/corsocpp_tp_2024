#include <iostream>
#include <vector>
#include "lecturerresearcher.h"

struct Foo {
    // Soluzione per rendere Foo un tipo polimorfico
    virtual ~Foo() = default;
};

struct Bar : Foo {
};


void dynamiccast() {
    Employee e{"John", "ISIN", 123};
    Lecturer l{"Mark", "ISEA", 555, "Computer Science", "C++"};
    Researcher r{"Alice", "ISEA", 5595, "AI"};
    LecturerResearcher lr{"John", "ISIN", 3565, "CompSci", "ParallelProgramming", "DS", 50.0};

    //auto el{dynamic_cast<Employee>(l)};
    Employee el2{l};

    Employee& er{dynamic_cast<Employee&>(r)};
    Employee& er2{r};

    Employee* ep{dynamic_cast<Employee*>(&r)};
    Employee* ep2{&r};

    // dynamic_cast può fare downcasting attraversando una derivazione virtual
    Researcher* rp{dynamic_cast<Researcher*>(ep)}; // virtual base class
    Researcher* lrp{&lr};

    // Cast valido da un puntatore a Researcher (con "collegato" un LecturerResearcher) a
    // puntatore a Lecturer
    Lecturer* lrp_ok{dynamic_cast<Lecturer*>(lrp)};
    if (lrp_ok == nullptr) {
        std::cout << "Cast non valido da Researcher* a Lecturer* (con LecturerResearcher)" << std::endl;
    }

    // Cast NON valido da un puntatore a Researcher (con "collegato" un Researcher) a
    // puntatore a Lecturer
    Lecturer* lrp_wrong{dynamic_cast<Lecturer*>(&r)};
    if (lrp_wrong == nullptr) {
        std::cout << "Cast non valido da Researcher* a Lecturer* (con Researcher)" << std::endl;
    }

    // Cast valido da un riferimento a Researcher (con "collegato" un LecturerResearcher) a
    // riferimento a Lecturer
    Lecturer& rlrp_ok{dynamic_cast<Lecturer&>(lr)};

    try {
        // Cast NON valido da un riferimento a Researcher (con "collegato" un LecturerResearcher) a
        // riferimento a Lecturer
        Lecturer& rlrp_wrong{dynamic_cast<Lecturer&>(r)};
    } catch (const std::bad_cast& e) {
        // cast non valido
    }

    // Cast NON valido da un puntatore generico (anche se "collegato" un Researcher) a
    // puntatore a Researcher
    void* vp{&r};
    //Researcher* lrrp4{dynamic_cast<Researcher*>(vp)};


    Bar b;
    Foo* f{&b};
    // Cast NON valido quando la sorgente non è un tipo polimorfico (non ha nessun metodo virtual)
    auto d{dynamic_cast<Bar*>(f)};
}


void staticcast() {
    Employee e{"John", "ISIN", 123};
    Lecturer l{"Mark", "ISEA", 555, "Computer Science", "C++"};
    Researcher r{"Alice", "ISEA", 5595, "AI"};
    LecturerResearcher lr{"John", "ISIN", 3565, "CompSci", "ParallelProgramming", "DS", 50.0};

    auto el{static_cast<Employee>(l)};
    Employee el2{l};

    Employee& er{static_cast<Employee&>(r)};
    Employee& er2{r};

    Employee* ep{static_cast<Employee*>(&r)};
    Employee* ep2{&r};

    // Non posso fare downcasting con static_cast attraversando una derivazione virtual
    //Researcher* rp{static_cast<Researcher*>(ep)}; // virtual base class

    Researcher* lrp{&lr};
    // Non posso "saltare" tra due rami della gerarchia
    //Lecturer* lrp_ok{static_cast<Lecturer*>(lrp)};

    LecturerResearcher* lr2{static_cast<LecturerResearcher*>(lrp)};
    Researcher& lrr{lr};
    LecturerResearcher& lrr2{static_cast<LecturerResearcher&>(lrr)};

    // Wrong cast
    Researcher& rr{r};
    LecturerResearcher& lrr3{static_cast<LecturerResearcher&>(rr)};

    Researcher* rrp{&r};
    LecturerResearcher* lrrp3{static_cast<LecturerResearcher*>(rrp)};

    //LecturerResearcher lrrp4{static_cast<LecturerResearcher>(r)};

    void* vp{&r};
    LecturerResearcher* lrrp4{static_cast<LecturerResearcher*>(vp)};

    Bar b;
    Foo* f{&b};
    auto d{static_cast<Bar*>(f)};
}


int main() {
    /*using namespace std;
    LecturerResearcher lr{"John", "ISIN", 3565, "CompSci", "ParallelProgramming", "DS", 50.0};
    cout << "Name: "
         << lr.name()
         << " Employee nr: "
         << lr.employeenr() << '\n';
    cout << "Studies: " << lr.studies() << '\n';
    cout << "Research area:" << lr.researcharea() << '\n';

    // Upcasting
    Employee e{"John", "ISIN", 123};
    Lecturer l{"Mark", "ISEA", 555, "Computer Science", "C++"};
    Researcher r{"Alice", "ISEA", 5595, "AI"};

    // Upcasting "always" works
    Employee* le{&l};
    Employee* re{&r};
    Employee* lre{&lr};

    Employee& rle{l};
    Employee& rre{r};
    Employee& rlre{lr};

    Employee vle{l};
    Employee vre{r};
    Employee vlre{lr};

    std::cout << "&l=" << &l << " le=" << le << std::endl;

    std::vector<Employee*> v;
    v.push_back(&l);
    for(Employee* p : v) {
        if ((void*) p == (void*) &l) {
            std::cout << "Found!\n";
        }
    }
    */
   // staticcast();
    dynamiccast();
}
