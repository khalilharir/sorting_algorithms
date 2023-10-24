#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @x: The first integer to swap.
 * @y: The second integer to swap.
 */
void swap_ints(int *x, int *y)
{
	int tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

/**
 * selection_sort - Sort an array of integers in ascending order.
 *   
 * @array: An array of integers.
 * @size: a size of the array.
 *
 * Description: it prints array after swap.
 */
void selection_sort(int *array, size_t size)
{
	int *m;
	size_t a, b;

	if (array == NULL || size < 2)
		return;

	for (a = 0; a < size - 1; a++)
	{
		m = array + a;
		for (b = a + 1; b < size; b++)
			m = (array[b] < *m) ? (array + b) : m;

		if ((array + a) != m)
		{
			swap_ints(array + a, m);
			print_array(array, size);
		}
	}
}
