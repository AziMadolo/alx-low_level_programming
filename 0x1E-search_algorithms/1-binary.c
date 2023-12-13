#include "search_algos.h"
#include <stdio.h>

/**
 * binary_search - Searches for a value in a sorted array using a binary search.
 * @array: The array to search in.
 * @size: The length of the array.
 * @value: The value to look for.
 *
 * Return: The index of the value in the array, otherwise -1.
 */
int binary_search(int *array, size_t size, int value)
{
    size_t left = 0, right = size - 1, mid;

    if (array == NULL)
        return (-1);

    while (left <= right)
    {
        mid = left + (right - left) / 2;

        printf("Searching in array: %d", array[left]);
        for (size_t i = left + 1; i <= mid; i++)
            printf(", %d", array[i]);
        printf("\n");

        if (array[mid] == value)
            return (mid);
        else if (array[mid] < value)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return (-1);
}
