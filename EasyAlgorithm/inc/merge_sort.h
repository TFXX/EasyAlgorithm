#pragma once

#include "pch.h"

int merge_by_index(int *pArray, int *pTempArray, const size_t begin, const size_t middle, const size_t end);

int merge_sort_by_index(int *pArray, int *pTempArray, size_t begin, size_t end);

int merge_sort(int *pArray, const size_t num);