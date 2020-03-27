#include <iostream>
#include "zero_initialization.h"
#include "stack.h"
#include "stack2.h"
#include <deque>

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
    // This line does not print "called converting copy ctor". 
    // Indeed the defined template constructor does not prevent the
    // compiler to generate the default copy constructor
    auto s3 = s1;
}

void use_stack2()
{
    Stack2<int> s;
    s.push(1);
    s.push(1);
    s.push(1);
    Stack2<bool, std::deque> s2;
    s2.push(true);
    s2.push(true);
    s2.push(true);
    std::cout << s << "and " << s2 << "\n";
}

int main()
{
    use_zero_initialization();
    use_stack();
    use_stack2();
}