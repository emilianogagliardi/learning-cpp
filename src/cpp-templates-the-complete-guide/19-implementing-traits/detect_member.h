#ifndef DETECT_TYPE_MEMBER_H
#define DETECT_TYPE_MEMBER_H

#include <vector>
#include <type_traits>
#include <iostream>

// Check if input type defines size_type

template<typename, typename = std::void_t<>>
struct HasSizeT : std::false_type {};

template<typename T>
struct HasSizeT <T, std::void_t<typename std::remove_reference<T>::Type::size_type>> : std::true_type {};

// Check if input type defines member function 

template<typename T, typename = std::void_t<>>
struct HasBeginT : std::false_type {};

template<typename T>
struct HasBeginT < T, std::void_t<decltype(std::declval<T>().begin())>> : std::true_type {};

void use_detect_member()
{
    std::cout << "USE HAS SIZE \n";
    std::cout << "has size int " << HasSizeT<int>::value << "\n";
    std::cout << "has size std::vector<int> " << HasSizeT<std::vector<int>>::value << "\n";
    std::cout << "has begin int " << HasBeginT<int>::value << "\n";
    std::cout << "has begin std::vector<int> " << HasBeginT<std::vector<int>>::value << "\n";
    std::cout << "\n";
}

#endif // !DETECT_MEMBER_H
