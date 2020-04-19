#ifndef DECAY_H
#define DECAY_H

#include <iostream>
#include <typeinfo>
#include <type_traits>
#include "removing_qualifiers.h"

// Non array non function case
template<typename T>
struct DecayT : RemoveConstVolatileT<T> {};

// From array to pointer

template<typename T>
struct DecayT<T[]> {
    using Type = T*;
};

template<typename T, size_t S>
struct DecayT<T[S]> {
    using Type = T*; 
};

// From function to function pointer

template<typename R, typename... Args>
struct DecayT<R(Args...)> {
    using Type = R(*) (Args...);
};

template<typename R, typename... Args> // c-style varargs
struct DecayT<R(Args..., ...)> {
    using Type = R(*)(Args..., ...);
};

template<typename T>
using Decay = typename DecayT<T>::Type;

template<typename T>
void printDecayedType()
{
    using A = typename Decay<T>;
    std::cout << "Parameter type: " << typeid(A).name() << '\n';
    std::cout << "- is int: " << std::is_same<A, int>::value << '\n';
    std::cout << "- is const: " << std::is_const<A>::value << '\n';
    std::cout << "- is pointer: " << std::is_pointer<A>::value << '\n';
}

void use_decay()
{
    std::cout << "USE DECAY\n";
    printDecayedType<int>();
    printDecayedType<int const>();
    printDecayedType<int[7]>();
    printDecayedType<int(int)>();
    std::cout << "\n";
}

#endif // !DECAY_H
