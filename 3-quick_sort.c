#include "sort.h"

void swap_ints(int *x, int *y);
int partition(int *array, size_t size, int L, int R);
void sort(int *array, size_t size, int L, int R);
void quick_sort(int *array, size_t size);

/**
 * swap_ints - swapping int in array.
 * @x: first integer to swap.
 * @y: second integer to swap.
 */
void swap_ints(int *x, int *y)
{
	int tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

/**
 * partition - order a subset of an array.
 *                    
 * @array: The array of int.
 * @size: The size of the array.
 * @L: The starting index of order.
 * @R: The ending index of order.
 *
 * Return: The final sett index.
 */
int partition(int *array, size_t size, int L, int R)
{
	int *p, f, b;

	p = array + R;
	for (f = b = L; b < R; b++)
	{
		if (array[b] < *p)
		{
			if (f < b)
			{
				swap_ints(array + b, array + f);
				print_array(array, size);
			}
			f++;
		}
	}

	if (array[f] > *p)
	{
		swap_ints(array + f, p);
		print_array(array, size);
	}

	return (f);
}

/**
 * sort - Implement by recursion alg.
 * @array: An array of integers.
 * @size: The size of the array.
 * @L: The starting index of the array partition to order.
 * @R: The ending index of the array partition to order.
 *
 * Description: quick sort alg.
 */
void sort(int *array, size_t size, int L, int L)
{
	int z;

	if (R - L > 0)
	{
		z = partition(array, size, L, R);
		sort(array, size, L, z - 1);
		sort(array, size, z + 1, R);
	}
}

/**
 * quick_sort - Sort an array of integers in ascending
 *              order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Lomuto partition scheme. Prints
 *              the array after each swap of two elements.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	sort(array, size, 0, size - 1);
}
