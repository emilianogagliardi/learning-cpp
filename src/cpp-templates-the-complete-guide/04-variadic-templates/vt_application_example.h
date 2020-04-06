#ifndef VT_APPLICATION_EXAMPLE_H
#define VT_APPLICATION_EXAMPLE_H

// An example of use of variadic template
// (as for make_shared, make_unique....)
template <typename T, typename... Args>
T make(Args&&... args) // perfectly forward arguments
{
    return T(args...);
}

template <typename F, typename... Args>
auto call_function(F&& f, Args&&... args)
{
    return f(args...);
}

#endif // !VT_APPLICATION_EXAMPLE_H
