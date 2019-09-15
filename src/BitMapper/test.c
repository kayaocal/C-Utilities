#include<stdio.h>

#include "bit_mapper.c"


int main()
{
	printf("\n BIT MAPPER STARTED");
	bm_ready_write();
	bm_set_int(1082, 12);
	bm_set_int(2, 2);
	bm_set_int(1111, 12);
	bm_set_int(16, 8);
	bm_draw_map();

	bm_ready_read();
	int value = bm_get_int(12);
	printf("\n\n VALUE : %d", value);
	value = bm_get_int(2);
	printf("\n\n VALUE : %d", value);
	value = bm_get_int(12);
	printf("\n\n VALUE : %d", value);
	value = bm_get_int(8);
	printf("\n\n VALUE : %d", value);
	getchar( );
	return 0;
}