
#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
__BEGIN_DECLS
#include "typedefs.h"

struct Stack
{
  value_type* obj;

  size_type   capacity;

  size_type   size;
};

typedef struct Stack Stack;
__END_DECLS

#endif /* STACK_H_INCLUDED */

