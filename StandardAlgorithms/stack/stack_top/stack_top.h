
#ifndef STACK_TOP_H_INCLUDED
#define STACK_TOP_H_INCLUDED
#include<features.h>
__BEGIN_DECLS
#include "Stack.acsl"

/*@
    requires valid: \valid(s) && StackInvariant(s);
    assigns         \nothing;
    ensures  top:   !StackEmpty(s) ==> \result == StackTop(s);
*/
value_type
stack_top(const Stack* s);
__END_DECLS

#endif /* STACK_TOP_H_INCLUDED */

