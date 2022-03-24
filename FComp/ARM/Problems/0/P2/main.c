#include <stdio.h>

int main()
{
	const int a=3, b=4;
int i, mul=0;
for (i=0; i<b; i++)
mul += a; /* el resultado se queda en 'mul'*/

	printf("%d 0x%X\n", mul, mul);
	return 0;
}