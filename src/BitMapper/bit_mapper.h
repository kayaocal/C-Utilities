/*
 * Author: Enes Kaya ÖCAL
 * Purpose: Easy Bit Mapping
 * Date : 15.09.2019
 * Language:  C
 */

#ifndef BIT_MAPPER
#define BIT_MAPPER

//each byte 8 bit
#define BYTE 8

#define MAX_PACKAGE_SIZE 1000
char bm_data[MAX_PACKAGE_SIZE];

int bm_byte_cursor = 0;
int bm_bit_cursor = 0;

void bm_ready_write();

void bm_ready_read();

int bm_write_bit(int bit, int byte_c, int bit_c);

int bm_set_int(int data, int bit_count);

void bm_draw_map();

int bm_set_int_optional(int data, int bit_count, bool is_active);

int bm_get_int_optional(int bit_count, int current_value);

int bm_get_int(int bit_count);

#endif //BIT_MAPPER