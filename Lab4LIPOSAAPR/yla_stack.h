#ifndef _yla_stack_h
#define _yla_stack_h

#include <stddef.h>

#include "yla_type.h"

typedef struct {
    int *ptr;
    size_t size;
    size_t count;
} yla_stack;

void yla_stack_init(yla_stack* stack, size_t size);
void yla_stack_done(yla_stack* stack);

int yla_stack_push(yla_stack* stack, yla_int_type value);
int yla_stack_pull(yla_stack* stack, yla_int_type *result);

int yla_stack_set_deep(yla_stack* stack, size_t index, yla_int_type value);
int yla_stack_get_deep(yla_stack* stack, size_t index, yla_int_type *result);

int yla_stack_top(yla_stack* stack, yla_int_type *result);

int yla_stack_tail_delete(yla_stack* stack, yla_int_type tail_size);

int yla_stack_is_empty(yla_stack* stack);
int yla_stack_is_full(yla_stack* stack);

#endif
