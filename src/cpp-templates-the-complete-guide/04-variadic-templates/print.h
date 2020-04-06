#ifndef PRINT_H
#define PRINT_H

#include<iostream>

template<typename T>
void print(T t) 
{
    std::cout << t << " ";
}

template <typename T, typename ... Types>
void print(T first, Types... args)
{
    // exploits template fun overloading: the single template fun is 
    // a better match than the one with ellipses
    print(first);
    print(args...);
}

// Use compile time if and sizeof... to stop when no args are remaining
template <typename T, typename... Types>
void print2(T first, Types... args)
{
    std::cout << first << " ";
    if constexpr (sizeof...(Types) > 0)
        print2(args...);
    else std::cout << "\n";
}

template<typename T>
class AddSpace {
    friend std::ostream& operator<<(std::ostream& os, AddSpace<T> s)
    {
        return os << s.ref << " ";
    }
public:
    AddSpace(const T& r) : ref(r) {}
private:
    const T& ref;
};

// Use fold expression (c++17)
template <typename... Types>
void print3(const Types&... args)
{
    (std::cout << ... << AddSpace(args)) << "\n";
}

#endif // !PRINT_H
