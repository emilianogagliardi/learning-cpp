#ifndef PREDICATE_TRAITS_H
#define PREDICATE_TRAITS_H

template<bool B>
struct BoolType {
    using Type = BoolType<B>;
    static constexpr bool value = B;
};

using FalseType = BoolType<false>;
using TrueType = BoolType<true>;

template<typename T1, typename T2>
struct IsSameT : FalseType {};

template<typename T>
struct IsSameT<T, T> : TrueType {};

template<typename T1, typename T2>
constexpr bool isSame = IsSameT<T1, T2>::value;

template<typename T1, typename T2>
using IsSame = typename IsSameT<T1, T2>::Type;

// tag dispatching example

template<typename T>
void fooImpl(T, FalseType) {
    std::cout << "called for non int\n";
}

template<typename T>
void fooImpl(T, TrueType) {
    std::cout << "called for int\n";
}

template<typename T>
void foo(T t) {
    fooImpl(t, IsSame<T, int>{});
}

void use_predicate_traits() {
    std::cout << "USE PREIDCATE TRAITS\n";
    int a{};
    bool b{};
    foo(a);
    foo(b);
}

#endif // !PREDICATE_TRAITS_H
