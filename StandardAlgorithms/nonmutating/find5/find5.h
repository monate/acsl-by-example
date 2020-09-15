
#ifndef FIND5_H_INCLUDED
#define FIND5_H_INCLUDED
#include<features.h>
__BEGIN_DECLS
#include "Find.acsl"


/*@
  requires valid:    \valid_read(a + (0..n-1));
  assigns            \nothing;
  ensures result:    0 <= \result <= n;
  ensures result:    \result == Find(a, n, v);
*/
size_type
find5(const value_type* a, size_type n, value_type v);
__END_DECLS

#endif /* FIND5_H_INCLUDED */

