#include <iostream>


// Zero initialization

template <typename T>
struct Bad {
    T t;
};

template <typename T>
struct Good
{
    T t{};
};

int main()
{
    Bad<int> b;
    Good<int> g;
    Good<float> c;
    // std::cout << "uninitialized " << b.t << "\n"; // ERROR!
    std::cout << "initialized " << g.t  << " "<< c.t << "\n";
}