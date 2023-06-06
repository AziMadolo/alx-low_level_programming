#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

size_t looped_listint_len(const listint_t *head);
size_t print_listint_safe(const listint_t *head);
void free_listint_safe(listint_t **head);

/**
 * looped_listint_len - Counts the number of unique nodes
 * in a looped listint_t linked list.
 * @head: A pointer to the head of the listint_t to check.
 *
 * Return: If the list is not looped - 0.
 * Otherwise - the number of unique nodes in the list.
 */
size_t looped_listint_len(const listint_t *head)
{
    // Function implementation...
}

/**
 * print_listint_safe - Prints a listint_t list safely.
 * @head: A pointer to the head of the listint_t list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
    // Function implementation...
}

/**
 * free_listint_safe - Frees a listint_t list safely.
 * @head: A double pointer to the head of the list.
 *
 * Description: Sets the head to NULL.
 */
void free_listint_safe(listint_t **head)
{
    listint_t *current, *temp;

    if (head == NULL || *head == NULL)
        return;

    current = *head;
    *head = NULL;

    while (current != NULL)
    {
        temp = current;
        current = current->next;
        free(temp);

        if (temp <= current)
            break;
    }
}
