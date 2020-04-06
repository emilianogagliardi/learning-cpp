#include "template_fun_overload.h"
#include <string>

int main()
{
    // non template is preferred than template
    auto a = max_overload(1, 3);        // print #1
    auto b = max_overload(1, 3.1);      // print #1
    // if template can generate better match call template
    auto c = max_overload(2.1, 2.2);    // print #2
    // force call to a template function 
    auto d = max_overload<>(1, 3);      // print #2
    // automatic type conversion is not considered to deduce template 
    // parameters, thus only non-template fun participates to resolution
    auto e = max_overload(1.2, 'a');    // print #1
    
    std::cout << "\n";

    // only #3 matches, since return argument is not specified
    auto f = max_overload1(3, 1.3);             // print #3
    // #4 generates better match, no conversion from double to long int needed
    auto g = max_overload1<long int>(3.1, 2);   // print #4
    // ambiguous call, #3 and #4 match in the same way
    // auto h = max_overload1<int>(1, 3.1);

    std::cout << "\n";

    int ia = 1, ib = 2;
    int* ptr1 = &ia, * ptr2 = &ib;
    std::string sa = "ciao", sb = "a te";
    const char* ca = "ciao", * cb = "a te";
    // max between int
    auto h = max_overload3(ia, ib);     // print #5
    // max between strings, no conversions in templates arguments deduction
    auto i = max_overload3(sa, sb);     // print #5
    // max between pointers, T* is better than T
    auto j = max_overload3(ptr1, ptr2); // print #6
    // max between c-style strings, const char* is better than T*
    auto k = max_overload3(ca, cb);     // print #7
}