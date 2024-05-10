#include <iostream>
#include <vector>
#include "lecturerresearcher.h"

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

    //Researcher* rp{static_cast<Researcher*>(ep)}; // virtual base class
    Researcher* lrp{&lr};
    //Lecturer* lrp_wrong{static_cast<Lecturer*>(lrp)};
    LecturerResearcher* lr2{static_cast<LecturerResearcher*>(lrp)};

    Researcher& lrr{lr};
    LecturerResearcher& lrr2{static_cast<LecturerResearcher&>(lrr)};

    // Wrong cast
    Researcher& rr{r};
    LecturerResearcher& lrr3{static_cast<LecturerResearcher&>(rr)};



}



int main() {
    using namespace std;
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

    staticcast();
}
