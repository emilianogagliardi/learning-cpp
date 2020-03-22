#include "stack2.h"

#include <deque>
#include <list>
#include <set>

// From c++11 can define alias tempaltes

template<typename T>
using StackDeque = Stack<T, std::deque<T>>;

int main() 
{
    Stack<int> stackVectorInt;
    stackVectorInt.push(1);
    stackVectorInt.push(1);

    // Class template argument deduction (here deduced from copy constructor)
    auto stackVectorInt2 = stackVectorInt;

    StackDeque<double> stackDequeDouble;
    stackDequeDouble.push(1.0);
    stackDequeDouble.push(1.0);

    Stack<int, std::list<int>> stackListInt;
    stackListInt.push(1);
    stackListInt.push(1);
    stackListInt.pop();
    stackListInt.top();

    Stack<double, std::set<double>> stackSetDouble;
    stackSetDouble.empty();
    // Error, set does not define push_back, pop_back, back
    // stackSetDouble.push(2.0);
    // stackSetDouble.top();
    // stackSetDouble.pop();

    // Use deduction guide from c-style string to std::string
    Stack stringStack{ "ciao" };
    stringStack.push("2");
    auto s = stringStack.top();
}