#include "..\inc\pch.h"

bool swap(int *a, int *b)
{
	assert(a != NULL && b != NULL);

	int temp = *a;
	*a = *b;
	*b = temp;
	return true;
}

bool less(const int a, const int b)
{
	return a < b;
}