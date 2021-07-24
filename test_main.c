#include "ft_printf.h"

int	main(void)
{
	char *meleon;

	meleon = ft_itoa_base(123, 2);
	ft_putstr(meleon);
	ft_strdel(&meleon);
	ft_putstr("\n");
	meleon = ft_itoa_base(123, 3);
	ft_putstr(meleon);
	ft_strdel(&meleon);
	ft_putstr("\n");
	meleon = ft_itoa_base(123, 4);
	ft_putstr(meleon);
	ft_strdel(&meleon);
	ft_putstr("\n");
	meleon = ft_itoa_base(123, 5);
	ft_putstr(meleon);
	ft_strdel(&meleon);
	ft_putstr("\n");
	meleon = ft_itoa_base(4278716424, 16);
	ft_putstr(meleon);
	ft_strdel(&meleon);
	ft_putstr("\n");

	ft_printf("%d %d %d\n", 1, 2, 3);
	ft_printf("%s %s %s\nis this working?\n", "str1", "str2", "str3");
	char *izard = ft_strjoiner("str1 ", "str2 ", "str3", NULL);
	ft_putstr(izard);
	ft_strdel(&izard);

	ft_putstr("\n-------------------\n");

	ft_printf("\n%#x == ", 4278716424);
	printf("%#x\n", 4278716424);

	ft_printf("\n%s == ", "string test");
	printf("%s\n", "string test");

	ft_printf("\n%d == ", 123);
	printf("%d\n", 123);

	ft_printf("\n%d == ", -123);
	printf("%d\n", -123);

	ft_printf("\n%i == ", 123);
	printf("%i\n", 123);

	ft_printf("\n%c == ", 'c');
	printf("%c\n", 'c');
	
	ft_printf("\n%f == ", 123.123);
	printf("%f\n", 123.123);

	ft_printf("\n%x == ", 123);
	printf("%x\n", 123);

	ft_printf("\n%X == ", 123);
	printf("%X\n", 123);

	ft_printf("\n%u == ", 123);
	printf("%u\n", 123);

	ft_printf("\n%o == ", 123);
	printf("%o\n", 123);

	ft_printf("\n%#x == ", 123);
	printf("%#x\n", 123);

	ft_printf("\n%+d == ", 123);
	printf("%+d\n", 123);

	ft_printf("\n%.3f == ", 123.123);
	printf("%.3f\n", 123.123);

	ft_printf("\n%.10f == ", 123.123);
	printf("%.10f\n", 123.123);
	ft_printf("\n%.9f == ", 123.123);
	printf("%.9f\n", 123.123);

	ft_printf("\n%.*f == ", 4, 123.123);
	printf("%.*f\n", 4, 123.123);

	ft_printf("\n[%-5d] == ", 123);
	printf("[%-5d]\n", 123);

	ft_printf("\n[%0-5d] == ", 123);
	printf("[%0-5d]\n", 123);

	ft_printf("\n[%-05d] == ", 123);
	printf("[%-05d]\n", 123);

	ft_printf("\n[%05d] == ", 123);
	printf("[%05d]\n", 123);
	return (0);
}
