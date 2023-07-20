#include "..\inc\pch.h"
#include "..\inc\shell_sort.h"

int shell_sort(int *pArray, size_t num)
{
	if (NULL == pArray)
	{
		return false;
	}


	for (size_t h = num / 2; h >= 1; h /= 2)
	{
		// ��������ֽ�ɵ�h��������
		insert_sort_with_delta(pArray, num, h);
	}
	return true;
}