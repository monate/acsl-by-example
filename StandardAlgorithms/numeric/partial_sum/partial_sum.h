
#ifndef PARTIAL_SUM_H_INCLUDED
#define PARTIAL_SUM_H_INCLUDED
#include<features.h>
__BEGIN_DECLS
#include "PartialSum.acsl"

/*@
  requires valid:     \valid_read(a + (0..n-1));
  requires valid:     \valid(b + (0..n-1));
  requires sep:       \separated(a + (0..n-1), b + (0..n-1));
  requires bounds:    AccumulateDefaultBounds(a, n);
  assigns             b[0..n-1];
  ensures result:     \result == n;
  ensures partialsum: PartialSum(a, n, b);
  ensures unchanged:  Unchanged{Old,Here}(a, n);
*/
size_type
partial_sum(const value_type* a, size_type n, value_type* b);
__END_DECLS

#endif /* PARTIAL_SUM_H_INCLUDED */

