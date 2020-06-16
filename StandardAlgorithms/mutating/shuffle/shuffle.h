
#ifndef SHUFFLE_H_INCLUDED
#define SHUFFLE_H_INCLUDED
#include<features.h>
__BEGIN_DECLS
#include "MultisetUnchanged.acsl"

/*@
  requires valid:   \valid(a + (0..n-1));
  requires valid:   \valid(seed + (0..2));
  requires sep:     \separated(a + (0..n-1), seed + (0..2));
  assigns           a[0..n-1];
  assigns           seed[0..2];
  ensures  reorder: MultisetUnchanged{Old,Here}(a,n);
*/
void
shuffle(value_type* a, size_type n, unsigned short* seed);
__END_DECLS

#endif /* SHUFFLE_H_INCLUDED */

