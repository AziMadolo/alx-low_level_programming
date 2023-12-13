#include "search_algos.h"

/**
 * jump_search_linked_list - Searches for a value in a sorted singly
 *                           linked list of integers using linear skip.
 * @head: A pointer to the head of the linked list to search.
 * @value: The value to search for.
 *
 * Return: If the value is not present or the head of the list is NULL, NULL.
 *         Otherwise, a pointer to the first node where the value is located.
 *
 * Description: Prints a value every time it is compared in the list.
 *              Uses the square root of the list size as the jump step.
 */
skiplist_t *jump_search_linked_list(skiplist_t *head, int value)
{
    skiplist_t *node, *jump;

    if (head == NULL)
        return (NULL);

    for (node = jump = head; jump->next != NULL && jump->n < value;)
    {
        node = jump;
        if (jump->express != NULL)
        {
            jump = jump->express;
            printf("Value checked at index [%lu] = [%d]\n",
                   jump->index, jump->n);
        }
        else
        {
            while (jump->next != NULL)
                jump = jump->next;
        }
    }

    printf("Value found between indexes [%lu] and [%lu]\n",
           node->index, jump->index);

    for (; node->index < jump->index && node->n < value; node = node->next)
        printf("Value checked at index [%lu] = [%d]\n", node->index, node->n);
    printf("Value checked at index [%lu] = [%d]\n", node->index, node->n);

    return (node->n == value ? node : NULL);
}

/**
 * create_skiplist - Creates a skip list from an array.
 * @array: The array to create the skip list from.
 * @size: The size of the array.
 *
 * Return: A pointer to the head of the created skip list.
 */
skiplist_t *create_skiplist(int *array, size_t size)
{
    skiplist_t *head, *new_node, *last_node, *express_node;
    size_t i, level, max_level;

    head = malloc(sizeof(skiplist_t));
    if (head == NULL)
        return (NULL);

    head->n = array[0];
    head->index = 0;
    head->express = NULL;
    head->next = NULL;

    last_node = head;
    express_node = head;
    max_level = 0;

    for (i = 1; i < size; i++)
    {
        new_node = malloc(sizeof(skiplist_t));
        if (new_node == NULL)
        {
            free_skiplist(head);
            return (NULL);
        }

        new_node->n = array[i];
        new_node->index = i;
        new_node->express = NULL;
        new_node->next = NULL;

        level = 0;
        while (rand() % 2 == 0 && level <= max_level)
        {
            express_node = express_node->express;
            level++;
        }

        if (level > max_level)
        {
            max_level = level;
            express_node = head;
            last_node = head;
        }

        new_node->express = express_node;
        last_node->next = new_node;
        last_node = new_node;
        express_node = head;
    }

    return (head);
}

/**
 * print_skiplist - Prints the elements of a skip list.
 * @list: The skip list to print.
 */
void print_skiplist(const skiplist_t *list)
{
    while (list != NULL)
    {
        printf("Index [%lu] = %d\n", list->index, list->n);
        list = list->next;
    }
    printf("\n");
}

/**
 * free_skiplist - Frees the memory allocated for a skip list.
 * @list: The skip list to free.
 */
void free_skiplist(skiplist_t *list)
{
    skiplist_t *current, *next;

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
    skiplist_t *list, *res;
    int array[] = {
        0, 1, 2, 3, 4, 7, 12, 15, 18, 19, 23, 53, 61, 62, 76, 99
    };
    size_t size = sizeof(array) / sizeof(array[0]);

    list = create_skiplist(array, size);
    print_skiplist(list);

    res =  jump_search_linked_list(list, 53);
    printf("Found %d at index: %lu\n\n", 53, res->index);
    res =  jump_search_linked_list(list, 2);
    printf("Found %d at index: %lu\n\n", 2, res->index);
    res =  jump_search_linked_list(list, 999);
    printf("Found %d at index: %p\n", 999, (void *) res);

    free_skiplist(list);
    return (EXIT_SUCCESS);
}
