#ifndef STACK2_H
#define STACK2_H

#include <vector>
#include <iostream>
#include <iterator>

template<typename, template<typename> class> class Stack2;

template<typename T, template<typename> class Cont>
std::ostream& operator<<(std::ostream&, const Stack2<T, Cont>&);

template<typename T, template<typename> class Cont = std::vector>
class Stack2 {
    friend std::ostream& operator<< <T, Cont> (std::ostream&, const Stack2&);
public:
    void push(const T&);
    void pop();
    const T& top() const;
    bool empty() const { return elems.empty(); }
private:
    Cont<T> elems;
};

template<typename T, template<typename> class Cont>
void Stack2<T, Cont>::push(const T& t)
{
    elems.push_back(t);
}

template<typename T, template<typename> class Cont>
void Stack2<T, Cont>::pop()
{
    assert(!elems.empty());
    elems.pop_back();
}

template<typename T, template<typename> class Cont>
const T& Stack2<T, Cont>::top() const
{
    assert(!elems.empty());
    return elems.back();
}

#endif // !STACK2_H

template<typename T, template<typename> class Cont>
inline std::ostream& operator<<(std::ostream& os, const Stack2<T, Cont>& s)
{
    std::copy(s.elems.cbegin(), s.elems.cend(),
        std::ostream_iterator<T>(os, " "));
    return os;
}
