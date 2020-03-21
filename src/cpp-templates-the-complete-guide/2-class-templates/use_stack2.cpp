#include "stack2.h"

#include <deque>
#include <list>
#include <set>

int main() 
{
    Stack<int> stackVectorInt;
    stackVectorInt.push(1);
    stackVectorInt.push(1);

    Stack<double, std::deque<double>> stackDequeDouble;
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
}