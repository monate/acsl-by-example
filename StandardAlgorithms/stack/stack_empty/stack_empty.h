
#ifndef STACK_EMPTY_H_INCLUDED
#define STACK_EMPTY_H_INCLUDED
#include<features.h>
__BEGIN_DECLS
#include "Stack.acsl"

/*@
    requires valid:    \valid_read(s) && StackInvariant(s);
    assigns            \nothing;
    ensures empty:     \result == 1  <==>  StackEmpty(s);
    ensures not_empty: \result == 0  <==> !StackEmpty(s);
*/
bool
stack_empty(const Stack* s);
__END_DECLS

#endif /* STACK_EMPTY_H_INCLUDED */

