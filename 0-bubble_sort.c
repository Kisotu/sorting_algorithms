#include "sort.h"

/**
 * bubble_sort - func that sorts array in asceding order using bubble sort
 * @array: an array of integers to sort
 * @size: size of array
 * Return; Nothing
 */
void bubble_sort(int *array, size_t size)
{
	size_t k;
	int temp, flg;

	if (!array || size < 2)
		return;

	do {
		flg = 1;
		for (k = 0; k < size - 1; k++)
		{
			if (array[k] > array[k + 1])
			{
				flg = 0;
				temp = array[k];
				array[k] = array[k + 1];
				array[k + 1] = temp;
				print_array(array, size);
			}
		}
	} while (flg == 0);
}
