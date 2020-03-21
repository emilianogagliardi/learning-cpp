#ifndef STACK_H
#define STACK_H

#include <vector>
#include <deque>
#include <cassert>
#include <iostream>

template<typename T> class Stack;

template<typename T>
std::ostream& operator<<(std::ostream& os, const Stack<T>& s);

template<typename T>
class Stack {
    friend std::ostream& operator<< <T> (std::ostream& os, const Stack<T>& s);
public:
    Stack() { std::cout << "Tempalte stack\n"; }
    void push(const T&);
    void pop();
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
void Stack<T>::pop()
{
    assert(!elems.empty());
    elems.pop_back();
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

///////////////////////////////////////////////////////////////////////////////
// Class template specialization: stack of string
///////////////////////////////////////////////////////////////////////////////

template<>
class Stack<std::string> {
    // friends need not to be redeclared
public:
    Stack() { std::cout << "Stack of string specialization\n"; }
    void push(const std::string&);
    void pop();
    const std::string& top() const;
    bool empty() const { return elems.empty(); }
    void printOn(std::ostream&) const;
private:
    std::deque<std::string> elems;
};

void Stack<std::string>::push(const std::string& s)
{
    elems.push_back(s);
}

void Stack<std::string>::pop()
{
    assert(!elems.empty());
    elems.pop_back(); // remove last element
}
const std::string& Stack<std::string>::top() const
{
    assert(!elems.empty());
    return elems.back();
}

void Stack<std::string>::printOn(std::ostream& os) const
{
    for (const auto& e : elems)
        os << e << "\n";
}

#endif // !STACK_H
