#ifndef TWO_TEMPL_PARAMS_H
#define TWO_TEMPL_PARAMS_H

#include <iostream>

// Parial template specialization multiple template params

template<typename T1, typename T2>
struct TwoTemplateParams {
    TwoTemplateParams() { std::cout << "#1\n"; }
};

template<typename T>
struct TwoTemplateParams<T, T> {
    TwoTemplateParams() { std::cout << "#2\n"; }
};

template<typename T>
struct TwoTemplateParams<T, int> {
    TwoTemplateParams() { std::cout << "#3\n"; }
};

template<typename T1, typename T2>
struct TwoTemplateParams<T1*, T2*> {
    TwoTemplateParams() { std::cout << "#4\n"; }
};

#endif // !TWO_TEMPL_PARAMS_H
