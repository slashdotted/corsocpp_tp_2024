#pragma once

class MyList {
public:
    explicit MyList(int size);
    MyList(const MyList& o) = delete;
    MyList(const MyList&& o) = delete;
    int& operator=(const MyList& o) = delete;
    int& operator=(const MyList&& o) = delete;
    ~MyList();
    int& operator[](int i);
    const int& operator[](int i) const;
    int size() const;
private:
    int* m_array;
    int m_size;
};
