#include <stdio.h>

int	main(void)
{
	char character = 'A';
	char str[] = "Text";

	printf("'-' flag, character, width 5: %-5c\n", character);
	
	//Compilation Warning, but prints the character after 3 blank spaces
	printf("Zero-padding character, width 3: %03c\n", character);   //

	//Compilation Warning -> "'#' flag used with ‘%c’ gnu_printf format [-Wformat=]"
	printf("'#' flag, character (no effect): %#c\n", character);

	//Compilation Warning -> "precision used with ‘%c’ gnu_printf format [-Wformat=]"
	printf("'.' flag, character (no effect): %.2c\n", character);   
	
	//Compilation Warning -> "'0' flag used with ‘%c’ gnu_printf format [-Wformat=]"
	printf("'0' flag, character (no effect): %05c\n", character);   

	//Compilation Warning -> "'+' flag used with ‘%c’ gnu_printf format [-Wformat=]"
	// 		      -> "'' flag used with ‘%c’ gnu_printf format [-Wformat=]"
	printf("'+' flag, character(no effect): %+c\n", character);
	printf("' ' flag, character(no effect): % c\n", character);
	
	
	printf("Left-align string, width 10: %-10s\n", str);        // 
	printf("Right-align string, width 10: %10s\n", str);         // 
	printf("Zero-padding string, width 3 (no effect): %03s\n", str);         // 
	printf("Hash flag with string (no effect): %#s\n", str);          // 


}
