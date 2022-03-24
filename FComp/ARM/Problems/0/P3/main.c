#include <stdio.h>

int main()
{
const int a=3;
int i, pot2=1;
for (i=0; i<a; i++)
pot2 += pot2; /* el resultado se queda en 'pot2'*/

	printf("%d 0x%X\n", pot2, pot2);
	return 0;
}