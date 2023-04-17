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

	d = malloc(sizeof(struct dog));
	if (!d)
		return (NULL);
	d->name = name;
	d->age = age;
	d->owner = owner;
	return (d);
}
