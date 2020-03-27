#ifndef STACK_H
#define STACK_H

#include <vector>
#include <iostream>
#include <iterator>

template <typename> class Stack;

template <typename T>
std::ostream& operator<<(std::ostream&, const Stack<T>&);

template<typename T>
class Stack {
    template <typename> friend class Stack;
    friend std::ostream& operator<< <T> (std::ostream& os, const Stack& s);
public:
    Stack() = default;
    // copy c'tor from stack of type convertible to T
    template<typename U>
    Stack(const Stack<U>&);
    void push(const T&);
    void pop();
    const T& top() const;
    bool empty() const { return elems.empty(); }
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
template<typename U>
Stack<T>::Stack(const Stack<U>& other)
{
    elems.clear();
    elems.insert(elems.begin(), other.elems.cbegin(), other.elems.cend());
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const Stack<T>& s)
{
    std::copy(s.elems.begin(), s.elems.end(),
        std::ostream_iterator<T>(os, " "));
    return os;
}

#endif // !STACK_H
