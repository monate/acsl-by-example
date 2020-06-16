
#ifndef REPLACE_COPY_H_INCLUDED
#define REPLACE_COPY_H_INCLUDED
#include<features.h>
__BEGIN_DECLS
#include "Replace.acsl"
#include "Unchanged.acsl"

/*@
  requires valid:   \valid(a + (0..n-1));
  assigns           a[0..n-1];
  ensures replace:  Replace{Old,Here}(a, n, v, w);
*/
void
replace(value_type* a, size_type n, value_type v, value_type w);
__END_DECLS

#endif /* REPLACE_COPY_H_INCLUDED */

