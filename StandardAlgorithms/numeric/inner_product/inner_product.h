
#ifndef INNER_PRODUCT_H_INCLUDED
#define INNER_PRODUCT_H_INCLUDED

#include "InnerProduct.h"
#include "InnerProductBounds.h"
#include "Unchanged.h"

/*@
  requires valid_a: \valid_read(a + (0..n-1));
  requires valid_b: \valid_read(b + (0..n-1));
  requires bounds:  ProductBounds(a, b, n);
  requires bounds:  InnerProductBounds(a, b, n, init);

  assigns \nothing;

  ensures result:    \result == InnerProduct(a, b, n, init);
  ensures unchanged: Unchanged{Here,Pre}(a, n);
  ensures unchanged: Unchanged{Here,Pre}(b, n);
*/
value_type
inner_product(const value_type* a, const value_type* b, size_type n,
              value_type init);

#endif /* INNER_PRODUCT_H_INCLUDED */
