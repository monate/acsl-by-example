
#ifndef SEARCH_H_INCLUDED
#define SEARCH_H_INCLUDED
#include<features.h>
__BEGIN_DECLS
#include "HasSubRange.acsl"

/*@
  requires valid:   \valid_read(a + (0..n-1));
  requires valid:   \valid_read(b + (0..p-1));
  assigns           \nothing;
  ensures  result:  0 <= \result <= n;

  behavior has_match:
    assumes         HasSubRange(a, n, b, p);
    assigns         \nothing;
    ensures bound:  0 <= \result <= n-p;
    ensures result: EqualRanges{Here,Here}(a+\result, p, b);
    ensures first:  !HasSubRange(a, \result+p-1, b, p);

  behavior no_match:
    assumes         !HasSubRange(a, n, b, p);
    assigns         \nothing;
    ensures result: \result == n;

  complete behaviors;
  disjoint behaviors;
*/
size_type
search(const value_type* a, size_type n,
       const value_type* b, size_type p);
__END_DECLS

#endif /* SEARCH_H_INCLUDED */


