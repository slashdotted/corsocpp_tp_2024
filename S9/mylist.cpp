#include "mylist.h"
#include <stdexcept>

MyList::MyList(int size)
{
    if (size <= 0) {
        throw std::out_of_range("Invalid size");
    }
    m_array = new int[size];
    m_size = size;
}
const int& MyList::operator[](int i) const
{
    if (i < 0 || i >= m_size) {
        throw std::out_of_range("Invalid index");
    }
    return m_array[i];
}
int& MyList::operator[](int i)
{
    if (i < 0 || i >= m_size) {
        throw std::out_of_range("Invalid index");
    }
    return m_array[i];
}
int MyList::size() const
{
    return m_size;
}
MyList::~MyList() {
    delete[] m_array;
}
