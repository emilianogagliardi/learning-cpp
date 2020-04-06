#include "compile_time_prime_old_style.h"
#include "compile_time_prime.h"
#include "compile_time_choice1.h"
#include "compile_time_choice2.h"
#include "my_enable_if_sfinae.h"
#include "decltype_sfinae.h"
#include <iostream>

int main()
{
    use_is_prime_old_style();
    use_is_prime();
    use_compile_time_choice1();
    use_compile_time_choice2();
    use_my_enable_if();
    use_only_if_has_size();
}