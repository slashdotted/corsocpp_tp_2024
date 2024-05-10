#pragma once
#include <string>
#include "lecturer.h"
#include "researcher.h"

class LecturerResearcher : public Lecturer, public Researcher
{
public:
    LecturerResearcher(
        std::string name, std::string institute, int nr,
        std::string studies, std::string course,
        std::string researcharea, double research_perc);
    ~LecturerResearcher();
    std::string classname() const;
    double researchpercentage() const;

protected:
    double m_researchperc;
};
