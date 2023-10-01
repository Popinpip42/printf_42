#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>

int	ft_fstrlen(const char *str)
{
	/*int	i;
	int	formating;

	formating = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if(str[i] == '%')
		{
			while(!formating)
			{
				
			}	
		}
		i++;
	}*/
	return (0);
}

//void	format(int index, const char *str, const char **format);

int	computing_flags(const char str)
{
	if (str == 'c' || str == 's' || str == 'p' || str == 'd' || str == 'i' 
		|| str == 'u' || str == 'x' || str == 'X' || str == 37)
		return (1);
	return (0);
}

void	ft_format(const char **str)
{
	(*str)++;//Skip %
	while (!computing_flags(**str))//Compute flags before reaching format_char(c,s,d...)
	{
		if (**str == 0) //Flag 0
		{
		}
		(*str)++;
	}
	(*str)++;//Skip format_char(c,s,d,p...)
}

int	ft_printf(const char *format, ...)
{
	int	str_size;
	int	i;
	va_list	args;
	char	*str;

	va_start(args, format);
	str_size = strlen(format);
	//str_size = ft_fstrlen(format);
	/*str = (char*)malloc((str_size + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (*format != '\0')
	{
		if (*format == '%')
			format(i, &str, &format);
		else
			str[i] = *format;	
		i++;
		format++;
	}*/
	while (*format)
	{
		if (*format == 37)
			ft_format(&format);
		else
		{
			write(1, format, 1);
			format++;
		}
	}
	write(1, "\n", 1);
	va_end(args);
	return (str_size);
}

int	main(void)
{
	char	a = 'a';
	char	str1[] = "Hola\n";

	int printed_chars;

	printed_chars = ft_printf("aa %c aaa % d aaa", a);
	printf("Return from ft_ -> %d\n", printed_chars);
	//printed_chars = printf("hola\n");
}
