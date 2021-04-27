/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 13:13:51 by jsalmi            #+#    #+#             */
/*   Updated: 2020/09/26 14:20:18 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	reset_flags(t_flags *flags)
{
	flags->minus = -1;
	flags->plus = -1;
	flags->zero = -1;
	flags->space = -1;
	flags->hash = -1;
	flags->width = -1;
	flags->precision_given = -1;
	flags->precision = 6;
	flags->hh = -1;
	flags->h = -1;
	flags->ll = -1;
	flags->l = -1;
	flags->big_l = -1;
	flags->specifier = 0;
	flags->negativ = -1;
}

int		check_flags(const char *format, t_flags *flags, char *flag_chars)
{
	int i;

	i = 0;
	reset_flags(flags);
	while (format[i] && ft_strchr(flag_chars, format[i]))
	{
		if (format[i] == '-')
			flags->minus = 1;
		else if (format[i] == '+')
			flags->plus = 1;
		else if (format[i] == '#')
			flags->hash = 1;
		else if (format[i] == '0')
			flags->zero = 1;
		else if (format[i] == ' ')
			flags->space = 1;
		i++;
	}
	return (i);
}

void	flag_parser(va_list ap, t_flags *flags, const char *format)
{
	int i;

	i = check_flags(format, flags, "#0- +");
	while (format[i] && !ft_strchr(flags->specifiers, format[i]))
	{
		format[i] == '*' && format[i - 1] != '.' ?
			flags->width = va_arg(ap, int) : 0;
		if (format[i] == '.')
		{
			flags->precision = 0;
			flags->precision_given = 1;
			format[i + 1] == '*' ? flags->precision = va_arg(ap, int) : 0;
			if (ft_isdigit(format[i + 1]))
			{
				flags->precision = ft_atoi(&format[i + 1]);
				i += ft_nbrlen(flags->precision);
			}
		}
		else if (ft_isdigit(format[i]))
		{
			flags->width = ft_atoi(&format[i]);
			i += ft_nbrlen(flags->width) - 1;
		}
		i++;
	}
	if (ft_strchr(flags->specifiers, format[i]))
		flags->specifier = format[i];
}

char	*output_type(va_list *ap, t_flags *flags)
{
	char	*new;
	int		i;

	i = 0;
	new = specifier_to_string(flags->specifier, ap, flags);
	apply_flags_to_string(&new, flags);
	if (flags->specifier == 'x')
	{
		while (new[i])
		{
			new[i] = ft_tolower(new[i]);
			i++;
		}
	}
	return (new);
}

void	input_parser(t_printf *info)
{
	int		i;
	char	*new;

	i = -1;
	new = NULL;
	while (info->input[++i])
	{
		if (info->input[i] == '%')
		{
			if (info->input[i + 1] && info->input[i + 1] == '%' && (i++))
				ft_straddchar(&new, info->input[i]);
			flag_parser(info->ap, &info->flags, info->input + i + 1);
			if (info->flags.specifier != 0 &&
				ft_strchr(info->flags.specifiers, info->flags.specifier))
			{
				while (info->input[i] != info->flags.specifier)
					i++;
				new = output_type(&info->ap, &info->flags);
			}
		}
		else
			ft_straddchar(&new, info->input[i]);
		ft_stradd(&info->output, new);
		ft_strdel(&new);
	}
}
