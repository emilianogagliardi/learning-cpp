#ifndef PERFECT_FORWARDING_H
#define PERFECT_FORWARDING_H

#include <iostream>

struct X {};

void g(const X&) { std::cout << "const l-value\n"; }
void g(X&) { std::cout << "non const l-value\n"; }
void g(X&&) { std::cout << "r-value reference\n"; }

// x is a forwarding reference. It can be bound to mutable, 
// immutable, and movable objects.
template <typename T> void f(T&& x) { g(std::forward<T>(x)); } 

void use_f()
{
    const X x1;
    X x2;
    f(x1);
    f(x2);
    f(X());
    f(std::move(x2));
}

#endif // !PERFECT_FORWARDING_H
