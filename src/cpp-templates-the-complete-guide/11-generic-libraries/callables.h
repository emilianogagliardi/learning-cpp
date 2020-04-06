#ifndef CALLABLES_H
#define CALLABLES_H

#include <iostream>
#include <array>


template<typename Iter, typename Callable, typename... Args>
void foreach(Iter current, Iter end, Callable op, const Args&... args)
{
    while (current != end) {
        // NOTE: can not forward declare because op might steal args status
        std::invoke(op, args..., *current); 
        ++current;
    }
}

// Some callables to pass to foreach

struct MyCallable1 {
    char separator;

    void operator()(int i)
    {
        std::cout << i << separator;
    }
};

void MyCallable2(char separator, int i)
{
    std::cout << i << separator;
}

struct UselessStruct{
    char separator;

    static void MyCallable3(char separator, int i)
    {
        std::cout << i  << separator;
    }

    void MyCallable4(int i) const
    {
        std::cout << i << separator;
    }
};


void use_foreach()
{
    std::cout << "USE FOREACH\n";
    std::array a{ 1, 2, 3, 4, 5 };
    // lambda
    foreach(a.begin(), a.end(), [](char s, int i) {std::cout << i << s; }, '.');
    std::cout << "\n";
    // operator()
    MyCallable1 myCallable1{ ',' };
    foreach(a.begin(), a.end(), myCallable1);
    std::cout << "\n";
    // function pointer
    foreach(a.begin(), a.end(), MyCallable2, ':'); // note: dacays to fn ptr
    std::cout << "\n";
    // static member
    foreach(a.begin(), a.end(), &UselessStruct::MyCallable3, ';');
    std::cout << "\n";
    // non static member, thanks to the use of std::invoke
    UselessStruct us{ '-' };
    foreach(a.begin(), a.end(), &UselessStruct::MyCallable4, us);
    std::cout << "\n";
    std::cout << "\n";
}

#endif // !CALLABLES_H