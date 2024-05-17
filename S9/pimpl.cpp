#include "data.h"
#include <iostream>

int main() {
    using namespace std;
    Data d;
    cout << "Offset of m_x in Data: " << ((unsigned long)&d.m_x - (unsigned long)&d) << " bytes\n";
    cout << "Offset of m_y in Data: " << ((unsigned long)&d.m_y - (unsigned long)&d) << " bytes\n";
    cout << "Offset of m_s in Data: " << ((unsigned long)&d.m_s - (unsigned long)&d) << " bytes\n";
}
