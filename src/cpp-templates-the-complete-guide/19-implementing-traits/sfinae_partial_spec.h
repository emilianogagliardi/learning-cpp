#ifndef SFINAE_PARTIAL_SPEC_H
#define SFINAE_PARTIAL_SPEC_H

#include <type_traits>

#ifndef __cpp_lib_void_t
namespace std {
template<typename...> using void_t = void;
}
#endif

// general case
template <typename T, typename = std::void_t<>>
struct IsDefaultConstructiblePartSpecT : std::false_type {};

// specialization
template<typename T>
struct IsDefaultConstructiblePartSpecT<T, std::void_t<decltype(T())>> : std::true_type {};

// try the implementations

struct C {
    C() = delete;
};

struct D {
    D() = default;
};

void use_sfinae_partial_spec()
{
    std::cout << "USE SFINAE PARTIAL SPECTIALIZATION\n";
    std::cout << IsDefaultConstructiblePartSpecT<C>::value << "\n";
    std::cout << IsDefaultConstructiblePartSpecT<D>::value << "\n";
    std::cout << "\n";
}

#endif // !SFINAE_PARTIAL_SPEC_H
