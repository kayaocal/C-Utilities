#include<stdio.h>

#include "bit_mapper.c"


int main()
{
	printf("\n BIT MAPPER STARTED");
	int value = 0;
	printf("\n------------------------------\n");
	bm_ready_write();
	bm_set_int_optional(1082, 12, true);
	 bm_set_int_optional(63, 8,false);
	 bm_set_int_optional(6, 3, true);
	// bm_set_int_optional(1111, 18, true);
	// bm_set_int(16, 8);
	bm_draw_map();

	bm_ready_read();
	value = bm_get_int_optional(12, -1);
	 printf("\n VALUE : %d", value);
	 value = bm_get_int_optional(8 , -1);
	 printf("\n VALUE : %d", value);
	 value = bm_get_int_optional(3 , -1);
	 printf("\n VALUE : %d", value);
	// value = bm_get_int_optional(18, -1);
	// printf("\n VALUE : %d", value);
	// value = bm_get_int(8);
	// printf("\n VALUE : %d", value);
	getchar( );
	return 0;
}