
#ifndef INSERTION_SORT_H_INCLUDED
#define INSERTION_SORT_H_INCLUDED
#include<features.h>
__BEGIN_DECLS
#include "MultisetUnchanged.acsl"
#include "Increasing.acsl"

/*@
   requires valid:       \valid(a + (0..n-1));
   assigns               a[0..n-1];
   ensures reorder:      MultisetUnchanged{Old,Here}(a, n);
   ensures increasing:   Increasing(a, n);
*/
void
insertion_sort(value_type* a, size_type n);
__END_DECLS

#endif /* INSERTION_SORT_H_INCLUDED */

