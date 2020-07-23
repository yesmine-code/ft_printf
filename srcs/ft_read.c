/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybesbes <ybesbes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 13:00:51 by ybesbes           #+#    #+#             */
/*   Updated: 2020/07/23 21:22:42 by ybesbes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_free(char *str)
{
	free(str);
	return (ft_strdup(""));
}

int		ft_read_star_parameter(t_flags *flags, char *str, va_list list)
{
	int i;
	int star_arg;

	i = -1;
	star_arg = -1;
	while (str[++i] != '\0')
	{
		if (str[i] == '*')
		{
			star_arg = va_arg(list, int);
			if (star_arg < 0 && ft_strchr("si", flags->specifier) &&
					ft_strchr(str, '.'))
			{
				flags->precision = ft_free(flags->precision);
				star_arg = -1;
			}
			else if (star_arg < 0)
			{
				flags->flags = ft_strjoin("-", flags->flags);
				star_arg = -star_arg;
			}
			break ;
		}
	}
	return (star_arg);
}

char	*ft_p_specifier(va_list list)
{
	char	*tmp_specifier;
	int		*ptr;

	ptr = va_arg(list, void *);
	tmp_specifier = (ptr != NULL) ?
		ft_itoa((long long)ptr, "0123456789abcdef") : ft_strdup("0");
	return (tmp_specifier);
}

char	*ft_c_specifier(t_flags *flags, va_list list)
{
	char	*tmp_specifier;

	tmp_specifier = malloc(sizeof(char) * 2);
	flags->c_origine = va_arg(list, int);
	tmp_specifier[0] = flags->c_origine;
	tmp_specifier[1] = '\0';
	return (tmp_specifier);
}

char	*read_specifier(t_flags *flags, va_list list)
{
	char	*s;

	if (flags->specifier == 'd' || flags->specifier == 'i')
		return (ft_itoa(va_arg(list, int), "0123456789"));
	if (flags->specifier == 'u')
		return (ft_itoa(va_arg(list, unsigned int), "0123456789"));
	if (flags->specifier == 'x')
		return (ft_itoa(va_arg(list, unsigned int), "0123456789abcdef"));
	if (flags->specifier == 'X')
		return (ft_itoa(va_arg(list, unsigned int), "0123456789ABCDEF"));
	if (flags->specifier == 'o')
		return (ft_itoa(va_arg(list, unsigned int), "01234567"));
	if (flags->specifier == 'p')
		return (ft_p_specifier(list));
	if (flags->specifier == 'c')
		return (ft_c_specifier(flags, list));
	if (flags->specifier == 's')
		return (ft_strdup((s = va_arg(list, char *)) ? s : "(null)"));
	if (flags->specifier == '%')
		return (ft_strdup("%"));
	return (NULL);
}
