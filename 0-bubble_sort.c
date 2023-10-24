#include "sort.h"

/**
 * bubble_algorithm - sorting alg.
 * @size: array size.
 * @array: the main array to sort.
 */
void bubble_sort(int *array, size_t size)
{
	int tmp = 0;
	size_t a, b;

	for (b = 0; b < size; b++)
	{
		a = 0;
		while (a < size - 1)
		{
			if (array[a] > array[a + 1])
			{
				tmp = array[a];
				array[a] = array[a + 1];
				array[a + 1] = tmp;
				print_array(array, size);
			}
			a++;
		}
	}
}
