#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>

class Employee
{
public:
    Employee(std::string name, std::string institute, int nr);
    ~Employee();

    std::string name() const;
    std::string institute() const;
    int employeenr() const;
    virtual std::string classname() const;
    virtual void doSomeWork() = 0; // Pure virtual method (there is no implementation in this class)
                                   // if there is at least one pure virtual method -> class is abstract
    void earnSalary(int amount) const;
    void earnSalary(double amount) const;

protected:
    std::string m_name;
    std::string m_institute;
    int m_employeenr;
};
#endif
