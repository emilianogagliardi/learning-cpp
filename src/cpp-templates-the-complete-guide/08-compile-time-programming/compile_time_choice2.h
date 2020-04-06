#ifndef COMPILE_TIME_CHOICE_2_H
#define COMPILE_TIME_CHOICE_2_H

#include "compile_time_prime.h"
#include <iostream>

// Perform compile time choice by constexpr if

template<size_t SIZE>
void fun2(std::array<int, SIZE>)
{
    if constexpr (isPrime(SIZE)) {
        std::cout << "executing prime version\n";
    }
    else {
        std::cout << "executing non-prime version\n";
    }
}

void use_compile_time_choice2()
{
    std::cout << "COMPILE TIME CHOICE 2\n";
    std::array<int, 11> aPrime{};
    std::array<int, 10> aNonPrime{};
    fun2(aPrime);
    fun2(aNonPrime);
    std::cout << "\n";
}

#endif // !COMPILE_TIME_CHOICE_2_H
