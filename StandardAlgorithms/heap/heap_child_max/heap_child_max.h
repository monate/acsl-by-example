
#ifndef HEAP_CHILD_MAX_H_INCLUDED
#define HEAP_CHILD_MAX_H_INCLUDED
#include<features.h>
__BEGIN_DECLS
#include "Heap.acsl"

/*@
   requires bound: 2 <= n;
   requires bound: 0 <= parent < n - 1;
   requires valid: \valid_read(a + (0..n-1));
   requires heap:  Heap(a, n);
   assigns         \nothing;
   ensures heap:   Heap(a, n);
   ensures max:    HeapChildMax(a, n, parent, \result);
   ensures less:   parent < \result;
   ensures less:   \result < n - 1  ==>  parent == HeapParent(\result);
*/
static inline size_type
heap_child_max(const value_type* a, size_type n, size_type parent)
{
  if (parent < (SIZE_TYPE_MAX - 1u) / 2u) {
    const size_type right = 2u * parent + 2u;
    const size_type left  = right - 1u;

    if (right < n - 1u) {
      // case of two children: select child with maximum value
      return a[left] >= a[right] ? left : right;
    }
    else {
      // at most one child that comes before n-1 can exist
      return left;
    }
  }
  else {
    return n;
  }
}
__END_DECLS

#endif /* HEAP_CHILD_MAX_H_INCLUDED */

