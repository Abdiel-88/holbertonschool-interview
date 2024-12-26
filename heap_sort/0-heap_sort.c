#include "sort.h"
#include <stdio.h>

/**
 * swap - Swaps two integers in an array
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * sift_down - Maintains the max heap property
 * @array: The array to heapify
 * @size: Total size of the array
 * @root: Index of the root element of the current subtree
 * @heap_size: Current size of the heap
 */
void sift_down(int *array, size_t size, size_t root, size_t heap_size)
{
	size_t largest = root;
	size_t left = 2 * root + 1;
	size_t right = 2 * root + 2;

	if (left < heap_size && array[left] > array[largest])
		largest = left;

	if (right < heap_size && array[right] > array[largest])
		largest = right;

	if (largest != root)
	{
		swap(&array[root], &array[largest]);
		print_array(array, size);
		sift_down(array, size, largest, heap_size);
	}
}

/**
 * heap_sort - Sorts an array using the Heap sort algorithm
 * @array: Array of integers to sort
 * @size: Size of the array
 */
void heap_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	/* Build the max heap */
	for (int i = (int)size / 2 - 1; i >= 0; i--)
		sift_down(array, size, i, size);

	/* Extract elements from the heap */
	for (size_t end = size - 1; end > 0; end--)
	{
		swap(&array[0], &array[end]);
		print_array(array, size);
		sift_down(array, size, 0, end);
	}
}
