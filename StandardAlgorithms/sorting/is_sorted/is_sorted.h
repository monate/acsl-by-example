
#ifndef IS_SORTED_H_INCLUDED
#define IS_SORTED_H_INCLUDED
#include<features.h>
__BEGIN_DECLS
#include "Increasing.acsl"

/*@
  requires valid: \valid_read(a + (0..n-1));
  assigns         \nothing;
  ensures result: \result <==> Increasing(a, n);
*/
bool
is_sorted(const value_type* a, size_type n);
__END_DECLS

#endif /* IS_SORTED_H_INCLUDED */

