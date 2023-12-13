#include "search_algos.h"

/**
 * custom_print_array - Prints the contents of an array.
 * @arr: The source of the array to print.
 * @left: The left index of the array.
 * @right: The right index of the array.
 */
void custom_print_array(int *arr, size_t left, size_t right)
{
    size_t i;

    if (arr)
    {
        printf("Array contents: ");
        for (i = left; i < left + (right - left + 1); i++)
            printf("%d%s", *(arr + i), i < left + (right - left) ? ", " : "\n");
    }
}

/**
 * custom_binary_search_index - Searches a value in a sorted array using \
 * a binary search.
 * @arr: The array to search in.
 * @left: The left index of the array.
 * @right: The right index of the array.
 * @val: The value to look for.
 *
 * Return: The first index of the value in the array, otherwise -1.
 */
int custom_binary_search_index(int *arr, size_t left, size_t right, int val)
{
    size_t mid;

    if (!arr)
        return (-1);

    custom_print_array(arr, left, right);
    mid = left + ((right - left) / 2);

    if (left == right)
        return (*(arr + mid) == val ? (int)mid : -1);

    if (val < *(arr + mid))
        return custom_binary_search_index(arr, left, mid - 1, val);
    else if (val == *(arr + mid))
        return (int)mid;
    else
        return custom_binary_search_index(arr, mid + 1, right, val);
}

/**
 * custom_binary_search - Searches a value in a sorted array using a binary search.
 * @arr: The array to search in.
 * @size: The length of the array.
 * @val: The value to look for.
 *
 * Return: The index of the value in the array, otherwise -1.
 */
int custom_binary_search(int *arr, size_t size, int val)
{
    return custom_binary_search_index(arr, 0, size - 1, val);
}

/**
 * main - Entry point
 *
 * Return: Always EXIT_SUCCESS
 */
int main(void)
{
    int array[] = {
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9
    };
    size_t size = sizeof(array) / sizeof(array[0]);

    printf("Found %d at index: %d\n\n", 2, custom_binary_search(array, size, 2));
    printf("Found %d at index: %d\n\n", 5, custom_binary_search(array, 5, 5));
    printf("Found %d at index: %d\n", 999, custom_binary_search(array, size, 999));
    return (EXIT_SUCCESS);
}
