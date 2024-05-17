#include "data.h"

static void checkCounter2(int counter);

struct Data::pimpl {
    int m_counter;
    std::string m_name;
    double c;
    std::string m_another_string;
};

void Data::checkCounter()
{
    if (m_pimpl->m_counter < 0) {
        throw "Bad value";
    }
}


Data::Data()
    : /*m_pimpl{new pimpl}*/ m_pimpl{std::make_unique<pimpl>()}
{
    m_pimpl->m_counter = 5;
    checkCounter();
    checkCounter2(m_pimpl->m_counter);
}

static void checkCounter2(int counter) {
    if (counter < 0) {
        throw "Bad value";
    }
}


Data::~Data() = default;

/*Data::~Data()
{
    delete m_pimpl;
}*/
