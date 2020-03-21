#ifndef STACK_2_H
#define STACK_2_H

#include <vector>
#include <cassert>

// A stack with specifiable underline container

template<typename T, typename C = std::vector<T>>
class Stack {
public:
    void push(const T&);
    void pop();
    const T& top() const;
    bool empty() const { return elems.empty(); }
private:
    C elems;
};

template<typename T, typename C>
void Stack<T, C>::push(const T& t)
{
    elems.push_back(t);
}

template<typename T, typename C>
void Stack<T, C>::pop()
{
    assert(!elems.empty());
    elems.pop_back();
}

template<typename T, typename C>
const T& Stack<T, C>::top() const
{
    assert(!elems.empty());
    return elems.back();
}

#endif // !STACK_2_H
