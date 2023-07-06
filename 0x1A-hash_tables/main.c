#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"

/**
 * main - check the code
 *
 * Return: Always EXIT_SUCCESS.
 */
int main(void)
{
    hash_table_t *ht;
    int i;

    ht = hash_table_create(1024);
    hash_table_set(ht, "betty", "cool");
    i = key_index((const unsigned char *)"betty", ht->size);
    printf("%s, %s\n", ht->array[i]->key, ht->array[i]->value);
    printf("------------\n");
    hash_table_set(ht, "dram", "not cool");
    i = key_index((const unsigned char *)"dram", ht->size);
    printf("%s, %s\n", ht->array[i]->key, ht->array[i]->value);
    printf("------------\n");
    hash_table_set(ht, "vivency", "cool");
    i = key_index((const unsigned char *)"vivency", ht->size);
    printf("%s, %s\n", ht->array[i]->key, ht->array[i]->value);
    printf("%s, %s\n", ht->array[i]->next->key, ht->array[i]->next->value);
    printf("------------\n");
    hash_table_set(ht, "dram", "extremly cool");
    i = key_index((const unsigned char *)"dram", ht->size);
    printf("%s, %s\n", ht->array[i]->key, ht->array[i]->value);
    printf("%s, %s\n", ht->array[i]->next->key, ht->array[i]->next->value);
    return (EXIT_SUCCESS);
}
