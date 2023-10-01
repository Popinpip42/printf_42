#include <stdio.h>
#include <stdarg.h>

int	sum(int count, ...)
{
	int		total;
	int		num;
	va_list	args; //List with all necessary arguments
	int		i;

	total = 0;
	va_start(args, count); //Initialization of "params"(count) and (...)
	i = 0;
	while (i < count)
	{
		num = va_arg(args, int); //Accesing the argument and ++
		total += num;
		i++;
	}
	va_end(args);
	return (total);
}

int	main(void)
{
	int	result;

	result = sum(4, 1, 1, 1, 1);
	printf("Sum . %d\n", result);
	return (0);
}
