#include <stdio.h>
#include "search_algos.h"

/**
 * advanced_binary - Searches for a value in a sorted array using
 *                   advanced binary search algorithm.
 * @array: A pointer to the first element of the array to search
 * @size: The number of elements in the array
 * @value: The value to search for
 *
 * Return: The index where the value is located,
 *         or -1 if the value is not present or the array is NULL.
 */
int advanced_binary(int *array, size_t size, int value)
{
    size_t left, right, mid;

    if (array == NULL || size == 0)
        return -1;

    left = 0;
    right = size - 1;

    while (left <= right)
    {
        size_t i;

        printf("Searching in array: ");
        for (i = left; i < right; i++)
            printf("%d, ", array[i]);
        printf("%d\n", array[i]);

        mid = (left + right) / 2;

        if (array[mid] == value && array[mid - 1] != value)
            return mid;
        if (array[mid] < value)
            left = mid + 1;
        else
            right = mid;
    }

    return -1;
}
