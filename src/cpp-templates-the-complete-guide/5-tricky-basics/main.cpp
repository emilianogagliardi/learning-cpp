#include <iostream>
#include "zero_initialization.h"
#include "stack.h"

void use_zero_initialization()
{
    std::cout << "ZERO INITIALIZATION\n";
    Bad<int> b;
    Good<int> g;
    Good<float> c;
    // std::cout << "uninitialized " << b.t << "\n"; // ERROR!
    std::cout << "initialized " << g.t << " " << c.t << "\n";
    std::cout << "\n";
}

void use_stack()
{
    Stack<int> s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    Stack<float> s2 = s1;
    std::cout << "copied s1: " << s1 << "to s2 " << s2 << "\n";
}

int main()
{
    use_zero_initialization();
    use_stack();
}