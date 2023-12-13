#include <math.h>
#include "search_algos.h"

/**
 * advance_pointer - Advances a list pointer to a given index or the last node.
 * @node: Pointer to the current node.
 * @index: Desired index.
 *
 * Return: Node with the desired index or the last node in the list.
 */
listint_t *advance_pointer(listint_t *node, size_t index)
{
    while (node->next != NULL && node->index < index)
        node = node->next;
    return (node);
}

/**
 * custom_jump_list - Searches for a value in a sorted list of integers
 *                    using the Jump search algorithm.
 * @list: Pointer to the head of the list to search in.
 * @size: Number of nodes in the list.
 * @value: Value to search for.
 *
 * Return: Pointer to the first node where the value is located, or NULL
 *         on failure.
 */
listint_t *custom_jump_list(listint_t *list, size_t size, int value)
{
    size_t jump;
    listint_t *left, *right;

    if (list != NULL && size > 0)
    {
        jump = sqrt(size);
        left = list;
        right = advance_pointer(left, jump);
        printf("Value checked at index [%lu] = [%d]\n", right->index, right->n);
        while (right->index < (size - 1) && right->n < value)
        {
            left = right;
            right = advance_pointer(left, right->index + jump);
            printf("Value checked at index [%lu] = [%d]\n", right->index, right->n);
        }
        printf("Value found between indexes [%lu] and [%lu]\n",
               left->index, right->index);
        printf("Value checked at index [%lu] = [%d]\n", left->index, left->n);
        while (left->index < size - 1 && left->n < value)
        {
            left = left->next;
            if (left == NULL)
                return (NULL);
            printf("Value checked at index [%lu] = [%d]\n", left->index, left->n);
        }
        if (left->n == value)
            return (left);
    }
    return (NULL);
}

/**
 * create_list - Creates a linked list from an array.
 * @array: The array to create the list from.
 * @size: The size of the array.
 *
 * Return: A pointer to the head of the created list.
 */
listint_t *create_list(int *array, size_t size)
{
    listint_t *head, *new_node, *last_node;
    size_t i;

    head = NULL;
    last_node = NULL;

    for (i = 0; i < size; i++)
    {
        new_node = malloc(sizeof(listint_t));
        if (new_node == NULL)
        {
            free_list(head);
            return (NULL);
        }

        new_node->n = array[i];
        new_node->index = i;
        new_node->next = NULL;

        if (last_node != NULL)
            last_node->next = new_node;
        else
            head = new_node;

        last_node = new_node;
    }

    return (head);
}

/**
 * print_list - Prints the elements of a linked list.
 * @list: The linked list to print.
 */
void print_list(const listint_t *list)
{
    while (list != NULL)
    {
        printf("Index [%lu] = %d\n", list->index, list->n);
        list = list->next;
    }
    printf("\n");
}

/**
 * free_list - Frees the memory allocated for a linked list.
 * @list: The linked list to free.
 */
void free_list(listint_t *list)
{
    listint_t *current, *next;

    current = list;
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
}

/**
 * main - Entry point
 *
 * Return: Always EXIT_SUCCESS
 */
int main(void)
{
    listint_t *list, *res;
    int array[] = {
        0, 1, 2, 3, 4, 7, 12, 15, 18, 19, 23, 53, 61, 62, 76, 99
    };
    size_t size = sizeof(array) / sizeof(array[0]);

    list = create_list(array, size);
    print_list(list);

    res = custom_jump_list(list, size, 53);
    printf("Found %d at index: %lu\n\n", 53, res->index);
    res = custom_jump_list(list, size, 2);
    printf("Found %d at index: %lu\n\n", 2, res->index);
    res = custom_jump_list(list, size, 999);
    printf("Found %d at index: %p\n", 999, (void *)res);

    free_list(list);
    return (EXIT_SUCCESS);
}
