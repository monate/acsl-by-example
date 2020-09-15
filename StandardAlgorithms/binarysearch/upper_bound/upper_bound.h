
#ifndef UPPER_BOUND_H_INCLUDED
#define UPPER_BOUND_H_INCLUDED
#include<features.h>
__BEGIN_DECLS

#include "Increasing.acsl"
#include "ArrayBounds.acsl"
/*@
  requires valid:      \valid_read(a + (0..n-1));
  requires increasing: Increasing(a, n);
  assigns              \nothing;
  ensures result:      0 <= \result <= n;
  ensures left:        UpperBound(a, 0, \result, val);
  ensures right:       StrictLowerBound(a, \result, n, val);
*/
size_type
upper_bound(const value_type* a, size_type n, value_type val);
__END_DECLS

#endif /* UPPER_BOUND_H_INCLUDED */

