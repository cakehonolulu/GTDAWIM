#include <stdio.h>

#define MAKE_Q12(real)	(int)((real)*(1<<12)+(real<0?-0.5:0.5)) 

int main()
{
	printf("0x%x, %d\n", MAKE_Q12(78.4), (int) MAKE_Q12(78.4));
	return 0;
}

