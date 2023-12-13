#include "search_algos.h"

/**
 * custom_interpolation_search - Searches a value in a sorted array using \
 * an interpolation search.
 * @arr: The array to search in.
 * @size: The length of the array.
 * @val: The value to look for.
 *
 * Return: The first index of the value in the array, otherwise -1.
 */
int custom_interpolation_search(int *arr, size_t size, int val)
{
    size_t low = 0, high = size - 1, pos = 0;
    double ratio;

    if (!arr)
        return (-1);

    while (arr[high] != arr[low])
    {
        ratio = (double)(high - low) / (arr[high] - arr[low]);
        pos = low + (ratio * (val - arr[low]));

        if (pos >= size)
        {
            printf("Value checked arr[%d] is out of range\n", (int)pos);
            break;
        }

        printf("Value checked arr[%d] = [%d]\n", (int)pos, arr[pos]);

        if (arr[pos] == val)
            return (pos);
        else if (arr[pos] < val)
            low = pos + 1;
        else
            high = pos - 1;
    }

    return (val == arr[low] ? (int)low : -1);
}

/**
 * main - Entry point
 *
 * Return: Always EXIT_SUCCESS
 */
int main(void)
{
    int array[] = {
        0, 0, 1, 2, 2, 2, 2, 3, 3, 4, 4, 5, 6, 6, 7, 8, 8, 8, 9, 9
    };
    size_t size = sizeof(array) / sizeof(array[0]);

    printf("Found %d at index: %d\n\n", 3, custom_interpolation_search(array, size, 3));
    printf("Found %d at index: %d\n\n", 7, custom_interpolation_search(array, size, 7));
    printf("Found %d at index: %d\n", 999, custom_interpolation_search(array, size, 999));
    return (EXIT_SUCCESS);
}
