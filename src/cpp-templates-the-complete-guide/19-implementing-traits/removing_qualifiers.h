#ifndef REMOVING_QUALIFIERS_H
#define REMOVING_QUALIFIERS_H

// Remove constant qualifier

template<typename T>
struct RemoveConstT {
    using Type = T;
};

template<typename T>
struct RemoveConstT<const T> {
    using Type = T;
};

template<typename T>
using RemoveConst = typename RemoveConstT<T>::Type; 

// Remove volatile qualifier

template<typename T>
struct RemoveVolatileT {
    using Type = T;
};

template<typename T>
struct RemoveVolatileT<volatile T> {
    using Type = T;
};

template<typename T>
using RemoveVolatile = typename RemoveVolatileT<T>::Type;

// Remove bot
template<typename T>
struct RemoveConstVolatileT : RemoveConstT<typename RemoveVolatileT<T>::Type> {};

template<typename T>
using RemoveConstVolatile = typename RemoveConstVolatileT<T>::Type;

void use_remove_qualifiers()
{
    std::cout << "USE REMOVE QUALIFIERS\n";
    std::cout << "std::is_const_v<RemoveConst<const int>> " << 
        std::is_const_v<RemoveConst<const int>> << "\n";
    std::cout << "std::is_volatile_v<RemoveVolatile<volatile int>> " <<
        std::is_volatile_v<RemoveVolatile<volatile int>> << "\n";
    std::cout << "std::is_const_v<RemoveConstVolatile<const volatile int>> " <<
        std::is_const_v<RemoveConstVolatile<const volatile int>> << "\n";
    std::cout << "std::is_volatile_v<RemoveConstVolatile<const volatile int>> " <<
        std::is_volatile_v<RemoveConstVolatile<const volatile int>> << "\n\n";
}

#endif