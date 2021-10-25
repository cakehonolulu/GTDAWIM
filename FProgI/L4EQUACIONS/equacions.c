#include <stdio.h>
#include <math.h>

int main()
{
	int a, b, c, discriminant;

	float x1, x2;

	printf("Utilitat per calcular les arrels d'una equació de segon grau (ax^2+bx+c=0)\n");
	printf("Per començar, escrigui el valor de a: ");

	scanf("%d", &a);

	if (a == 0)
	{
		printf("L'equació no es de segon grau!\n");
	} else {
		printf("Ara escrigui el valor de b: ");

		scanf("%d", &b);

		printf("Finalment, el valor de c: ");

		scanf("%d", &c);

		// We'll now calculate the square root of b^2 - 4ax

		discriminant = ((b * b) - 4 * a * c);

		printf("Discriminant: %d\n", discriminant);

		discriminant = sqrt(discriminant);

		printf("Discriminant: %d\n", discriminant);

		if (discriminant < 0)
		{
			printf("No existeixen sol·lucions!\n");
		}

		printf("El discriminant es: %d\n", discriminant);

		x1 = (((-b) * +discriminant) / (2 * a));

		x2 = (((-b) * -discriminant) / (2 * a));

		if (x1 == x2)
		{
			printf("La sol·lució és %f\n", x1);
		} else {
			printf("Les sol·lucions son %f i %f\n", x1, x2);
		}
	}

	return 0;
}