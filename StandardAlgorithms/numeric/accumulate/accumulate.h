
#ifndef ACCUMULATE_H_INCLUDED
#define ACCUMULATE_H_INCLUDED
#include<features.h>
__BEGIN_DECLS
#include "Accumulate.acsl"

/*@
  requires valid:  \valid_read(a + (0..n-1));
  requires bounds: AccumulateBounds(a, n, init);
  assigns          \nothing;
  ensures  result: \result == Accumulate(a, n, init);
*/
value_type
accumulate(const value_type* a, size_type n, value_type init);
__END_DECLS

#endif /* ACCUMULATE_H_INCLUDED */

