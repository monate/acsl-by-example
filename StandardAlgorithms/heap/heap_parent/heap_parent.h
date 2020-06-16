
#ifndef HEAP_AUX_H_INCLUDED
#define HEAP_AUX_H_INCLUDED
#include<features.h>
__BEGIN_DECLS
#include "HeapBasics.acsl"

/*@
   requires bound:  0 < child;
   assigns          \nothing;
   ensures  parent: \result == HeapParent(child);
 */
static inline size_type
heap_parent(size_type child)
{
  return (child - 1u) / 2u;
}

__END_DECLS

#endif /* HEAP_AUX_H_INCLUDE */

