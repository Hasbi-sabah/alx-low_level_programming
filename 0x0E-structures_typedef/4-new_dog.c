#include "dog.h"
#include <stdlib.h>

/**
 * new_dog - initialize a variable of type struct dog
 * @name: dogs name
 * @age: dogs age
 * @owner: dogs owner
 * Return: pointer or NULL
 */

dog_t *new_dog(char *name, float age, char *owner)
{
	struct dog *d;
	char *dog_name = name, *dog_owner = owner;

	d = malloc(sizeof(struct dog));
	if (!d)
		return (NULL);
	d->name = dog_name;
	d->age = age;
	d->owner = dog_owner;
	return (d);
}
