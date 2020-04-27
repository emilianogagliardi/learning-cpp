#ifndef IS_CONVERTIBLE_TO_EXAMPLE
#define IS_CONVERTIBLE_TO_EXAMPLE

#include <type_traits>

// SFINAE with overloading

template<typename FROM, typename TO>
struct IsConvertibleHelper {
private:
    static void aux(TO);

    template<typename F,
        typename = decltype(aux(std::declval<F>()))>
    static std::true_type test(void*);

    template<typename F>
    static std::false_type test(...);
public:
    using Type = decltype(test<FROM>(nullptr));
};

template<typename FROM, typename TO>
struct IsConvertibleT : IsConvertibleHelper<FROM, TO>::Type {};

// SFINAE with partial specialization 

template<typename FROM, typename TO, typename = std::void_t<>>
struct IsConvertible2 : std::false_type {};

template<typename TO>
void aux2(TO);

template<typename FROM, typename TO>
struct IsConvertible2 < FROM, 
                        TO, 
                        std::void_t<decltype(aux2<TO>(std::declval<FROM>()))>> 
    : std::true_type {};

// NOTE this implementaitons do not work with arrays, functions, and void type.
//      (fix on book)

void use_is_convertible()
{
    std::cout << "USE IS CONVERTIBLE TO\n";
    std::cout << "Is convertible int to float " 
              << IsConvertible2<int, float>::value << "\n";
    std::cout << "Is convertible string to int " 
              << IsConvertible2<std::string, int>::value << "\n";
    std::cout << "\n";
}

#endif // !IS_CONVERTIBLE_TO_EXAMPLE