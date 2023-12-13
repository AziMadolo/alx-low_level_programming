#include "search_algos.h"

/**
 * _custom_binary_search - Searches for a value in a sorted array
 *                         of integers using binary search.
 * @arr: A pointer to the first element of the array to search.
 * @left: The starting index of the [sub]array to search.
 * @right: The ending index of the [sub]array to search.
 * @val: The value to search for.
 *
 * Return: If the value is not present or the array is NULL, -1.
 *         Otherwise, the index where the value is located.
 *
 * Description: Prints the [sub]array being searched after each change.
 */
int _custom_binary_search(int *arr, size_t left, size_t right, int val)
{
    size_t i;

    if (arr == NULL)
        return (-1);

    while (right >= left)
    {
        printf("Searching in array: ");
        for (i = left; i < right; i++)
            printf("%d, ", arr[i]);
        printf("%d\n", arr[i]);

        i = left + (right - left) / 2;
        if (arr[i] == val)
            return (i);
        if (arr[i] > val)
            right = i - 1;
        else
            left = i + 1;
    }

    return (-1);
}

/**
 * custom_exponential_search - Searches for a value in a sorted array
 *                            of integers using exponential search.
 * @arr: A pointer to the first element of the array to search.
 * @size: The number of elements in the array.
 * @val: The value to search for.
 *
 * Return: If the value is not present or the array is NULL, -1.
 *         Otherwise, the index where the value is located.
 *
 * Description: Prints a value every time it is compared in the array.
 */
int custom_exponential_search(int *arr, size_t size, int val)
{
    size_t i = 0, right;

    if (arr == NULL)
        return (-1);

    if (arr[0] != val)
    {
        for (i = 1; i < size && arr[i] <= val; i = i * 2)
            printf("Value checked arr[%ld] = [%d]\n", i, arr[i]);
    }

    right = i < size ? i : size - 1;
    printf("Value found between indexes [%ld] and [%ld]\n", i / 2, right);
    return (_custom_binary_search(arr, i / 2, right, val));
}

/**
 * main - Entry point
 *
 * Return: Always EXIT_SUCCESS
 */
int main(void)
{
    int array[] = {
        0, 1, 2, 3, 4, 7, 12, 15, 18, 19, 23, 54, 61, 62, 76, 99
    };
    size_t size = sizeof(array) / sizeof(array[0]);

    printf("Found %d at index: %d\n\n", 62, custom_exponential_search(array, size, 62));
    printf("Found %d at index: %d\n\n", 3, custom_exponential_search(array, size, 3));
    printf("Found %d at index: %d\n", 999, custom_exponential_search(array, size, 999));
    return (EXIT_SUCCESS);
}
