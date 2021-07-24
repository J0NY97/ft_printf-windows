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

	ft_printf("\n%#x\n", 4278716424);
	printf("%#x\n", 4278716424);

	ft_printf("pad with zeros 0 amount of times: %02d\n", 3);

	return (0);
}
