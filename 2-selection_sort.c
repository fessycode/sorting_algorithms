#include "sort.h"

/**
 * selection_sort - Sorts ab array of integers in
 * ascending order using the Selection Sort
 * Algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array to be sorted
 *
 * Returns: Nothing
 */
void selection_sort(int *array, size_t size)
{
	size_t a, b;
	int n, x, pos;
	bool flag;

	if (!array)
		return;
	flag = false;

	for (a = 0; a < size; a++)
	{
		n = array[a];
		for (b = a + 1; b < size; b++)
		{
			x = array[b];
			if (x < n)
			{
				pos = b;
				n = x;
				flag = true;
			}
		}
		if (flag)
		{
			array[pos] = array[a];
			array[a] = n;
			flag = false;
			print_array(array, size);
		}
	}
}
