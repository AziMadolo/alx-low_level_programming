#include <math.h>
#include "search_algos.h"

/**
 * custom_minimum_value - finds the minimum of two values
 * @a: first value to compare
 * @b: second value to compare
 *
 * Return: The smaller of the two values, or a if equal
 */
size_t custom_minimum_value(size_t a, size_t b)
{
    return (b < a ? b : a);
}

/**
 * custom_jump_search - searches for a value in a sorted array of integers using the
 * Jump search algorithm
 * @arr: pointer to the first element of the array to search in
 * @size: number of elements in array
 * @val: value to search for
 *
 * Return: first index where value is located, or -1 on failure
 */
int custom_jump_search(int *arr, size_t size, int val)
{
    size_t left, right, jump;
    int current_val;

    if (arr != NULL && size > 0)
    {
        jump = sqrt(size);
        left = 0;
        right = jump;
        current_val = arr[left];
        printf("Value checked arr[%lu] = [%d]\n", left, current_val);
        while (right < size && current_val < val)
        {
            if (arr[right] >= val)
                break;
            left += jump;
            right += jump;
            current_val = arr[left];
            printf("Value checked arr[%lu] = [%d]\n", left, current_val);
        }
        if (left >= size || current_val > val)
            return (-1);
        printf("Value found between indexes [%lu] and [%lu]\n", left, right);
        while (left <= custom_minimum_value(size - 1, right) && current_val <= val)
        {
            current_val = arr[left];
            printf("Value checked arr[%lu] = [%d]\n", left, current_val);
            if (current_val == val)
                return (left);
            left++;
        }
    }
    return (-1);
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

    printf("Found %d at index: %d\n\n", 6, custom_jump_search(array, size, 6));
    printf("Found %d at index: %d\n\n", 1, custom_jump_search(array, size, 1));
    printf("Found %d at index: %d\n", 999, custom_jump_search(array, size, 999));
    return (EXIT_SUCCESS);
}
