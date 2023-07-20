#include "..\inc\pch.h"
#include "..\inc\quick_sort.h"

// [begin mid - 1] [mid] [mid + 1 end]
size_t _partition_by_index(int *aNums, size_t begin, size_t end)
{
	int mid = aNums[begin];
	while (true)
	{
		if (aNums[])
	}
	return true;
}

void _quick_sort_by_index(int *aNums, size_t begin, size_t end)
{
	if (end <= begin)
	{
		return ;
	}

	size_t mid = _partition_by_index(aNums, begin, end);
	_quick_sort_by_index(aNums, begin, mid - 1);
	_quick_sort_by_index(aNums, mid + 1, end);
}

bool quick_sort(int *aNums, const size_t length)
{
	
	return true;
}