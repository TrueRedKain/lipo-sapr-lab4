#include <stdlib.h>
#include <stdio.h>
#include "yla_stack.h"

static void dprint();

void yla_stack_init(yla_stack* stack, size_t size)
{
    stack->size = size;
    stack->count = 0;
    stack->ptr = calloc(stack->size, sizeof(int));
}

void yla_stack_done(yla_stack* stack)
{
    stack->size = 0;
    stack->count = 0;
    free(stack->ptr);
}

int yla_stack_push(yla_stack* stack, yla_int_type value)
{
    if (stack->count >= stack->size) {
        return 0;
    }
    stack->ptr[stack->count++] = value;
    return 1;
}

int yla_stack_pull(yla_stack* stack, yla_int_type *result)
{
    if (stack->count == 0) {
        return 0;
    }
    *result = stack->ptr[--stack->count];
    return 1;
}

int yla_stack_set_deep(yla_stack* stack, size_t index, yla_int_type value)
{
    if (stack->count == 0) {
        return -10;
    }
    if (index >= stack->count) {
        return -20;
    }
    stack->ptr[stack->count-index-1] = value;
    return 1;
}

int yla_stack_get_deep(yla_stack* stack, size_t index, yla_int_type *result)
{
    if (stack->count == 0) {
        return -10;
    }
    if (index >= stack->count) {
        return -20;
    }
    *result = stack->ptr[stack->count-index-1];
    return 1;
}

int yla_stack_top(yla_stack* stack, yla_int_type *result)
{
    if (stack->count == 0) {
        return 0;
    }
    *result = stack->ptr[stack->count-1];
    return 1;
}

int yla_stack_tail_delete(yla_stack* stack, yla_int_type tail_size)
{
	if (stack->count < tail_size) {
		return 0;
	}
	stack->count -= tail_size;
	return 1;
}

int yla_stack_is_empty(yla_stack* stack)
{
    return stack->count == 0;
}

int yla_stack_is_full(yla_stack* stack)
{
    return stack->count >= stack->size;
}

static void dprint(yla_stack* stack)
{
    int i;
    printf("stack:{size: %zu, count: %zu values: ", stack->size, stack->count);
    for (i=0; i < stack->count; ++i) {
        printf("%d ", stack->ptr[i]);
    }
    printf("}\n");
}
