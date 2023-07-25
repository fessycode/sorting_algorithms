#include "sort.h"

/**
 * bubble_sort - Sorts an array of size ``size`` using
 * bubble Sort algorith.
 * @array: The array to be sorted.
 * @size: The size of the array.
 * Return: Nothing.
 */
void bubble_sort(int *array, size_t size)
{
	int temp/*, n_times = 0*/;
	size_t a, b;
	int h_value; /* highest value */
	size_t h_ps = size; /* highest position */
	bool sorted;

	if (!array)
		return;
	h_value = array[0];

	for (a = 0; a < h_ps; a++)
	{
		sorted = true;

		for (b = 0; b < h_ps - 1; b++)
		{
			if (array[b] > array[b + 1])
			{
				temp = array[b];
				array[b] = array[b + 1];
				array[b + 1] = temp;
				print_array(array, size);

				sorted = false;
			}

			h_value = h_value >= array[b + 1] ? h_value : array[b + 1];
			if (h_value == array[h_ps - 1])
				h_ps--;

			/*n_times++;*/
		}
		if (sorted)
			break;
	}
	/*printf("======= ");*/
	/*printf("%d total cycle.\n", n_times);*/
}
