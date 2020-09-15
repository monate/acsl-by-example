
#ifndef FILL_H_INCLUDED
#define FILL_H_INCLUDED
#include<features.h>
__BEGIN_DECLS
#include "AllSomeNot.acsl"

/*@
  requires valid:   \valid(a + (0..n-1));
  assigns           a[0..n-1];
  ensures constant: AllEqual(a, n, val);
*/
void
fill(value_type* a, size_type n, value_type val);
__END_DECLS

#endif /* FILL_H_INCLUDED */

