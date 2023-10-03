#include <stdio.h>

int	main(void)
{
	int num = 99;
	float fl = 99.9989;
	//'-'
	printf("%-10d X\n", num);
	//'0'
	printf("%04d\n", num);
	//'.'
	printf("%.2f\n", fl);
	// '0' + '.' flags
	printf("%07.3f\n", fl);
}
