#ifndef UNIQUE_PTR_H
#define UNIQUE_PTR_H
#include <iostream>

template <typename T>
class unique_ptr
{
private:
    /* data */
    T* m_ptr;
public:
    unique_ptr(T* ptr): m_ptr(ptr) {
        ptr=nullptr;
    }
    unique_ptr(const T*)=delete;
    unique_ptr& operator= (const T*)= delete;
    unique_ptr(T*&&)=default;
    unique_ptr& operator=(T*&&)=default;
    void Release(){ delete m_ptr;
    m_ptr=nullptr; }
    ~unique_ptr() { delete _mptr;
    m_ptr=nullptr;}
};

#endif // UNIQUE_PTR_H
