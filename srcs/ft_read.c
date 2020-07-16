/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybesbes <ybesbes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 13:00:51 by ybesbes           #+#    #+#             */
/*   Updated: 2020/07/16 23:06:50 by ybesbes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_read_star_parameter(char *flags, va_list list)
{
	int i;
	int star_arg;

	i = 0;
	star_arg = -1;
	while (flags[i] != '\0')
	{
		if (flags[i] == '*')
		{
			star_arg = va_arg(list, int);
			break ;
		}
		i++;
	}
	return (star_arg);
}

char	*ft_p_specifier(va_list list)
{
	char	*tmp_specifier;
//	char	*tmp_specifier2;
	int		*ptr;

	ptr = va_arg(list, void *);
	tmp_specifier = (ptr != NULL) ? ft_itoa((long long)ptr, "0123456789abcdef") : ft_strdup("0");
//	tmp_specifier2 = ft_strjoin("0x", tmp_specifier);
//	free(tmp_specifier);
	return (tmp_specifier);
}

char	*ft_c_specifier(va_list list)
{
	char	*tmp_specifier;

	tmp_specifier = malloc(sizeof(char) * 2);
	tmp_specifier[0] = va_arg(list, int);
	tmp_specifier[1] = '\0';
	return (tmp_specifier);
}

char	*read_specifier(t_flags flags, va_list list)
{
	char	*s;

	if (flags.specifier == 'd' || flags.specifier == 'i')
		return (ft_itoa(va_arg(list, int), "0123456789"));
	if (flags.specifier == 'u')
		return (ft_itoa(va_arg(list, unsigned int), "0123456789"));
	if (flags.specifier == 'x')
		return (ft_itoa(va_arg(list, unsigned int), "0123456789abcdef"));
	if (flags.specifier == 'X')
		return (ft_itoa(va_arg(list, unsigned int), "0123456789ABCDEF"));
	if (flags.specifier == 'o')
		return (ft_itoa(va_arg(list, unsigned int), "01234567"));
	if (flags.specifier == 'p')
		return (ft_p_specifier(list));
	if (flags.specifier == 'c')
		return (ft_c_specifier(list));
	if (flags.specifier == 's')
		return (ft_strdup((s = va_arg(list, char *)) ? s : "(null)"));
	if (flags.specifier == '%')
		return (ft_strdup("%"));
	return (ft_strdup(""));
}
