#ifndef RESULT_TYPE_TRAITS_H
#define RESULT_TYPE_TRAITS_H

#include "remove_reference.h"
#include "removing_qualifiers.h"
#include <array>

template<typename T1, typename T2>
struct PlusResultT {
    // Use declval instead of T1() to avoid requirement of default 
    // constructible types. This is useless for the below implementation 
    // because std::array requires default constructible value type
    using Type = decltype(std::declval<T1>() + std::declval<T2>());
};

template<typename T1, typename T2>
using PlusResult = typename PlusResultT<T1, T2>::Type;

template<typename T1, typename T2, std::size_t S>
std::array<RemoveConstVolatile<RemoveReference<PlusResult<T1, T2>>>, S> 
    add_arrays(const std::array<T1, S>& a1, const std::array<T2, S>& a2)
{
    std::array<RemoveConstVolatile<RemoveReference<PlusResult<T1, T2>>>, S> a;
    for (auto i = 0; i < S; ++i)
        a[i] = a1[i] + a2[i];
    return a;
}

// NOTE Plus result is not SFINAE-friendly

class NonPlusA {};
class NonPlusB {};

template <std::size_t S>
std::array<NonPlusA, S> add_arrays(std::array<NonPlusA, S>, std::array<NonPlusB, S>) {}

void use_result_traits()
{
    std::array<int, 4> a{ 1, 2, 3, 4 };
    std::array<int, 4> b = add_arrays(a, a);
    std::array<NonPlusA, 1> na;
    std::array<NonPlusB, 1> nb;
    //add_arrays(na, nb); // compile error
}

#endif // !RESULT_TYPE_TRAITS_H
