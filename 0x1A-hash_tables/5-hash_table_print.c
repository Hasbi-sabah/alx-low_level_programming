#include "hash_tables.h"

/**
 * hash_table_print - prints a hash table.
 * @ht: hash table
 */
void hash_table_print(const hash_table_t *ht)
{
	int i;
	hash_node_t *head;

	if (!ht)
		return;
	printf("{");
	for (i = 0; i < (int)ht->size; i++)
	{
		for (head = ht->array[i]; head; head = head->next)
		{
			printf("\'%s\': \'%s\'", head->key, head->value);
			if (i != (int)ht->size - 1)
				printf(", ");
		}
	}
	printf("}\n");
}
