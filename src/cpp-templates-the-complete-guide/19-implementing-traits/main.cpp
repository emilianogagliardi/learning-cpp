#include "accumulation.h"
#include "removing_qualifiers.h"
#include "decay.h"
#include "predicate_traits.h"
#include "result_type_traits.h"

int main() {
    use_accumulate();
    use_remove_qualifiers();
    use_decay();
    use_predicate_traits();
    use_result_traits();
}