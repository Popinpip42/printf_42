#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	ft_strlen(const char *str)
{
	int i = 0;
	while (*str)
	{
		str++;
		i++;
	}
	return i;
}

int ft_strlen2(char **str)
{	
	int i = 0;
	/*while (*str)
	{
		str++;
		i++;
	}*/
	(*str)++; //Moving outer pointer :DD!
	printf("%c\n", **str);
	return i;
}

int	main(void)
{
	char	*str = strdup("Hola");

	//ft_strlen(str);

	//ft_strlen2((const char **)&str);
	ft_strlen2(&str);

	printf("%s\n", str);
	free(--str);
}
