#ifndef TEMPLATE_FUN_OVERLOAD_H
#define TEMPLATE_FUN_OVERLOAD_H

#include <iostream>

int max_overload(int a, int b) {
    std::cout << "#1\n";
    return b < a ? a : b;
}

template<typename T>
T max_overload(T a, T b) {
    std::cout << "#2\n";
    return b < a ? a : b;
}

#endif // !TEMPLATE_FUN_OVERLOAD_H
