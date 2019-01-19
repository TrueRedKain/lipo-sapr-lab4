#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "yla_vm.h"
#include "yla_cop.h"
#include "yla_type.h"
#include "yla_test.h"
#include "yla_test_gencode.c"
#include "yla_compliance.h"
#include "yla_diapason.h"

int char_to_int(char letter);

int main(int argc, char argv[])
{
	yla_int_type stack_size = 30;
	yla_int_type vartable_size = 100;
	yla_int_type prg_size = 2048;
	yla_cop_type prg[HEADER_SIZE + prg_size];
	yla_cop_type *prog_ptr = prg;
	
	yla_int_type prog_counter = 0;
	yla_int_type *prog_counter_ptr = prog_counter;
	
	compliance_table link_table;
	compliance_table_init(&link_table, 40);
	
	yla_int_type global_var[2];
	
	global_var[0] = 0x000a;		
	global_var[1] = 0x000b;	
	
	put_header(&prog_ptr, stack_size, vartable_size, prg_size);
	
	yla_int_type i;
	
	/*
		[16,2...134] 
		- 5 ?
		- 18 ?
		- 130 ?
	*/
	put_commd(&prog_ptr, CPUSH);				prog_counter++;
	put_value(&prog_ptr, 0x0010);				prog_counter += 2;
	put_commd(&prog_ptr, CPUSH);				prog_counter++;
	put_value(&prog_ptr, 0x0002);				prog_counter += 2;
	put_commd(&prog_ptr, CPUSH);				prog_counter++;
	put_value(&prog_ptr, 0x0086);				prog_counter += 2;
	
	/*
		5 ?
	*/
	put_commd(&prog_ptr, CPUSH);				prog_counter++;
	put_value(&prog_ptr, 0x0005);				prog_counter += 2;
	put_commd(&prog_ptr, CALO);					prog_counter++;
	put_value(&prog_ptr, 0x0040);				prog_counter += 2;
	put_commd(&prog_ptr, COUT);					prog_counter++;
	put_value(&prog_ptr, 0x0001);				prog_counter += 2;
	put_commd(&prog_ptr, CSTK);					prog_counter++;
	put_value(&prog_ptr, 0x0001);				prog_counter += 2;
	/*
		18 ?
	*/
	put_commd(&prog_ptr, CPUSH);				prog_counter++;
	put_value(&prog_ptr, 0x0012);				prog_counter += 2;
	put_commd(&prog_ptr, CALO);					prog_counter++;
	put_value(&prog_ptr, 0x0040);				prog_counter += 2;
	put_commd(&prog_ptr, COUT);					prog_counter++;
	put_value(&prog_ptr, 0x0001);				prog_counter += 2;
	put_commd(&prog_ptr, CSTK);					prog_counter++;
	put_value(&prog_ptr, 0x0001);				prog_counter += 2;
	/*
		130 ?
	*/
	put_commd(&prog_ptr, CPUSH);				prog_counter++;
	put_value(&prog_ptr, 0x0082);				prog_counter += 2;
	put_commd(&prog_ptr, CALO);					prog_counter++;
	put_value(&prog_ptr, 0x0040);				prog_counter += 2;
	put_commd(&prog_ptr, COUT);					prog_counter++;
	put_value(&prog_ptr, 0x0001);				prog_counter += 2;
	put_commd(&prog_ptr, CSTK);					prog_counter++;
	put_value(&prog_ptr, 0x0001);				prog_counter += 2;
	
	put_commd(&prog_ptr, CHALT);				prog_counter++;
	
	put_number_in_diapason(&prog_ptr, 0x0040, &link_table, &prog_counter, global_var);
	
	yla_vm vm;
	
	yla_cop_type *prog_linker_ptr = prg;
	int link_state = link_program(prog_linker_ptr, prog_counter, &link_table);
	
	yla_vm_init(&vm, &prg, (prg_size + HEADER_SIZE));
	
	if (link_state == 1) {
		yla_vm_run(&vm);
	} else if (link_state == -8) {
		vm.last_error = YLA_VM_LINKER_ERROR_TABLE_EMPTY;
	} else if (link_state == -9) {
		vm.last_error = YLA_VM_LINKER_ERROR_ADDRESS_NOT_FOUND;
	}
	
	yla_vm_done(&vm);
	
	return 0;
}