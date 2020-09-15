
#ifndef MAX_ELEMENT_H_INCLUDED
#define MAX_ELEMENT_H_INCLUDED
#include<features.h>
__BEGIN_DECLS
#include "typedefs.h"

/*@
  requires valid:   \valid_read(a + (0..n-1));
  assigns           \nothing;
  ensures  result:  0 <= \result <= n;

  behavior empty:
    assumes          n == 0;
    assigns          \nothing;
    ensures result:  \result == 0;

  behavior not_empty:
    assumes          0 < n;
    assigns          \nothing;
    ensures result:  0 <= \result < n;
    ensures upper:   \forall integer i; 0 <= i < n       ==> a[i] <= a[\result];
    ensures first:   \forall integer i; 0 <= i < \result ==> a[i] <  a[\result];

  complete behaviors;
  disjoint behaviors;
*/
size_type
max_element(const value_type* a, size_type n);
__END_DECLS

#endif /* MAX_ELEMENT_H_INCLUDED */

