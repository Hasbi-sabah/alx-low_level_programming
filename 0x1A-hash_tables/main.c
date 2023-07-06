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

    ht = hash_table_create(1024);
    hash_table_print(ht);
    hash_table_set(ht, "c", "fun");
    printf("%ld\n", key_index((const unsigned char *)"c", 1024)); 
    hash_table_set(ht, "python", "awesome");
    printf("%ld\n", key_index((const unsigned char *)"python", 1024)); 
    hash_table_set(ht, "Bob", "and Kris love asm");
    printf("%ld\n", key_index((const unsigned char *)"Bob", 1024)); 
    hash_table_set(ht, "N", "queens");
    printf("%ld\n", key_index((const unsigned char *)"N", 1024)); 
    hash_table_set(ht, "Asterix", "Obelix");
    printf("%ld\n", key_index((const unsigned char *)"Asterix", 1024)); 
    hash_table_set(ht, "Betty", "Cool");
    printf("%ld\n", key_index((const unsigned char *)"Betty", 1024)); 
    hash_table_set(ht, "98", "Battery Street");
    printf("%ld\n", key_index((const unsigned char *)"98", 1024)); 
    hash_table_print(ht);
    return (EXIT_SUCCESS);
}
