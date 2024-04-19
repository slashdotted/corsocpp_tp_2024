#pragma once
#include <string>
#include "employee.h"

struct Researcher : public Employee
{
public:
    Researcher(std::string name, std::string institute, int nr, std::string researcharea);
    ~Researcher();
    const std::string &researcharea() const;
    std::string classname() const override;
    void doSomeWork() override;

protected:
    std::string m_researcharea;
};
