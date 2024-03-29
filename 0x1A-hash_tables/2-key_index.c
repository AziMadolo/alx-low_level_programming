#include "hash_tables.h"

/**
 * key_index - Get the index at which a key/value pair should be stored
 * in the array of a hash table.
 * @key: The key to get the index of.
 * @size: The size of the array of the hash table.
 *
 * Return: The index of the key.
 * Description: Uses the djb2 algorithm.
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int hash_value;
	unsigned long int index;

	if (key == NULL || size == 0)
		return (0);

	hash_value = hash_djb2(key);
	index = hash_value % size;
	return (index);
}
