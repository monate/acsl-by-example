
#ifndef FIND_FIRST_OF_H_INCLUDED
#define FIND_FIRST_OF_H_INCLUDED
#include<features.h>
__BEGIN_DECLS
#include "HasValueOf.acsl"

/*@
  requires valid:   \valid_read(a + (0..m-1));
  requires valid:   \valid_read(b + (0..n-1));
  assigns           \nothing;
  ensures result:   0 <= \result <= m;

  behavior found:
    assumes         HasValueOf(a, m, b, n);
    assigns         \nothing;
    ensures bound:  0 <= \result < m;
    ensures result: SomeEqual(b, n, a[\result]);
    ensures first:  !HasValueOf(a, \result, b, n);

  behavior not_found:
    assumes         !HasValueOf(a, m, b, n);
    assigns         \nothing;
    ensures result: \result == m;

  complete behaviors;
  disjoint behaviors;
*/
size_type
find_first_of(const value_type* a, size_type m,
              const value_type* b, size_type n);
__END_DECLS

#endif /* FIND_FIRST_OF_H_INCLUDED */
