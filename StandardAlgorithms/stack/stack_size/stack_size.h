
#ifndef STACK_SIZE_H_INCLUDED
#define STACK_SIZE_H_INCLUDED
#include<features.h>
__BEGIN_DECLS
#include "Stack.acsl"

/*@
    requires valid: \valid(s) && StackInvariant(s);
    assigns         \nothing;
    ensures  size:  \result == StackSize(s);
*/
size_type
stack_size(const Stack* s);
__END_DECLS

#endif /* STACK_SIZE_H_INCLUDED */

