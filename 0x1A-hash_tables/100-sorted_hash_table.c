#include "hash_tables.h"

/**
 * shash_table_create - creates a hash table aith a sorted list.
 * @size: size of the array
 * Return: pointer to the newly created hash table or NULL (fail)
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *new_table;

	new_table = malloc(sizeof(shash_table_t));
	if (!new_table)
		return (NULL);
	new_table->size = size;
	new_table->slength = 0;
	new_table->array = malloc(sizeof(shash_node_t *) * size);
	if (!new_table->array)
		return (NULL);
	new_table->shead = NULL;
	new_table->stail = NULL;
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
	new_node = malloc(sizeof(shash_node_t));
	if (!new_node)
		return (0);
	new_node->key = strdup(key);
	if (!new_node->key)
		return (0);
	new_node->value = value_cp;
	new_node->next = ht->array[index];
	ht->array[index] = new_node;
	set_sorted_list(ht, new_node);
	ht->slength++;
	return (1);
}

/**
 * set_sorted_list - sets the sorted list
 * @ht: hash table
 * @node: node to be set
 */
void set_sorted_list(shash_table_t *ht, shash_node_t *node)
{
	int i, idx;
	shash_node_t *temp;

	if (!ht->slength)
	{
		ht->shead = node;
		node->sprev = NULL;
		node->snext = NULL;
		ht->stail = node;
		return;
	}
	idx = 0;
	for (i = 0, temp = ht->shead; i < (int)ht->slength; i++, temp = temp->snext)
	{
		if (strcmp(node->key, temp->key) <= 0)
			break;
		idx++;
	}
	if (!idx)
	{
		node->sprev = ht->shead->sprev;
		node->snext = ht->shead;
		ht->shead->sprev = node;
		ht->shead = node;
	}
	else if (idx == (int)ht->slength)
	{
		node->sprev = ht->stail;
		node->snext = ht->stail->snext;
		ht->stail->snext = node, ht->stail = node;
	}
	else
	{
		idx--;
		for (temp = ht->shead, i = 0; i < (int)idx; i++, temp = temp->snext)
			;
		node->sprev = temp;
		node->snext = temp->snext;
		temp->snext->sprev = node, temp->snext = node;
	}
}

/**
 * shash_table_get -  retrieves a value associated with a key.
 * @ht: hash table
 * @key: key
 * Return: value associated with the element or NULL
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	int index;
	shash_node_t *head;

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

/**
 * shash_table_print - prints sorted hash table
 * @ht: hash table
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *head;
	int i;

	printf("{");
	for (i = 0, head = ht->shead; i < (int)ht->slength; i++, head = head->snext)
	{
		printf("'%s': '%s'", head->key, head->value);
		if (i != (int)ht->slength - 1)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - prints sorted hash table in reverse
 * @ht: hash table
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *tail;
	int i;

	printf("{");
	for (i = (int)ht->slength - 1, tail = ht->stail; i >= 0; tail = tail->sprev)
	{
		printf("'%s': '%s'", tail->key, tail->value);
		if (i > 0)
			printf(", ");
		i--;
	}
	printf("}\n");
}

/**
 * shash_table_delete - deletes a hash table.
 * @ht: hash table
 */
void shash_table_delete(shash_table_t *ht)
{
	int i;

	for (i = 0; i < (int)ht->size; i++)
	{
		if (ht->array[i])
			free_slist(ht->array[i]);
	}
	free(ht->array);
	free(ht);
}
/**
 * free_slist - frees list
 * @array: list
 */
void free_slist(shash_node_t *array)
{
	shash_node_t *head = array;

	while (array)
	{
		head = array;
		free(array->key);
		free(array->value);
		free(head);
		array = array->next;
	}
}
