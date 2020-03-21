#ifndef STACK_H
#define STACK_H

#include <vector>
#include <cassert>
#include <iostream>

template<typename T> class Stack;

template<typename T>
std::ostream& operator<<(std::ostream& os, const Stack<T>& s);

template<typename T>
class Stack {
    friend std::ostream& operator<< <T> (std::ostream& os, const Stack<T>& s);
public:
    void push(const T&);
    T pop();
    const T& top() const;
    bool empty() const { return elems.empty(); }
    void printOn(std::ostream&) const;
private:
    std::vector<T> elems;
};

template<typename T>
void Stack<T>::push(const T& t)
{
    elems.push_back(t);
}

template<typename T>
T Stack<T>::pop()
{
    assert(!elems.empty());
    T ret = elems.back();
    elems.pop_back();
    return ret;
}

template<typename T>
const T& Stack<T>::top() const
{
    assert(!elems.empty());
    return elems.back();
}

template<typename T>
void Stack<T>::printOn(std::ostream& os) const
{
    for (const auto& e : elems)
        os << e << "\n";
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const Stack<T>& s)
{
    s.printOn(os);
    return os;
}

#endif // !STACK_H
