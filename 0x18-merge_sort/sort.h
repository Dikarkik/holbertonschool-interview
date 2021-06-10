#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
#include <stdio.h>

void print_array(const int *array, size_t size);
void merge_sort(int *array, size_t size);
int *merge_recursion(int *array, size_t size, int *merge);
int *merge_func(int *array_1, int *array_2, size_t size_1,
				size_t size_2, int *merge);

#endif /* SORT_H */
