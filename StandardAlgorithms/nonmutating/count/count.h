
#ifndef COUNT_H_INCLUDED
#define COUNT_H_INCLUDED
#include<features.h>
__BEGIN_DECLS
#include "Count.acsl"

/*@
  requires valid: \valid_read(a + (0..n-1));
  assigns         \nothing;
  ensures bound:  0 <= \result <= n;
  ensures count:  \result == Count(a, n, v);
*/
size_type
count(const value_type* a, size_type n, value_type v);
__END_DECLS

#endif /*  COUNT_H_INCLUDED */

