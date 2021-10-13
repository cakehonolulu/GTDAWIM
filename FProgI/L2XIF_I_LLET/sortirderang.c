#include <stdio.h>

int main()
{
	short int a = 1000, b = 2000;

	printf("a te el valor %d i ocupa %lu bytes\n", a, sizeof(a));
	printf("b te el valor %d i ocupa %lu bytes\n", b, sizeof(b));

	b = a +  b;
	printf("b ara te el valor %d\n", b);

	b = b * 5;
	printf("b ara te el valor %d\n", b);

	b = b * 99999;
	printf("b ara te el valor %d\n", b);

	return 0;
}
