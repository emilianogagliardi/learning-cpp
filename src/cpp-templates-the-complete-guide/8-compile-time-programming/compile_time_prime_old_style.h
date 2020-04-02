#ifndef COMPILE_TIME_PRIME_OLD_STYLE_H
#define COMPILE_TIME_PRIME_OLD_STYLE_H

#include <type_traits>
#include <iostream>

template<unsigned p, unsigned d>
struct is_prime_impl {
    static constexpr bool value = (p % d) != 0 && is_prime_impl<p, d - 1>::value;
};

template<unsigned p>
struct is_prime_impl<p, 2> {
    static constexpr bool value = (p % 2) != 0;
};

template<unsigned p>
struct is_prime {
    static constexpr bool value = is_prime_impl<p, p/2>::value;
};

// special cases (to avoid endless recursion with template instantiation):
template<>
struct is_prime<0> { static constexpr bool value = false; };
template<>
struct is_prime<1> { static constexpr bool value = false; };
template<>
struct is_prime<2> { static constexpr bool value = true; };
template<>
struct is_prime<3> { static constexpr bool value = true; };

void use_is_prime_old_style()
{
    std::cout << "IS PRIME OLD STYLE \n";
    std::cout << is_prime<10>::value << "\n";
    std::cout << is_prime<11>::value << "\n";
    std::cout << is_prime<23>::value << "\n";
    std::cout << is_prime<1>::value << "\n";
    std::cout << is_prime<12>::value << "\n";
    std::cout << is_prime<157>::value << "\n";
    std::cout << "\n";
}

#endif // !COMPILE_TIME_PRIME_OLD_STYLE_H
