#include <stdio.h>
#include <math.h>
#include "search_algos.h"

/**
 * custom_jump_search - Searches for a value in a sorted array of integers
 *                      using jump search algorithm.
 * @array: A pointer to the first element of the array to search.
 * @size: The number of elements in the array.
 * @value: The value to search for.
 *
 * Return: If the value is not present or the array is NULL, -1.
 *         Otherwise, the index where the value is located.
 */
int custom_jump_search(int *array, size_t size, int value)
{
    size_t jump, left, right;
    int current_val;

    if (array == NULL || size == 0)
        return (-1);

    jump = sqrt(size);
    for (left = 0; left < size; left += jump)
    {
        right = left + jump;
        if (right >= size)
            right = size - 1;

        current_val = array[left];
        printf("Value checked arr[%lu] = [%d]\n", left, current_val);

        if (current_val <= value && value <= array[right])
        {
            printf("Value found between indexes [%lu] and [%lu]\n", left, right);

            while (left <= right)
            {
                current_val = array[left];
                printf("Value checked arr[%lu] = [%d]\n", left, current_val);

                if (current_val == value)
                    return (left);

                left++;
            }
            break;
        }
    }

    printf("Value checked arr[%lu] = [%d]\n", left, array[left]);
    printf("Value checked arr[%lu] = [%d]\n", right, array[right]);
    printf("Value checked arr[%lu] = [%d]\n", left, array[left]);
    return (-1);
}

/* Function used in 100-main.c */
int jump_search(int *array, size_t size, int value)
{
    return custom_jump_search(array, size, value);
}
