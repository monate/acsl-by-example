
#ifndef REVERSE_H_INCLUDED
#define REVERSE_H_INCLUDED
#include<features.h>
__BEGIN_DECLS
#include "Reverse.acsl"

/*@
  requires valid:  \valid(a + (0..n-1));
  assigns          a[0..n-1];
  ensures reverse: Reverse{Old,Here}(a, n);
*/
void
reverse(value_type* a, size_type n);
__END_DECLS

#endif  /* REVERSE_H_INCLUDED */

