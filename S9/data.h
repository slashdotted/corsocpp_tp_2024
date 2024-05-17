#pragma once
#include <string>
#include <memory>

class Data {
private:
    struct pimpl;
    //pimpl* m_pimpl;
    std::unique_ptr<pimpl> m_pimpl;

    void checkCounter();
public:
    Data();
    ~Data();
    //Data(const Data&) = delete;
    //Data& operator=(const Data&) = delete;
    int m_x;
    double m_y;
    std::string m_s;
};
