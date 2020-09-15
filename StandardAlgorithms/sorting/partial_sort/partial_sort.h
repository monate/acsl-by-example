
#ifndef PARTIAL_SORT_H_INCLUDED
#define PARTIAL_SORT_H_INCLUDED
#include<features.h>
__BEGIN_DECLS
#include "Increasing.acsl"
#include "Partition.acsl"
#include "MultisetUnchanged.acsl"

/*@
  requires valid:        \valid(a + (0..n-1));
  requires split:        0 <= m <= n;
  assigns                a[0..n-1];
  ensures reorder:       MultisetUnchanged{Old,Here}(a, n);
  ensures partition:     Partition(a, m, n);
  ensures increasing:    Increasing(a, m);
*/
void
partial_sort(value_type* a, size_type m, size_type n);
__END_DECLS

#endif /* PARTIAL_SORT_H_INCLUDED */

