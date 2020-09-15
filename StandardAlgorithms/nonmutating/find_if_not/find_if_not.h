
#ifndef FINDIFNOT_H_INCLUDED
#define FINDIFNOT_H_INCLUDED
#include<features.h>
__BEGIN_DECLS
#include "FindNotEqual.acsl"

/*@
  requires valid:    \valid_read(a + (0..n-1));
  assigns            \nothing;
  ensures result:    0 <= \result <= n;
  ensures result:    \result == FindNotEqual(a, n, v);
*/
size_type
find_if_not(const value_type* a, size_type n, value_type v);
__END_DECLS

#endif /* FINDIFNOT_H_INCLUDED */

