#ifndef DOG_STRUCT
#define DOG_STRUCT
/**
 * struct dog - dog info
 *
 * @name: dogs name
 * @age: dogs age
 * @owner: dogs owner
 */
struct dog
{
	char *name;
	float age;
	char *owner;
};
#define dog_t struct dog
void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);
#endif
