#include "accumulation.h"
#include "removing_qualifiers.h"
#include "decay.h"
#include "predicate_traits.h"
#include "result_type_traits.h"
#include "sfinae_overload.h"
#include "sfinae_partial_spec.h"
#include "sfinae_friendly.h"
#include "is_conv_to_example.h"
#include "detect_member.h"

int main() {
    use_accumulate();
    use_remove_qualifiers();
    use_decay();
    use_predicate_traits();
    use_result_traits();
    use_sfinae_overload();
    use_sfinae_partial_spec();
    use_is_convertible();
    use_detect_member();
}