#include "..\inc\pch.h"

#include "..\inc\bubble_sort.h"

int bubble_sort(int *pArray, size_t num)
{
	if (NULL == pArray)
	{
		return 1;
	}

	for (size_t i = 0; i < num; i++)
	{
		for (size_t j = 1; j < num - i; j++)
		{
			if (pArray[j - 1] > pArray[j])
			{
				swap(pArray + j, pArray + j - 1);
			}
		}
	}
	return 0;
}