#include "hash_tables.h"

/**
 * hash_table_get -  retrieves a value associated with a key.
 * @ht: hash table
 * @key: key
 * Return: value associated with the element or NULL
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	int index;
	hash_node_t *head;

	if (!ht || !key || *key == '\0')
		return (NULL);
	index = key_index((const unsigned char *)key, ht->size);
	if (ht->array[index] && !strcmp(ht->array[index]->key, key))
		return (ht->array[index]->value);
	for (head = ht->array[index]; head; head = head->next)
	{
		if (!strcmp(head->key, key))
			return (head->value);
	}
	return (NULL);
}
