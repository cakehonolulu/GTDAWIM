#include <stdio.h>

int main()
{
	char c;

	// [A-Z] = [65-90]
	// [a-z] = [97-122]
	// [0-9] = [48-57]
	c = 'A';

	printf("El codi de %c es %d\n", c, c);

	c = 'Z';
	printf("El codi de %c es %d\n", c, c);

	c = 'a';
	printf("El codi de %c es %d\n", c, c);

	c = 'z';
	printf("El codi de %c es %d\n", c, c);

	c = '0';
	printf("El codi de %c es %d\n", c, c);

	c = '9';
	printf("El codi de %c es %d\n", c, c);

	c = 'ª';
	printf("El codi de %c es %d\n", c, c);

	c = '='
	printf("El codi de %c es %d\n", c, c);

	c = ']';
	printf("El codi de %c es %d\n", c, c);

	return 0;
}
