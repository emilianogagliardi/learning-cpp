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

template<typename T1, typename T2>
auto max_overload1(T1 a, T2 b)
{
    std::cout << "#3\n";
    return b < a ? a : b;
}

template<typename RT, typename T1, typename T2>
auto max_overload1(T1 a, T2 b)
{
    std::cout << "#4\n";
    return b < a ? a : b;
}

template<typename T>
T max_overload3(T a, T b)
{
    std::cout << "#5\n";
    return b < a ? a : b;
}

// maximum of two pointers:
template<typename T>
T* max_overload3(T* a, T* b)
{
    std::cout << "#6\n";
    return *b < *a ? a : b;
}

// maximum of two C-strings:
char const* max_overload3(char const* a, char const* b)
{
    std::cout << "#7\n";
    return std::strcmp(b, a) < 0 ? a : b;
}


#endif // !TEMPLATE_FUN_OVERLOAD_H
