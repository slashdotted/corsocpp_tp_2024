#include "lecturerresearcher.h"
#include <iostream>

using std::cout;
using std::endl;
using std::string;

LecturerResearcher::LecturerResearcher(
    std::string name, std::string institute, int nr,
    std::string studies, std::string course,
    std::string researcharea, double research_perc)
    : m_researchperc{research_perc}
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
