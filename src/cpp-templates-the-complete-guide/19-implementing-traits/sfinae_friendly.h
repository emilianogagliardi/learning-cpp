#ifndef SFINAE_FRIENDLY_H
#define SFINAE_FRIENDLY_H

#include <type_traits>
#include <array>

// definition of a result plus SFINAE-friendly trait


// has plus predicate trait

template <typename T1, typename T2, typename = std::void_t<>>
struct HasPlusT : std::false_type {};

template <typename T1, typename T2>
struct HasPlusT<T1, T2,
    std::void_t<decltype(std::declval<T1>() + std::declval<T2>())>>
    : std::true_type {};

// plus result for elements that have + operator
template<typename T1, typename T2, 
    bool = HasPlusT<T1, T2>::value>
struct PlusResultSFINAEFriendlyT {
    using Type = decltype(std::declval<T1>() + std::declval<T2>());
};

// plus result for elements that do not have + operator (do not define type)
template<typename T1, typename T2>
struct PlusResultSFINAEFriendlyT<T1, T2, false> {};

template<typename T1, typename T2, std::size_t S>
std::array<typename PlusResultSFINAEFriendlyT<T1, T2>::Type, S>
add_arrays2(const std::array<T1, S>& a1, const std::array<T2, S>& a2)
{
    return {};
}

// NOTE Plus result is not SFINAE-friendly

class NonPlusC {};
class NonPlusD {};

template <std::size_t S>
std::array<NonPlusC, S> add_arrays2(std::array<NonPlusC, S>, std::array<NonPlusD, S>) {
    return {};
}

void use_sfinae_friendly()
{
    std::array<int, 4> a{ 1, 2, 3, 4 };
    std::array<int, 4> b = add_arrays2(a, a);
    std::array<NonPlusC, 1> nc;
    std::array<NonPlusD, 1> nd;
    add_arrays2(nc, nd); // no compile error
}

#endif // !SFINAE_FRIENDLY_H
