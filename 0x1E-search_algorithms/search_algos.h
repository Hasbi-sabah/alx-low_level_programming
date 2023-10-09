#ifndef SEARCH_ALGOS
#define SEARCH_ALGOS

#include <stdio.h>
#include <stdlib.h>

int linear_search(int *array, size_t size, int value);

int binary_search(int *array, size_t size, int value);
int binary_helper(int *array, int min, int max, int value);

#endif
