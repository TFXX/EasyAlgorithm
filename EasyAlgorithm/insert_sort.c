#include "pch.h"
#include "insert_sort.h"

int insert_sort_with_delta(int *pArray, size_t num, size_t delta)
{
	if (NULL == pArray)
	{
		return 1;
	}

	for (size_t i = delta; i < num; i++)
	{
		for (size_t j = i; j >= delta && pArray[j] < pArray[j - delta]; j -= delta)
		{
			swap(pArray + j, pArray + j - 1);
		}
	}

	return 0;
}

int insert_sort(int *pArray, size_t num)
{
	return insert_sort_with_delta(pArray, num, 1);
}