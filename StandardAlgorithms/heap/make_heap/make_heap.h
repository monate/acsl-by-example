
#ifndef MAKE_HEAP_H_INCLUDED
#define MAKE_HEAP_H_INCLUDED
#include<features.h>
__BEGIN_DECLS
#include "Heap.acsl"
#include "MultisetUnchanged.acsl"

/*@
   requires valid:  \valid(a + (0..n-1));
   assigns          a[0..n-1];
   ensures heap:    Heap(a, n);
   ensures reorder: MultisetUnchanged{Old,Here}(a, n);
*/
void
make_heap(value_type* a, size_type n);
__END_DECLS

#endif /* MAKE_HEAP_H_INCLUDED */

