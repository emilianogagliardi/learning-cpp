#ifndef TEMPLATE_FUN_BASICS_H
#define TEMPLATE_FUN_BASICS_H

#include <type_traits>

template<typename T>
T max_1templateArg(T a, T b)
{
    // T is anything that defines operator <
    // and copy operator
    return b < a ? a : b;
}

template<typename T1, typename T2>
T1 max_2templateArg_retFirst(T1 a, T2 b)
{
    return b < a ? a : b;
}

template<typename RT, typename T1, typename T2>
RT max_3templateArg(T1 a, T2 b)
{
    return b < a ? a : b;
}

// Let return type to be deduced from return statement
// c++14
// BEST SOLUTION
template<typename T1, typename T2>
auto max_2templateArgs_auto(T1 a, T2 b)
{
    return b < a ? a : b;
}

// Specify return type with trayling
// c++11
template<typename T1, typename T2>
auto max_2templateArgs_trayling(T1 a, T2 b) 
    -> typename std::decay<decltype(true ? a : b)>::type
{
    return b < a ? a : b;
}

template<typename T1, typename T2>
std::common_type_t<T1, T2> max_2tempalteArgs_common(T1 a, T2 b)
{
    return b < a ? a : b;
}

// requireS T1 and T2 to be default constructible
template<typename T1, typename T2,
    typename RT = std::decay_t<decltype(true ? T1() : T2())>>
    RT max_3templateArgs_retDefault(T1 a, T2 b)
{
    return b < a ? a : b;
}

template<typename T1, typename T2,
    typename RT = std::common_type_t<T1, T2>>
    RT max_3templateArgs_retDefault2(T1 a, T2 b)
{
    return b < a ? a : b;
}

#endif // !TEMPLATE_FUN_BASICS_H