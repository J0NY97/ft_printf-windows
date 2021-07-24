/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_modification.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 12:00:17 by jsalmi            #+#    #+#             */
/*   Updated: 2020/09/24 12:23:05 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*specifier_to_string(char type, va_list *ap, t_flags *flags)
{
	char	*new;

	new = NULL;
	if (type == 'c')
		new = put_char(va_arg(*ap, int));
	else if (type == 'd' || type == 'i')
		new = put_int((long long int)va_arg(*ap, int), flags);
	else if (type == 'x' || type == 'X' || type == 'u' || type == 'o')
		new = put_int(va_arg(*ap, unsigned long int), flags);
	else if (type == 's')
		new = put_str(va_arg(*ap, char *), flags);
	else if (type == 'f')
		new = put_float((long double)va_arg(*ap, double), flags);
	return (new);
}

char	*add_special_chars(const char *old, t_flags *flags)
{
	char	*new;
	char	*temp;

	temp = NULL;
	new = ft_strdup(old);
	if (flags->hash == 1 && flags->specifier == 'f'
		&& flags->precision == 0)
		ft_straddchar(&new, '.');
	if (flags->plus == 1)
		temp = ft_strjoin("+", new);
	else if (flags->hash == 1
		&& (flags->specifier == 'x' || flags->specifier == 'X'))
		temp = ft_strjoin("0X", new);
	else if (flags->hash == 1 && flags->specifier == 'o'
		&& flags->precision_given == -1)
		temp = ft_strjoin("0", new);
	if (temp)
		ft_strreplace(&new, &temp);
	return (new);
}

void	apply_flags_to_string(char **new, t_flags *flags)
{
	char	*temp;

	if (flags->precision_given != -1 && flags->specifier != 'f')
	{
		temp = specifier_padding(*new, flags);
		ft_strreplace(new, &temp);
	}
	temp = add_special_chars(*new, flags);
	ft_strreplace(new, &temp);
	if (flags->negativ == 1)
	{
		if (flags->zero == -1)
		{
			temp = ft_strjoin("-", *new);
			ft_strreplace(new, &temp);
		}
		else if (flags->zero == 1)
			*new[0] = '-';
	}
	if (flags->width > -1)
	{
		temp = padding(*new, flags);
		ft_strreplace(new, &temp);
	}
}

char	*output_type(va_list *ap, t_flags *flags)
{
	char	*new;
	int		i;

	if (flags->specifier == '%')
	{
		new = ft_strdup("%");
		return (new);
	}
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
