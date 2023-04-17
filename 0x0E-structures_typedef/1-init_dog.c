#include "dog.h"
#include <stdio.h>

/**
 * init_dog - initialize a variable of type struct dog
 * @d: const
 * @name: dogs name
 * @age: dogs age
 * @owner: dogs owner
 */

void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (name == NULL)
		name = "";
	if (owner == NULL)
		owner = "";
	d->name = name;
	d->age = age;
	d->owner = owner;
}
