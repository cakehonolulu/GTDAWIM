#include <stdio.h>

int main()
{
const int a=3, b=40;
int i=b, div=0;
if (b>a)
while (i>0)
{ i -= a;
div++;
} /* el resultado queda en 'div'*/
	printf("%d 0x%X\n", div, div);
	return 0;
}