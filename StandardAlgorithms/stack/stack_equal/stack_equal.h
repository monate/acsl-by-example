
#ifndef STACK_EQUAL_H_INCLUDED
#define STACK_EQUAL_H_INCLUDED
#include<features.h>
__BEGIN_DECLS
#include "Stack.acsl"

/*@
    requires valid:     \valid_read(s) && StackInvariant(s);
    requires valid:     \valid_read(t) && StackInvariant(t);
    assigns             \nothing;
    ensures  equal:     \result == 1  <==>  StackEqual{Here,Here}(s, t);
    ensures  not_equal: \result == 0  <==> !StackEqual{Here,Here}(s, t);
*/
bool
stack_equal(const Stack* s, const Stack* t);
__END_DECLS

#endif /* STACK_EQUAL_H_INCLUDED */

