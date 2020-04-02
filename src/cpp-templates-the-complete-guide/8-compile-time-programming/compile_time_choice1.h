#ifndef COMPILE_TIME_CHOICE_1_H
#define COMPILE_TIME_CHOICE_1_H

#include "compile_time_prime.h"
#include <array>
#include <iostream>

// Perform compile time choice by callable class template partial specification
// Could also use class with static function

template<size_t SIZE, bool = isPrime(SIZE) > struct Helper;

template<size_t SIZE>
struct Helper<SIZE, true>
{
    void operator()()
    {
        std::cout << "executing prime version\n";
    }
};

template<size_t SIZE>
struct Helper<SIZE, false>
{
    void operator()()
    {
        std::cout << "executing non-prime version\n";
    }
};


template<size_t SIZE>
void fun1(std::array<int, SIZE>)
{
    Helper<SIZE> h;
    h();
}


void use_compile_time_choice1()
{
    std::cout << "COMPILE TIME CHOICE 1\n";
    std::array<int, 11> aPrime{};
    std::array<int, 10> aNonPrime{};
    fun1(aPrime);
    fun1(aNonPrime);
    std::cout << "\n";
}

#endif // !COMPILE_TIME_CHOICE_1_H
