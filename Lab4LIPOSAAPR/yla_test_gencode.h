#ifndef yla_test_gencode_h
#define yla_test_gencode_h

#include "yla_type.h"
#include "yla_compliance.h"
#include <stddef.h>

void put_commd(yla_cop_type** prg, yla_cop_type value);

void put_value(yla_cop_type** prg, yla_int_type value);

void put_header(yla_cop_type** prg, size_t stack_size, size_t vartable_size, size_t code_size);

int link_program(yla_cop_type *prog_ptr, yla_int_type prog_counter, compliance_table *link_table);

#endif
