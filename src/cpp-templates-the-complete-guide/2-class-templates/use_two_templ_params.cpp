#include "two_templ_params.h"

int main() {
    TwoTemplateParams<int, float> tif;      // print #1
    TwoTemplateParams<float, float> tff;    // print #2
    TwoTemplateParams<float, int> tfi;      // print #3
    TwoTemplateParams<int*, float*> tp;     // print #4
    // Ambiguous
    // TwoTemplateParams<int, int> tii;
    // Ambiguous, can be solved with <T*, T*> partial specialization
    // TwoTemplateParams<float*, float*> tpi;
}