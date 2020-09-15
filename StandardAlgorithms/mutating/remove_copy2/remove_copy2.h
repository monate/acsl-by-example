
#ifndef REMOVE_COPY2_H_INCLUDED
#define REMOVE_COPY2_H_INCLUDED
#include<features.h>
__BEGIN_DECLS
#include "SomeNone.acsl"
#include "Unchanged.acsl"
#include "CountNotEqual.acsl"

/*@
  requires valid:    \valid_read(a + (0..n-1));
  requires valid:    \valid(b + (0..n-1));
  requires sep:      \separated(a + (0..n-1), b + (0..n-1));
  assigns            b[0..n-1];
  ensures size:      \result == CountNotEqual(a, n, v);
  ensures bound:     0 <= \result <= n;
  ensures discard:   NoneEqual(b, \result, v);
  ensures unchanged: Unchanged{Old,Here}(a, n);
  ensures unchanged: Unchanged{Old,Here}(b, \result, n);
*/
size_type
remove_copy2(const value_type* a, size_type n, value_type* b, value_type v);
__END_DECLS

#endif /* REMOVE_COPY2_H_INCLUDED */

