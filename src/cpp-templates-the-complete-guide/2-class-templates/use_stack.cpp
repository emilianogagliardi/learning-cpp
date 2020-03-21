#include "stack.h"

int main() 
{
    Stack<std::pair<int, int>> pairsStack;
    pairsStack.push({ 1, 2 });
    pairsStack.push({ 1, 2 });
    auto a = pairsStack.top();
    pairsStack.pop();
    // No operator<< defined for pair, call to this line cause compile error
    // If not called the member method is not instantiated, thus can use stack
    // event with types for which operator<< is defined (as std::pair)
    // pairsStack.printOn(std::cout);

    Stack<int> si;
    si.push(1);
    si.push(1);
    si.push(1);
    si.push(1);
    std::cout << si << "\n";

    Stack<std::string> stringStack;
    stringStack.push("ciao");
    stringStack.push("ciao");
    stringStack.push("ciao");
    std::cout << stringStack;
}