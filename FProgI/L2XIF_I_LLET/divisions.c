#include <stdio.h>

int main()
{
	float r;
	int a, b, c;

	a = 1;
	b = 2;

	r = a/b; // 1/2 = 0.5????
	printf("Cas 1: el resultat de a/b es %f\n", r);

	r = (float)a/b;
	printf("Cas 2: el resultat de a/b es %f\n", r);

	r = a*1.0/b;
	printf("Cas 3: el resultat de a/b es %f\n", r);

	c = (float)a/b;
	printf("Cas 4: el resultat de a/b es %d\n", c);

	r = a/(float)b;
	printf("Cas 5: el resultat de a/b es %f\n", r);

	r = (float)(a/b);
	printf("Cas 6: el resultat de a/b es %f\n", r);

	return 0;
}
