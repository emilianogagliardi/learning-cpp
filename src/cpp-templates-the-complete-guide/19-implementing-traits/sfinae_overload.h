#ifndef SFINAE_OVERLOAD_H
#define SFINAE_OVERLOAD_H

#include "result_type_traits.h"
#include <iostream>

// Use SFINAE and overload resultion to make a traits that check if a type
// defines the default constructor

template<typename T>
struct IsDefaultConstructibleOverloadT {
private:
    // test() trying substitute call of a default constructor for T passed as U:
    template<typename U, typename = decltype(U())>
    static char test(void*);
    // test() fallback:
    template<typename>
    static long test(...);
public:
    static constexpr bool value
        = IsSameT<decltype(test<T>(nullptr)), char>::value;
};

// Alternative implementation, still based on overload resolution
// (used before the definition of constexpr and nullptr)

using Size1T = char;
using Size2T = struct { char a[2]; };

template<typename T, typename = decltype(T())> Size1T test(int);
template<typename> Size2T test(...);

template<typename T>
struct IsDefaultConstructibleOverloadT2 {
    enum { value = sizeof(test<T>(0)) == sizeof(Size1T) };
};

// Improved implementation, makes use of true_type and false_type

template<typename T>
struct IsDefaultConstructibleOverloadT3Helper {
private:
    template<typename U, typename = decltype(U())>
    static TrueType test(void*);
    
    template<typename>
    static FalseType test(...);
public:
    using Type = decltype(test<T>(nullptr));
};

template<typename T>
struct IsDefaultConstructibleOverloadT3 : 
    public IsDefaultConstructibleOverloadT3Helper<T>::Type {};

// try the implementations

struct A {
    A() = delete; 
};

struct B { 
    B() = default;
};

void use_sfinae_overload()
{
    std::cout << "USE SFINAE OVERLOAD\n";
    std::cout << IsDefaultConstructibleOverloadT2<A>::value << " " 
        << IsDefaultConstructibleOverloadT2<A>::value << " " 
        << IsDefaultConstructibleOverloadT3<A>::value << "\n";
    std::cout << IsDefaultConstructibleOverloadT2<B>::value << " "
        << IsDefaultConstructibleOverloadT2<B>::value << " " 
        << IsDefaultConstructibleOverloadT3<B>::value << "\n";
    std::cout << "\n";
}

#endif // !SFINAE_OVERLOAD_H
