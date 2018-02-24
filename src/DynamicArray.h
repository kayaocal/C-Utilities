/*
 * Author: Enes Kaya ÖCAL
 * Purpose: Dynamic array operations
 * Date : 24.02.2018
 * Language:  C
 */

#ifndef DYNAMIC_ARRAY_H_
#define DYNAMIC_ARRAY_H_

#define DYNAMIC_ARRAY_LOG

typedef struct IntegerArray
{
	int* arr;
	int size;
	
}IntegerArray;

typedef struct FloatArray
{
	float* arr;
	int size;
	
}FloatArray;

typedef struct CharArray
{
	char* arr;
	int size;
	
}CharArray;

typedef struct VoidArray
{
	void* arr;
	int size;
	int enement_size;
	
}VoidArray;

IntegerArray* create_int_array(int size);

#endif /* DYNAMIC_ARRAY_H_ */