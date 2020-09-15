
#ifndef FIND2_H_INCLUDED
#define FIND2_H_INCLUDED
#include<features.h>
__BEGIN_DECLS
#include "SomeNone.acsl"
/*@
  requires valid:    \valid_read(a + (0..n-1));
  assigns            \nothing;
  ensures result:    0 <= \result <= n;

  behavior some:
    assumes          SomeEqual(a, n, v);
    assigns          \nothing;
    ensures  bound:  0 <= \result < n;
    ensures  result: a[\result] == v;
    ensures  first:  NoneEqual(a, \result, v);

  behavior none:
    assumes          NoneEqual(a, n, v);
    assigns          \nothing;
    ensures  result: \result == n;

  complete behaviors;
  disjoint behaviors;
*/
size_type
find2(const value_type* a, size_type n, value_type v);
__END_DECLS

#endif /* FIND2_H_INCLUDED */

