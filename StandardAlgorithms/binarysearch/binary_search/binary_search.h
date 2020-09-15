
#ifndef BINARY_SEARCH_H_INCLUDED
#define BINARY_SEARCH_H_INCLUDED
#include<features.h>
__BEGIN_DECLS

#include "Increasing.acsl"

/*@
  requires valid:      \valid_read(a + (0..n-1));
  requires increasing: Increasing(a, n);
  assigns              \nothing;
  ensures  result:     \result <==> \exists integer i; 0 <= i < n && a[i] == val;
*/
bool
binary_search(const value_type* a, size_type n, value_type val);
__END_DECLS
#endif /* BINARY_SEARCH_H_INCLUDED */

