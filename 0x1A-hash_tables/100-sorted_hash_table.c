#include "hash_tables.h"

/**
 * shash_table_create - creates a hash table aith a sorted list.
 * @size: size of the array
 * Return: pointer to the newly created hash table or NULL (fail)
 */
shash_table_t *shash_table_create(unsigned long int size);
{
	shash_table_t *new_table;

	new_table = malloc(sizeof(shash_table_t));
	if (!new_table)
		return (NULL);
	new_table->size = size;
	new_table->array = malloc(sizeof(shash_node_t *) * size);
	if (!new_table->array)
		return (NULL);
	new_table->shead = malloc(sizeof(shash_node_t));
	if (!new_table->shead)
		return (NULL);
	new_table->stail = malloc(sizeof(shash_node_t));
	if (!new_table->stail)
		return (NULL);
	new_table->shead->sprev = NULL;
	new_table->shead->snext = new_table->stail;
	new_table->stail->sprev = new_table->shead;
	new_table->stail->snext = NULL;
	return (new_table);
}

/**
 * shash_table_set - adds an element to the sorted hash table.
 * @ht: hash table you want to add or update the key/value to
 * @key: is the key, can't be empty
 * @value: is the value associated with the key.
 * Return: 1 if it succeeded, 0 otherwise
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	int index = 0;
	char *value_cp = NULL;
	shash_node_t *new_node = NULL, *head = NULL;

	if (!ht || !key || *key == '\0' || !value)
		return (0);
	value_cp = strdup(value);
	if (!value_cp)
		return (0);
	index = key_index((const unsigned char *)key, ht->size);
	if (ht->array[index] && !strcmp(ht->array[index]->key, key))
	{
		free(ht->array[index]->value);
		ht->array[index]->value = value_cp;
		return (1);
	}
	for (head = ht->array[index]; head; head = head->next)
	{
		if (!strcmp(head->key, key))
		{
			free(head->value);
			head->value = value_cp;
			return (1);
		}
	}
	new_node = malloc(sizeof(hash_node_t));
	if (!new_node)
		return (0);
	new_node->key = strdup(key);
	if (!new_node->key)
		return (0);
	new_node->value = value_cp;
	new_node->next = ht->array[index];
	ht->array[index] = new_node;
	return (1);
}

shash_table_t *set_sorted_list(shash_table_t *ht, hash_node_t *node)
{
	int i, idx;
	int len = list_len(*ht);
	shash_node_t *temp;

	idx = 0;
	while (ht->shead && node->key >= ht->shead->key)
	{
		ht->shead = ht->shead->snext;
		idx++;
	}
	if (!idx)
	{
		set_node_top(ht, node);
	}
	else if (idx == len)
	{
		set_node_end(ht, node);
	}
	else
	{
		for (temp = ht->array[index], i = 0; i < (int)idx; i++, temp = temp->snext)
			;
		temp->sprev->snext = node;
		node->sprev = temp->sprev;
		node->snext = temp;
		temp->sprev = node;
	}
	return (node);
}

void set_node_top(shash_table_t *ht, hash_node_t *node)
{


}

/**
 * dlistint_len - returns number of elements
 * @h: head
 * Return: int number of nodes
 */
int list_len(const shash_table_t *h)
{
	int i;

	for (i = 0; h->shead; h->shead = h->shead->next, i++)
		;
	return (i);
}
