#include "search_algos.h"

/**
 * custom_advanced_binary_recursive - Searches recursively for a value in a sorted
 *                                   array of integers using advanced binary search.
 * @arr: A pointer to the first element of the [sub]array to search.
 * @left: The starting index of the [sub]array to search.
 * @right: The ending index of the [sub]array to search.
 * @val: The value to search for.
 *
 * Return: If the value is not present, -1.
 *         Otherwise, the index where the value is located.
 *
 * Description: Prints the [sub]array being searched after each change.
 */
int custom_advanced_binary_recursive(int *arr, size_t left, size_t right, int val)
{
    size_t i;

    if (right < left)
        return (-1);

    printf("Searching in array: ");
    for (i = left; i < right; i++)
        printf("%d, ", arr[i]);
    printf("%d\n", arr[i]);

    i = left + (right - left) / 2;
    if (arr[i] == val && (i == left || arr[i - 1] != val))
        return (i);
    if (arr[i] >= val)
        return (custom_advanced_binary_recursive(arr, left, i, val));
    return (custom_advanced_binary_recursive(arr, i + 1, right, val));
}

/**
 * custom_advanced_binary - Searches for a value in a sorted array
 *                         of integers using advanced binary search.
 * @arr: A pointer to the first element of the array to search.
 * @size: The number of elements in the array.
 * @val: The value to search for.
 *
 * Return: If the value is not present or the array is NULL, -1.
 *         Otherwise, the first index where the value is located.
 *
 * Description: Prints the [sub]array being searched after each change.
 */
int custom_advanced_binary(int *arr, size_t size, int val)
{
    if (arr == NULL || size == 0)
        return (-1);

    return (custom_advanced_binary_recursive(arr, 0, size - 1, val));
}

/**
 * main - Entry point
 *
 * Return: Always EXIT_SUCCESS
 */
int main(void)
{
    int array[] = {
        0, 1, 2, 5, 5, 6, 6, 7, 8, 9
    };
    size_t size = sizeof(array) / sizeof(array[0]);

    printf("Found %d at index: %d\n\n", 8, custom_advanced_binary(array, size, 8));
    printf("Found %d at index: %d\n\n", 5, custom_advanced_binary(array, size, 5));
    printf("Found %d at index: %d\n", 999, custom_advanced_binary(array, size, 999));
    return (EXIT_SUCCESS);
}
