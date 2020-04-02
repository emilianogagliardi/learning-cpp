#ifndef DECLTYPE_SFINAE_H
#define DECLTYPE_SFINAE_H

#include <vector>
#include <list>
#include <iostream>

// idiom for SFINAEing out: put condition in trailing return 
// comma operator inside decltype check validity of first expression,
// then check validity of second expression and gives its type,
// set las argument for return type, and previous for conditions. 
// if condition gives error then substitution of type fails

template<typename T>
auto only_if_has_size(T t) -> decltype((void)(t.size()), t.size())
{
    return t.size();
}

void use_only_if_has_size()
{
    std::list<int> a{};
    std::vector<std::list<int>> b{};
    int c[10];
    std::cout << only_if_has_size(a) << "\n";
    std::cout << only_if_has_size(b) << "\n";
    // Compiler error!
    // std::cout << only_if_has_size(c) << "\n";
}

#endif // !DECLTYPE_SFINAE_H
