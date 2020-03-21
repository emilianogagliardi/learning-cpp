#include "template_fun_basics.h"


int main()
{
    auto a = max_1templateArg(3, 2);
    // on template argument deduction only decay conversions are applyied
    // no automatic type conversions
    // auto b = max_1templateArg(1.2, 4); // this does not compile
    // double b = max_1templateArg(1.2, 4); // this does not compile
    auto b = max_1templateArg<double>(2, 3.1); // you have to specify template argument
    // deduce return type int
    auto c = max_2templateArg_retFirst(4, 5.2);
    // the return template type can not be deduced if there is not other guess (eg equal to a param)
    // auto d = max_3templateArg(1, 2); // do not compile
    // int d = max_3templateArg(1, 2); // do not compile
    auto d = max_3templateArg<double>(1, 2); // need to specify return type template
    // return type is common type
    auto e = max_2templateArgs_auto(1, 2.3);
    auto f = max_2templateArgs_trayling(1, 2.1);
    auto g = max_2tempalteArgs_common(2.1, 3);
    auto h = max_3templateArgs_retDefault(1, 4.1);
    auto i = max_3templateArgs_retDefault2(1, 4.1);
}