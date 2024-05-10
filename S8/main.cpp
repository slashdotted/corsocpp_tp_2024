#include "employee.h"
#include "lecturer.h"
#include "researcher.h"
#include <iostream>

using std::cout;

void printInfo(Employee* e) {
    cout << e->classname() << ": " << e->name() << ", " << e->institute() << ", " << e->employeenr() << '\n';
    e->doSomeWork();
}

void printInfo(const Employee& e) {
    cout << e.classname() << ": " << e.name() << ", "
         << e.institute() << ", " << e.employeenr() << '\n';
}

int main() {
    //Employee a{"John", "ISIN", 123};
    Lecturer l{"Mark", "ISEA", 555, "Computer Science", "C++"};
    //Researcher r{"Alice", "ISEA", 5595, "AI"};

    //l.Employee::earnSalary(2000.5);
    l.earnSalary(2000.5);

    /*cout << a.classname() << ": " << a.name() << ", " << a.institute() << ", " << a.employeenr() << '\n';
    cout << l.classname() << ": " << l.name() << ", " << l.institute()
         << ", " << l.employeenr() << ", " << l.studies()
         << ", " << l.course() << '\n';
    cout << r.classname() << ": " << r.name() << ", "
         << r.institute() << ", " << r.employeenr() << ", "
         << r.researcharea() << '\n';*/

    /*printInfo(l);
    printInfo(&l);

    printInfo(r);
    printInfo(&r);*/

}
