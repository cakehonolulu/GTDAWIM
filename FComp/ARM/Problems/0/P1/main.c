#include <stdio.h>

int main()
{ int fib0=0, fib1=1, fib2, i;
for (i=0; i<50; i++)
{ fib2 = fib1 + fib0;
fib0 = fib1;
fib1 = fib2;
} /* el resultado se queda en 'fib2'*/

	printf("%d 0x%X\n", fib2, fib2);
	return 0;
}