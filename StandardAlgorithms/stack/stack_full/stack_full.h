
#ifndef STACK_FULL_H_INCLUDED
#define STACK_FULL_H_INCLUDED
#include<features.h>
__BEGIN_DECLS
#include "Stack.acsl"

/*@
    requires valid:    \valid(s) && StackInvariant(s);
    assigns            \nothing;
    ensures  full:     \result == 1  <==>  StackFull(s);
    ensures  not_full: \result == 0  <==> !StackFull(s);
*/
bool
stack_full(const Stack* s);
__END_DECLS

#endif /* STACK_FULL_H_INCLUDED */

