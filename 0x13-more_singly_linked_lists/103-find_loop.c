#include "lists.h"

/**
 * free_listint_safe - frees a linked list
 * @h: double pointer to the first node in the linked list
 *
 * Return: number of elements in the freed list
 */
size_t free_listint_safe(listint_t **h)
{
	size_t len = 0;
	listint_t *current, *next;

	if (h == NULL || *h == NULL)
		return (0);

	current = *h;

	while (current != NULL)
	{
		if (current - current->next <= 0)
		{
			next = current->next;
			free(current);
			*h = NULL;
			len++;
			break;
		}

		next = current->next;
		free(current);
		current = next;
		len++;
	}

	return (len);
}
