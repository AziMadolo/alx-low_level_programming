#include "search_algos.h"
#include <stdio.h>

/**
 * interpolation_search - Searches for a value in a sorted array using
 *                         interpolation search algorithm.
 * @array: A pointer to the first element of the array to search.
 * @size: The number of elements in the array.
 * @value: The value to search for.
 *
 * Return: If the value is not present or the array is NULL, -1.
 *         Otherwise, the index where the value is located.
 */
int interpolation_search(int *array, size_t size, int value)
{
    size_t low = 0, high = size - 1;

    if (array == NULL)
        return -1;

    while (low <= high && value >= array[low] && value <= array[high])
    {
        size_t pos = low + ((double)(high - low) / (array[high] - array[low])) * (value - array[low]);

        printf("Value checked arr[%d] = [%d]\n", (int)pos, array[pos]);

        if (array[pos] == value)
            return (int)pos;

        if (array[pos] < value)
            low = pos + 1;
        else
            high = pos - 1;
    }

    printf("Value checked arr[%d] is out of range\n", (int)low);
    return -1;
}
