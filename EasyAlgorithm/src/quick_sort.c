#include "..\inc\pch.h"
#include "..\inc\quick_sort.h"

size_t _partition_by_index(int *a, const size_t zBegin, const size_t zLast)
{
	size_t i = zBegin, j = zLast + 1;
	
	const int midValue = a[zBegin];
	
	while (true)
	{
		while (a[++i] <= midValue)
		{
			if (i == zLast)
			{
				break;
			}
		}

		while (midValue <= a[--j])
		{
			if (j == zLast)
			{
				break;
			}
		}

		if (j <= i)
		{
			break;
		}

		swap(&a[i], &a[j]);
	}

	swap(&a[zBegin], &a[j]);
	
	return j;
}

void _quick_sort_by_index(int *aNums, size_t zBegin, size_t zLast)
{
	if (zLast <= zBegin)
	{
		return ;
	}

	// [begin mid - 1] [mid] [mid + 1 last]
	size_t mid = _partition_by_index(aNums, zBegin, zLast);
	_quick_sort_by_index(aNums, zBegin, mid - 1);
	_quick_sort_by_index(aNums, mid + 1, zLast);
}

void quick_sort(int *aNums, const size_t length)
{
	assert( aNums != NULL );
	_quick_sort_by_index(aNums, 0, length - 1);
}

void _partition_3way_by_index(int *a, const size_t zBegin, const size_t zLast, size_t *pI, size_t *pJ)
{
	assert( pI != NULL && pJ != NULL);

	assert( *pI == zBegin && *pJ == zLast);
	
	size_t i = zBegin, j = zLast + 1;
	size_t p = i + 1, q = j - 1;

	const int midValue = a[zBegin];
	
	while (true)
	{
		while (a[++i] <= midValue)
		{
			if (midValue == a[i])
			{
				swap(&a[p++], &a[i]);
			}
			if (i == q)
			{
				break;
			}
		}

		while (midValue <= a[--j])
		{
			if (midValue == a[j])
			{
				swap(&a[q--], &a[j]);
			}

			if (i == p)
			{
				break;
			}
		}

		if (j <= i)
		{
			break;
		}
	}


	for (size_t k = p; k <= j; k++)
	{
		swap(&a[k], &a[(*pI)--]);
	}

	for (size_t k = q; j < k; k--)
	{
		swap(&a[k], &a[(*pJ)++]);
	}
}

void _quick_sort_3way_by_index(int *aNums, const size_t zBegin, const size_t zLast)
{
	if (zLast <= zBegin)
	{
		return;
	}

	size_t i = zBegin;
	size_t j = zLast;
	_partition_3way_by_index(aNums, zBegin, zLast, &i, &j);
	
	// [zBegin..i-1] [i...j] [j+1..zLast]
	
	_quick_sort_3way_by_index(aNums, zBegin, i - 1);
	_quick_sort_3way_by_index(aNums, j + 1, zLast);
}

void quick_sort_3way(int *aNums, const size_t length)
{
	assert( aNums != NULL );
	_quick_sort_3way_by_index(aNums, 0, length - 1);
}