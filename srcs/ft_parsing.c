/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybesbes <ybesbes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 20:03:30 by ybesbes           #+#    #+#             */
/*   Updated: 2020/07/16 11:45:25 by ybesbes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_flags(const char *format, int *i)
{
	int		start;
	int		offset;

	offset = 0;
	start = (int)*i;
	while (ft_strchr("-+ #0", format[*i + offset]))
		offset++;
	*i = *i + offset;
	return (ft_substr(format, start, offset));
}

char	*get_width(const char *format, int *i)
{
	int	start;
	int	offset;

	offset = 0;
	start = (int)*i;
	while (ft_isdigit(format[*i + offset]) == 1 || format[*i + offset] == '*')
		offset++;
	*i = *i + offset;
	return (ft_substr(format, start, offset));
}

char	*get_length(const char *format, int *i)
{
	int		start;
	int		offset;

	offset = 0;
	start = (int)*i;
	while (ft_strchr("hlL", format[*i + offset]))
		offset++;
	*i = *i + offset;
	return (ft_substr(format, start, offset));
}

char	get_specifier(const char *format, int *i)
{
	if (ft_strchr("cdieEfgGosuxXpn%", format[*i]))
		return (format[*i++]);
	return (0);
}

t_flags	ft_parse(const char *format, int *i)
{
	t_flags	f;

	f.flags = get_flags(format, i);
	f.width = get_width(format, i);
	if (format[*i] == '.')
	{
		*i = *i + 1;
		f.precision = ft_strjoin(".", get_width(format, i));
	}
	else
		f.precision = ft_strdup("");
	f.length = get_length(format, i);
	f.specifier = get_specifier(format, i);
	return (f);
}
