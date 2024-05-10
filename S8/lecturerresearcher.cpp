#include "lecturerresearcher.h"
#include <iostream>

using std::cout;
using std::endl;
using std::string;

LecturerResearcher::LecturerResearcher(std::string name,
                                       std::string institute,
                                       int nr,
                                       std::string studies,
                                       std::string course,
                                       std::string researcharea,
                                       double research_perc)
    : Employee{name,institute,nr}, Lecturer{name, institute, nr, studies, course}
    , Researcher{name, institute, nr, researcharea}
    , m_researchperc{research_perc}
{
    cout << "Costructing LecturerResearcher" << endl;
}
LecturerResearcher::~LecturerResearcher()
{
    cout << "Destroying LecturerResearcher" << endl;
}

string LecturerResearcher::classname() const
{
    return "LecturerResearcher";
}

double LecturerResearcher::researchpercentage() const
{
    return m_researchperc;
}
