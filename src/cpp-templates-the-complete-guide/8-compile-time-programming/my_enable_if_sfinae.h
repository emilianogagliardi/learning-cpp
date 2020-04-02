#ifndef MY_ENABLE_IF_SFINAE_H
#define MY_ENABLE_IF_SFINAE_H

#include <type_traits>

// Substitution failure is not an error

// enable if implementation is based on sfinae principle

template<bool, typename T>
struct my_enable_if_helper {};

template<typename T>
struct my_enable_if_helper<true, T> {
    using type = T;
};

template<bool Cond, typename T = void>
struct my_enable_if {
    using type = typename my_enable_if_helper<Cond, T>::type;
};

template<bool Cond, typename T = void>
using my_enable_if_t = typename my_enable_if<Cond, T>::type;

template <typename T, 
    typename = my_enable_if_t<std::is_same_v<T, int>>>
void fun(T t) {}

void use_my_enable_if()
{
    int a = 1;
    double b = 2.1;
    fun(a);
    // Compile error! 
    // my_enable_if_t<false, void>              expands to
    // my_enable_if<false, void>::type          expands to
    // my_enable_if_helper<false, void>::type   which is undefined
    //fun(b);
}

#endif // !MY_ENABLE_IF_SFINAE_H
