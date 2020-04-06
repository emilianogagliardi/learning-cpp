#ifndef VARIADIC_EXPRESSIONS_H
#define VARIADIC_EXPRESSIONS_H

#include "print.h"

template<typename... Args>
auto sum_foldl(Args... s)
{
    return (... + s);
}

// binary tree

struct Node {
    int t;
    Node* left;
    Node* right;
    Node(int t_) : t(t_), left(nullptr), right(nullptr) {}
};

template<typename T, typename... Ts>
Node* traverse(T node, Ts... nodes)
{
    return (node ->* ...->*nodes);
}

template <typename... Types>
void printDoubled(const Types&... args)
{
    // apply + elementwise
    print((args + args)...);
}

template <typename... Types>
void printPlusOne(const Types&... args)
{
    // add to each one
    print((args + 1)...);
}

// example of compile time expression

template <typename T, typename... TN>
constexpr bool isHomogeneous(T, TN...)
{
    // use fold expression (args op ...)
    // std::is_same<T, TN1>::value && is_same<T, TN2>::value ...
    return (std::is_same<T, TN>::value && ...);
}

// examples of variadic indices

template <typename C, typename... Idx>
void printElems(const C& c, Idx... idx)
{
    print(c[idx]...);
}

template<size_t... idx, typename C>
void printIdx(const C& c)
{
    print(c[idx]...);
}


#endif // !VARIADIC_EXPRESSIONS_H
