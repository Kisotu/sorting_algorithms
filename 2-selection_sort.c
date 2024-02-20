#include "sort.h"

/**
 * selection_sort - sorts array in ascending order
 * @array: array to sort
 * @size: size of the array
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	int temp;
	size_t k, m_index, step;

	for (step = 0; step < size - 1; step++)
	{
		m_index = step;
		for (k = step + 1; k < size; k++)
		{
			if (array[k] < array[m_index])
				m_index = k;
		}

		if (m_index != step)
		{
			temp = array[step];
			array[step] = array[m_index];
			array[m_index] = temp;

			print_array(array, size);
		}
	}
}
