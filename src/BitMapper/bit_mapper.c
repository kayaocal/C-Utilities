/*
 * Author: Enes Kaya ÖCAL
 * Purpose: Easy Bit Mapping
 * Date : 15.09.2019
 * Language:  C
 */

#include "bit_mapper.h"


void bm_ready_write()
{
	bm_byte_cursor = 0;
	bm_bit_cursor = 0;
	bm_data[0] = 0;
}

void bm_ready_read()
{
	bm_byte_cursor = 0;
	bm_bit_cursor = 0;
}


int bm_write_bit(int bit, int byte_c, int bit_c)
{
	printf("\n bit_c : %d", bit_c);
	if(bit_c>=BYTE)
	{
		int divider = bit_c / BYTE;
		bit_c%=BYTE;
		if(byte_c < bm_byte_cursor + divider)
		{
			printf("\n new_line ");
			byte_c++;
			bm_data[byte_c] = 0;
		}
	}

	bm_data[byte_c] |= (bit<<bit_c);
	return byte_c;
}

int bm_set_int(int data, int bit_count)
{
	printf("\n bm_set_int ( %d, %d )", data, bit_count);
	printf("\n\t bm_byte_cursor : %d", bm_byte_cursor);
	printf("\t bm_bit_cursor : %d", bm_bit_cursor);
	int byte_to_write = bm_byte_cursor;
	for(char i = 0; i < bit_count; i++)
	{
		int bit = (data >> i) & 1;
		char bit_to_write = bm_bit_cursor + i;
		byte_to_write = bm_write_bit(bit, byte_to_write, bit_to_write);
	}
	bm_byte_cursor += (bm_bit_cursor+bit_count) / BYTE ;
	bm_bit_cursor = ((bm_bit_cursor+bit_count) % BYTE);

	return 0;
}

int bm_get_int(int bit_count)
{
	printf("\n bm_get_int ( %d )", bit_count);
	int value = 0;
	int byte_to_read = bm_byte_cursor;
	printf("\n byte_to_read %d ", byte_to_read);
	printf("\t bm_bit_cursor %d ", bm_bit_cursor);

	int l_bit_count = bm_bit_cursor + bit_count;
	for(char i = bm_bit_cursor; i < l_bit_count; i++)
	{	
		int divider = i / BYTE;
		if(byte_to_read < bm_byte_cursor + divider)
		{
			byte_to_read ++;
		}

		int bit = (bm_data[byte_to_read] >> (i%BYTE)) & 1;
		printf("\n i : %d, byte_to_read : %d, bit : %d", i,byte_to_read,bit);
		value |= (bit << ( i - bm_bit_cursor));
		printf("\t value : %d", value);
	}
	bm_byte_cursor += l_bit_count / BYTE;
	bm_bit_cursor = l_bit_count % BYTE;

	return value;
}

void bm_draw_map()
{
	printf("\n\n-------BM_DRAW_MAP-------");
	for(int i = 0; i < bm_byte_cursor+1; i++)
	{
		printf("\n");	
		for(int j = BYTE - 1; j >= 0; j--)
		{
			printf("%d - ", ((bm_data[i] >> j )&1));
		}
	}
	printf("\n------------------------");
}