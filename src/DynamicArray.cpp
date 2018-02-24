/*
 * Author: Enes Kaya ÖCAL
 * Purpose: Dynamic array operations
 * Date : 24.02.2018
 * Language:  C
 */

#include "DynamicArray.h"


void dynamic_array_log(char* str)
{
#ifdef DYNAMIC_ARRAY_LOG
	printf("\n");
	printf(str);
#endif



