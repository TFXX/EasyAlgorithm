#include "..\inc\pch.h"
#include "..\inc\merge_sort.h"

int merge_by_index(int *pArray, int *pTempArray, const size_t begin, const size_t middle, const size_t end)
{
	if (NULL == pArray || NULL == pTempArray)
	{
		return 1;
	}

	size_t rangeSize = (end - begin + 1) * sizeof(int); 

	

	memcpy_s(pTempArray + begin, rangeSize, pArray + begin, rangeSize);

	// pArray[begin...middle] pArray[middle + 1...end]
	size_t i = begin, j = middle + 1;
	for (size_t k = begin; k < end; k++)
	{
		if (i > middle)
		{
			// 左边的序列已经排完
			pArray[k] = pTempArray[j++];
		}
		else if (j > end)
		{
			// 右边的序列已经排完
			pArray[k] = pTempArray[i++];
		}
		else if (pTempArray[i] < pTempArray[j])
		{
			// 左边元素小于右边元素
			pArray[k] = pTempArray[i++];
		}
		else
		{
			// 左边元素大于等于右边元素
			pArray[k] = pTempArray[j++];
		}

	}

	return 0;
}

int merge_sort_by_index(int *pArray, int *pTempArray, size_t begin, size_t end)
{
	if (NULL == pArray || NULL == pTempArray)
	{
		return 1;
	}

	if (end <= begin)
	{
		// 边界条件，子数组不可再分
		return 0;
	}

	size_t middle = begin + (end - begin) / 2;
	merge_sort_by_index(pArray, pTempArray, begin, middle);
	merge_sort_by_index(pArray, pTempArray, middle, end);
	
	if (pArray[middle + 1] < pArray[middle])
	{
		// pArray[begin...end]不是一个有序数组
		merge_by_index(pArray, pTempArray, begin, middle, end);
	}
	
	return 0;
}

int merge_sort(int *pArray, const size_t num)
{
	if (NULL == pArray)
	{
		return 1;
	}

	int *pTempArray = calloc(num, sizeof(int));
	if (NULL == pTempArray)
	{
		return 2;
	}
	merge_sort_by_index(pArray, pTempArray, 0, num - 1);
	return 0;
}

int mergeBU_sort_by_index(int *pArray, int *pTempArray, size_t begin, size_t end)
{
	if (NULL == pArray || NULL == pTempArray)
	{
		return 1;
	}

	for (size_t i = 1; i <= end; i *= 2)
	{
		for (size_t j = 0; j <= end; j += 2 * i)
		{
			merge_by_index(pArray, pTempArray, j, j += i - 1, j += 2 * i - 1);
		}
	}

	return 0;
}

/*
int mergeBU_sort(int *pArray, const size_t num)
{
	if (NULL == pArray)
	{
		return 1;
	}

	int *pTempArray = calloc(num, sizeof(int));
	if (NULL == pTempArray)
	{
		return 2;
	}
	mergeBU_sort_by_index(pArray, pTempArray, 0, num - 1);
	return 0;
}
*/