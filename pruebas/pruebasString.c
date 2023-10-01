#include <stdio.h>

int	main(void)
{
	char character = 'A';
	char str[] = "Text";

	//****CHARACTERS****
	//**Works Fine, left aligns char
	printf("'-' flag, character, width 5: %-10c X|\n", character);
	
	//Compilation Warning, but prints the character after 3 blank spaces
	printf("'0' flag, character, width 3: %03c\n", character);   //
	
	//Compilation Warning -> "precision used with ‘%c’ gnu_printf format [-Wformat=]"
	printf("'.' flag, character (no effect): %.2c\n", character);   

	//Compilation Warning -> "'#' flag used with ‘%c’ gnu_printf format [-Wformat=]"
	printf("'#' flag, character (no effect): %#c\n", character);

	//Compilation Warning -> "'+' flag used with ‘%c’ gnu_printf format [-Wformat=]"
	// 		      -> "'' flag used with ‘%c’ gnu_printf format [-Wformat=]"
	printf("'+' flag, character(no effect): %+c\n", character);
	printf("' ' flag, character(no effect): % c\n", character);
	
	//****STRINGS****
	//**Works Fine, left align str
	printf("'-' flag, string, width 5: %-10sX|\n", str);
	
	//Compilation Warning
	printf("'0' flag, string, width 5: %05s\n", str);   //
	
	//**Works Fine, cuts str 
	printf("'.' flag, string: %.2s\n", str);   

	//Compilation Warning
	printf("'#' flag, string (no effect): %#s\n", str);

	//Compilation Warning
	printf("'+' flag, string (no effect): %+s\n", str);
	printf("' ' flag, string (no effect): % s\n", str);
}
