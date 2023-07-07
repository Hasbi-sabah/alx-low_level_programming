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

	idx = 0;
	for (temp = ht->shead->snext; temp != ht->stail; temp = temp->snext)
	{
		if (strcmp(node->key, temp->key) <= 0)
			break;
		idx++;
	}
	if (!idx)
	{
		node->sprev = ht->shead;
		node->snext = ht->shead->snext;
		ht->shead->snext->sprev = node;
		ht->shead->snext = node;
	}
	else if (idx == (int)ht->slength)
	{
		node->sprev = ht->stail->sprev;
		node->snext = ht->stail;
		ht->stail->sprev->snext = node;
		ht->stail->sprev = node;
	}
	else
	{
		idx++;
		for (temp = ht->shead, i = 0; i < (int)idx; i++, temp = temp->snext)
			;
		temp->sprev->snext = node;
		node->sprev = temp->sprev;
		node->snext = temp;
		temp->sprev = node;
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

	printf("{");
	for (head = ht->shead->snext; head != ht->stail; head = head->snext)
	{
		printf("'%s': '%s'", head->key, head->value);
		if (head->snext != ht->stail)
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

	printf("{");
	for (tail = ht->stail->sprev; tail != ht->shead; tail = tail->sprev)
	{
		printf("'%s': '%s'", tail->key, tail->value);
		if (tail->sprev != ht->shead)
			printf(", ");
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
	free(ht->shead);
	free(ht->stail);
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
