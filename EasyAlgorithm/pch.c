#include "pch.h"

bool swap(int *a, int *b)
{
	if (a == NULL || b == NULL)
	{
		return false;
	}
	int temp = *a;
	*a = *b;
	*b = temp;
	return true;
}