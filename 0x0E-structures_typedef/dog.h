#ifndef DOG_H
#define DOG_H

/**
 * struct dog - a dog's basic info
 * @name: First member
 * @age: Second member
 * @owner: Third member
 *
 * Description: Longer description
 */
typedef struct dog
{
	char *name;
	float age;
	char *owner;
} dog_t;

/**
 * init_dog - Initializes a dog structure
 * @d: Pointer to the dog structure
 * @name: Name of the dog
 * @age: Age of the dog
 * @owner: Owner of the dog
 */
void init_dog(struct dog *d, char *name, float age, char *owner);

/**
 * print_dog - Prints the details of a dog
 * @d: Pointer to the dog structure
 */
void print_dog(struct dog *d);

/**
 * new_dog - Creates a new dog structure
 * @name: Name of the dog
 * @age: Age of the dog
 * @owner: Owner of the dog
 *
 * Return: Pointer to the newly created dog structure
 */
dog_t *new_dog(char *name, float age, char *owner);

/**
 * free_dog - Frees the memory allocated for a dog structure
 * @d: Pointer to the dog structure to be freed
 */
void free_dog(dog_t *d);

/**
 * _strcpy - Copies a string
 * @dest: Destination string
 * @src: Source string
 *
 * Return: Pointer to the destination string
 */
char *_strcpy(char *dest, const char *src);

/**
 * _strlen - Computes the length of a string
 * @s: Input string
 *
 * Return: Length of the string
 */
int _strlen(const char *s);

#endif /* DOG_H */
