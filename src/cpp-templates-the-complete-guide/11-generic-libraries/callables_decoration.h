#ifndef CALLABLES_DECORATION_H
#define CALLABLES_DECORATION_H

#include <utility>
#include <functional>
#include <chrono>
#include <string>
#include <type_traits>

// We want to wrap the call of a function:
// wrapper(f, args...) 
// {
//     // do something 
//     res = f(args...);
//     // do something
//     return res;
// }
// Problem if return type of f is void you cant store the returned value in 
// the res variable. Two solutions:
// 1) consider differently void and non void return type, store only in non 
//    void case
// 2) avoid writing code after the return statement, by instantiating a dummy
//    object whose destructor will perform the operations we want to perform 
//    after the return.

void print_time_diff(const std::string& label, 
    std::chrono::high_resolution_clock::time_point start,
    std::chrono::high_resolution_clock::time_point end)
{
    using namespace std::chrono;
    std::cout << label << " "
        << duration_cast<nanoseconds>(end - start).count()
        << " nanoseconds\n";
}

template<typename Callable, typename... Args>
decltype(auto) exec_time_decorator1(const std::string& label,
    Callable&& c, Args&&... args)
{
    using namespace std::chrono;
    auto start = high_resolution_clock::now();
    decltype(start) end;

    if constexpr (std::is_same_v<void,
                                 std::invoke_result_t<Callable, Args...>>) {
        // return type is void, cannot instantiate result
        std::invoke(std::forward<Callable>(c), std::forward<Args>(args)...);
        end = high_resolution_clock::now();
        print_time_diff(label, start, end);
        return;
    }
    else {
        // return type is not void, can instantiate it
        decltype(auto) ret{ std::invoke(std::forward<Callable>(c),
            std::forward<Args>(args)...) };
        end = high_resolution_clock::now();
        print_time_diff(label, start, end);
        return ret;
    }
}

template<typename Callable, typename... Args>
decltype(auto) exec_time_decorator2(const std::string& label, 
    Callable&& c, Args&&... args)
{
    using namespace std::chrono;
    auto s = high_resolution_clock::now();
    // Put a struct to make the destructor execute after return
    struct execute_after_return {
        const high_resolution_clock::time_point& start;
        const std::string& label;
        ~execute_after_return()
        {
            auto end = high_resolution_clock::now();
            print_time_diff(label, start, end);
        }
    } e{ s, label};
    return std::invoke(std::forward<Callable>(c), std::forward<Args>(args)...);
}

int factorial(int n)
{ 
    if (n <= 1) return n >= 0; // note: oveflow results in 0
    return n * factorial(n - 1);
}

void waste_some_time()
{
    factorial(10);
}

void use_callable_decoration()
{
    auto res = exec_time_decorator2("factorial(10)", factorial, 10);
    std::cout << "factorial(10) result: " << res << "\n";
    exec_time_decorator2("waste_some_time()", 
        waste_some_time);
    auto res2 = exec_time_decorator1("factorial(10)", factorial, 10);
    std::cout << "factorial(10) result: " << res2 << "\n";
    exec_time_decorator1("waste_some_time()",
        waste_some_time);
    std::cout << "\n";
}

#endif // !CALLABLES_DECORATION_H
