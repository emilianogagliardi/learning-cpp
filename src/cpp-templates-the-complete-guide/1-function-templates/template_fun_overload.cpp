#include "template_fun_overload.h"

int main()
{
    // non template is preferred than template
    auto a = max_overload(1, 3);        // print #1
    auto b = max_overload(1, 3.1);      // print #1
    // if template give better match call template
    auto c = max_overload(2.1, 2.2);    // print #2
    // force call to a template function 
    auto d = max_overload<>(1, 3);      // print #2
    // automatic type conversion is not considered to deduce
    // template parameters. 
    auto e = max_overload(1.2, 'a');    // print #1
}