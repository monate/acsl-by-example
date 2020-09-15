
#ifndef ROTATE_COPY_H_INCLUDED
#define ROTATE_COPY_H_INCLUDED
#include<features.h>
__BEGIN_DECLS
#include "EqualRanges.acsl"
#include "Unchanged.acsl"

/*@
  requires bound:      0 <= m <= n;
  requires valid:      \valid_read(a + (0..n-1));
  requires valid:      \valid(b + (0..n-1));
  requires sep:        \separated(a + (0..n-1), b + (0..n-1));
  assigns              b[0..(n-1)];
  ensures left:        EqualRanges{Old,Here}(a, 0, m,   b, n-m);
  ensures right:       EqualRanges{Old,Here}(a, m, n-m, b, 0);
  ensures unchanged:   Unchanged{Old,Here}(a, n);
*/
void
rotate_copy(const value_type* a, size_type m, size_type n, value_type* b);
__END_DECLS

#endif /* ROTATE_COPY_H_INCLUDED */

