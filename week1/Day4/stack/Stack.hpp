#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
#include <list>
#include "StackEmptyException.hpp"

template <typename T>
class Stack
{
private:
    std::list<T> m_data{};

public:
    Stack() = default;
    Stack(const Stack &) = delete;
    Stack &operator=(const Stack &) = delete;
    Stack(Stack &&) = default;
    Stack &operator=(Stack &&) = default;
    ~Stack() = default;

    Stack(const T val)
    {
        m_data.push_back(val);
    }
    void Pop();

    /* Push fun accepts one item "val" of type T, return void */
    void Push(T val)
    {
        m_data.push_back(val);
    }

    T Peek()
    {
        if (m_data.empty())
        {
            // throw stack empty!!!
            throw StackEmptyException("Data is Empty");
        }
        return m_data.back();
    }

    size_t Size() { return m_data.size(); }

    bool IsEmpty() { return m_data.empty(); }
};

#endif // STACK_HPP

template <typename T>
inline void Stack<T>::Pop()
{
    if (m_data.empty())
    {
        throw StackEmptyException("Data is Empty");
    }

    m_data.pop_back();
}
