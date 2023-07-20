#include "..\inc\pch.h"

#include "..\inc\select_sort.h"

int select_sort(int *pArray, size_t num)
{
	if (NULL == pArray)
	{
		return 1;
	}

	for (size_t i = 0; i < num; i++)
	{
		size_t minIndex = i;
		for (size_t j = i + 1; j < num; j++)
		{
			if(pArray[minIndex] > pArray[j])
			minIndex = j;
		}
		
		swap(pArray + i, pArray + minIndex);
	}
	return 0;
}