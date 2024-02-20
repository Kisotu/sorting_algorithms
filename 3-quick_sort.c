#include "sort.h"

/**
 * swapper - swap two items in array
 * @array: The array to swap
 * @lt: index of left item
 * @rt: index of right item
 */
void swapper(int *array, size_t lt, size_t rt)
{
	int temp;

	if (array != NULL)
	{
		temp = array[lt];
		array[lt] = array[rt];
		array[rt] = temp;
	}
}

/**
 * quick_sort_partition - Sorts sub array using Lomuto's partition scheme
 * @array: The array containing with sub-array.
 * @left: left position of the sub-array.
 * @right: right position of the sub-array.
 * @size: length of the array.
 */
void quick_sort_partition(int *array, size_t left, size_t right, size_t size)
{
	size_t lt, rt;
	int pivot;

	if ((left >= right) || (array == NULL))
		return;
	pivot = array[right];
	lt = left;
	for (rt = left; rt < right; rt++)
	{
		if (array[rt] <= pivot)
		{
			if (lt != rt)
			{
				swapper(array, lt, rt);
				print_array(array, size);
			}
			lt++;
		}
	}
	if (lt != right)
	{
		swapper(array, lt, right);
		print_array(array, size);
	}
	if (lt - left > 1)
		quick_sort_partition(array, left, lt - 1, size);
	if (right - lt > 1)
		quick_sort_partition(array, lt + 1, right, size);
}

/**
 * quick_sort - sorts array using the quick sort algorithm
 * @array: array to sort.
 * @size: length of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array != NULL)
	{
		quick_sort_partition(array, 0, size - 1, size);
	}
}
