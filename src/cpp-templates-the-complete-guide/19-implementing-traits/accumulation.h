#ifndef ACCUM_H
#define ACCUM_H

#include <type_traits>
#include <iostream>

template<typename T>
struct AccumulationTraits {};

template<>
struct AccumulationTraits<char> {
    using AccT = int;
};

template<>
struct AccumulationTraits<int> {
    using AccT = long;
};

template<typename Iter, 
         typename Traits = std::iterator_traits<Iter>::value_type>
auto accum(Iter beg, Iter end)
{
    using VT = std::iterator_traits<Iter>::value_type;
    using AccT = AccumulationTraits<VT>::AccT;

    AccT total{};
    while (beg != end) {
        total += *beg;
        ++beg;
    }
    return total;
}

void use_accumulate()
{
    std::cout << "USE ACCUMULATE\n";
    char name[] = "templates";
    int length = sizeof(name) - 1;
    std::cout << "the average value of the characters in \""
        << name << "\" is "
        << accum(name, name + length) / length
        << '\n';
    std::cout << "\n";
}

#endif // !ACCUM_H