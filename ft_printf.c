#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>

int	ft_fstrlen(const char *str)
{
	//Is it possible to measure the fullString before formatting???
	return (0);
}

//void	format(int index, const char *str, const char **format);

int	computing_flags(const char str)
{
	if (str == 'c' || str == 's' || str == 'p' || str == 'd' || str == 'i' 
		|| str == 'u' || str == 'x' || str == 'X' || str == 37)
		return (0);
	return (1);
}

int	format_text(const char *arg)
{
	write(1, arg, strlen(arg));
	return (strlen(arg));
}

int	format_char(int c)
{
	char	ch = (char) c;
	write (1, &ch, 1);
	return (1);
}

int	ft_format(const char **str, va_list args)
{
	int	length;

	length = 0;
	(*str)++;//Skip %
	//if (**str == '\0') return ; null temination protection...
	while (computing_flags(**str))//Compute flags before reaching format_char(c,s,d...)
	{
		if ()//Instead of pre-writting flags,
		     //Pass the string to "format" functions and 
		     //apply and make the neccesary "write calls" from there
		(*str)++;
	}
	if (**str == 's')
		length += format_text(va_arg(args, const char *));//pass"*format" toApply flags
	else if (**str == 'c' || **str == 37)
		length += format_char(va_arg(args, int));
	else if (**str == 'd' || **str == 'i')
	{
	}
	(*str)++;//Skip formatted_char(c,s,d,p...)
	return (length);
}

int	has_format(const char *str)
{
	str++;//Skip %
	while (*str)
	{
		if (*str == 'c' || *str == 's' || *str == 'p' || *str == 'd' || *str == 'i' 
		|| *str == 'u' || *str == 'x' || *str == 'X' || *str == 37)
			return (1);
		str++;
	}
	return (0);
}

int	calc_format(const char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		if (*str == 37 && has_format(str))
			i++;
		str++;
	}
	return (i);
}

int	ft_printf(const char *format, ...)
{
	int	str_size;
	va_list	args;
	int	format_num;

	va_start(args, format);
	str_size = 0;
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
	format_num = calc_format(format);
	while (*format)
	{
		if (*format == 37 && format_num--)
			str_size += ft_format(&format, args);
		else
		{
			write(1, format, 1);
			format++;
			str_size ++;
		}
	}
	va_end(args);
	return (str_size);
}

int	main(void)
{
	char	a = 'Z';
	char	str1[] = "Hola";

	int printed_chars; //printf return the amount of char "write calls"

	printed_chars = ft_printf("aa %s aaa %c aaa%  \n", str1, a);
	//printf("Return from ft_ -> %d\n", printed_chars);
	//printed_chars = printf("hola\n");
}
