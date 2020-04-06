#ifndef VARIADIC_CLASS_TEMPLATES_H
#define VARIADIC_CLASS_TEMPLATES_H

#include <type_traits>
#include <unordered_set>

// Template type represented by some indices

template<size_t... Idx>
struct Indices {};

template<typename C, size_t... Idx>
void printElements2(C c, Indices<Idx...>)
{
    print(std::get<Idx>(c)...);
}

// Array style class

template<typename T, size_t S> class my_array {
public:
    template<typename U, typename... Us>
    my_array(U u, Us... us) : data{u, us...} {}
    T* begin() { return data; }
    T* end() { return data + S; }
private:
    T data[S];
};

// deduction guide for array constructor
template<typename U, typename... Us> my_array(U, Us...)->my_array<
    std::enable_if_t<(std::is_same_v<U, Us> && ...), U>,
    (1 + sizeof...(Us))>;

// example: deriving the variadic argument

struct Customer {
    std::string name;
};

struct CustomerEq {
    bool operator() (const Customer& c1, const Customer& c2) const
    {
        return c1.name == c2.name;
    }
};

struct CustomerHash {
    std::size_t operator() (const Customer& c) const
    {
        return std::hash<std::string>()(c.name);
    }
};

template<typename... Bases> 
class Overloader : Bases... {
    using Bases::operator()...;
};

#endif // !VARIADIC_CLASS_TEMPLATES_H
