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
	do
	{
		if(bm_bit_cursor+bit_count < BYTE)
		{
			bm_data[bm_byte_cursor] |= (data&((1<<bit_count)-1)) << bm_bit_cursor;
			bm_bit_cursor += bit_count;
			bit_count = 0;
		}
		else
		{
			int first_part = BYTE - bm_bit_cursor;
			bit_count -= first_part;
			bm_data[bm_byte_cursor] |= (data&((1<<first_part)-1)) << bm_bit_cursor;
			data = data >> first_part;
			bm_byte_cursor++;
			bm_bit_cursor = 0;
		}

	}while(bit_count > 0);

	return bm_byte_cursor;
}

int bm_set_int_optional(int data, int bit_count, bool is_active)
{
	if(is_active == false)
	{
		return bm_set_int(0, 1);
	}
	
	bm_set_int(1, 1);
	return bm_set_int(data, bit_count);
}

int bm_get_int_optional(int bit_count, int current_value)
{
	int is_active = bm_get_int(1);
	if(is_active)
	{
		return bm_get_int(bit_count);
	}

	return current_value;
}

int bm_get_int(int bit_count)
{
	int value = 0;
	int byte_to_read = bm_byte_cursor;

	int l_bit_count = bm_bit_cursor + bit_count;
	for(char i = bm_bit_cursor; i < l_bit_count; i++)
	{	
		int divider = i / BYTE;
		if(byte_to_read < bm_byte_cursor + divider)
		{
			byte_to_read ++;
		}

		int bit = (bm_data[byte_to_read] >> (i%BYTE)) & 1;
		value |= (bit << ( i - bm_bit_cursor));
	}
	bm_byte_cursor += l_bit_count / BYTE;
	bm_bit_cursor = l_bit_count % BYTE;

	return value;
}

void bm_draw_map()
{
	printf("\n----------DRAW_MAP--------\n");
	for(int i = 0; i < bm_byte_cursor+1; i++)
	{
		printf("\n");	
		for(int j = BYTE - 1; j >= 0; j--)
		{
			printf("%d - ", ((bm_data[i] >> j )&1));
		}
	}
	printf("\n------------------------------\n");
}