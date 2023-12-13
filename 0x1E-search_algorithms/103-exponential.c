#include "search_algos.h"
#include <stdio.h>

/**
 * _custom_binary_search - Perform binary search on array within a given range.
 * @array: Pointer to the array to search.
 * @left: The starting index of the range.
 * @right: The ending index of the range.
 * @value: The value to search for.
 *
 * Return: The index where the value was found, or -1 if not found.
 */
static size_t _custom_binary_search(int *array, size_t left, size_t right, int value)
{
    size_t mid;

    while (left <= right)
    {
        mid = left + (right - left) / 2;

        printf("Searching in array: ");
        for (size_t i = left; i <= right; i++)
        {
            if (i == right)
                printf("%d\n", array[i]);
            else
                printf("%d, ", array[i]);
        }

        if (array[mid] == value)
            return mid;

        if (array[mid] < value)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

/**
 * exponential_search - Perform exponential search on a sorted array.
 * @array: Pointer to the array to search.
 * @size: The size of the array.
 * @value: The value to search for.
 *
 * Return: The index where the value was found, or -1 if not found.
 */
int exponential_search(int *array, size_t size, int value)
{
    size_t bound = 1;
    size_t right;

    if (array == NULL || size == 0)
        return -1;

    while (bound < size && array[bound] < value)
    {
        printf("Value checked array[%lu] = [%d]\n", bound, array[bound]);
        bound *= 2;
    }

    right = (bound < size - 1) ? bound : size - 1;

    printf("Value found between indexes [%lu] and [%lu]\n", bound / 2, right);

    return _custom_binary_search(array, bound / 2, right, value);
}
