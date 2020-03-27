#ifndef ZERO_INITIALIZATION_H
#define ZERO_INITIALIZATION_H

template <typename T>
struct Bad {
    T t;
};

template <typename T>
struct Good
{
    T t{};
};

#endif // !ZERO_INITIALIZATION_H
