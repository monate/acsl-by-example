
#ifndef MERGE_H_INCLUDED
#define MERGE_H_INCLUDED
#include<features.h>
__BEGIN_DECLS
#include "IncreasingLemmas.acsl"


/*@
  requires bound:        n + m <= SIZE_TYPE_MAX;
  requires valid:        \valid_read(a + (0..n-1));
  requires valid:        \valid_read(b + (0..m-1));
  requires valid:        \valid(result + (0..n+m-1));
  requires sep:          \separated(a + (0..n-1), result + (0..n+m-1));
  requires sep:          \separated(b + (0..m-1), result + (0..n+m-1));
  requires increasing:   WeaklyIncreasing(a, n);
  requires increasing:   WeaklyIncreasing(b, m);
  assigns                result[0 .. n+m-1];
  ensures  increasing:   Increasing(result, n + m);
 */
void
merge(const value_type* a, size_type n,
      const value_type* b, size_type m,
      value_type* result);

__END_DECLS

#endif /* MERGE_H_INCLUDED */

