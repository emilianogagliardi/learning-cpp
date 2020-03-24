#ifndef VARIADIC_CLASS_TEMPLATES_H
#define VARIADIC_CLASS_TEMPLATES_H

template<size_t... Idx>
struct Indices {};

template<typename C, size_t... Idx>
void printElements2(C c, Indices<Idx...>)
{
    print(std::get<Idx>(c)...);
}

#endif // !VARIADIC_CLASS_TEMPLATES_H
