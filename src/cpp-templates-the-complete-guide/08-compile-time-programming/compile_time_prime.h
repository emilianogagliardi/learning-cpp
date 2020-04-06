#ifndef COMPILE_TIME_PRIME_H
#define COMPILE_TIME_PRIME_H

constexpr bool isPrime(unsigned int p)
{
    for (unsigned int d = 2; d <= p / 2; ++d) {
        if (p % d == 0) return false;
    }
    return p > 1;
}

void use_is_prime()
{
    std::cout << "IS PRIME\n";
    std::cout << isPrime(10) << "\n";
    std::cout << isPrime(11) << "\n";
    std::cout << isPrime(23) << "\n";
    std::cout << isPrime(1) << "\n";
    std::cout << isPrime(12) << "\n";
    std::cout << isPrime(157) << "\n";
    std::cout << "\n";
}

#endif // !COMPILE_TIME_PRIME_H
