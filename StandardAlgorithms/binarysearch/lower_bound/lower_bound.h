
#ifndef LOWER_H_BOUND_INCLUDED
#define LOWER_H_BOUND_INCLUDED
#include<features.h>
__BEGIN_DECLS

#include "Increasing.acsl"
#include "ArrayBounds.acsl"
/*@
  requires valid:      \valid_read(a + (0..n-1));
  requires increasing: Increasing(a, n);
  assigns              \nothing;
  ensures result:      0 <= \result <= n;
  ensures left:        StrictUpperBound(a, 0, \result, val);
  ensures right:       LowerBound(a, \result, n, val);
*/
size_type
lower_bound(const value_type* a, size_type n, value_type val);
__END_DECLS

#endif /* LOWER_H_BOUND_INCLUDED */

