#include "lecturer.h"
#include <iostream>

using std::cout;
using std::endl;
using std::string;

Lecturer::Lecturer(string name, string institute, int nr,
                   string studies, string course)
    : Employee{name, institute, nr}, m_studies{studies}
    , m_course{course}
{
    cout << "Costructing Lecturer" << endl;
}
Lecturer::~Lecturer()
{
    cout << "Destroying Lecturer" << endl;
}
string Lecturer::studies() const
{
    return m_studies;
}
string Lecturer::course() const
{
    return m_course;
}
string Lecturer::classname() const
{
    return Employee::classname()+":Lecturer";
}

void Lecturer::earnSalary(float amount) const
{
    cout << "Lecturer::earnSalary(float amount)\n";
}

/*void Lecturer::earnSalary(int amount) const
{
    Employee::earnSalary(amount);
}

void Lecturer::earnSalary(double amount) const
{
    Employee::earnSalary(amount);
}*/
