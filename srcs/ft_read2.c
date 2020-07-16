/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybesbes <ybesbes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 13:10:29 by ybesbes           #+#    #+#             */
/*   Updated: 2020/07/16 17:36:40 by ybesbes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*read_precision(t_flags flags, char *origine, int star_value, int is_neg)
{
	char	*result;
	int		width;

	result = NULL;
	if (star_value != -1)
		width = star_value;
	else if (ft_strlen(flags.precision) > 1)
		width = ft_atoi(ft_substr(flags.precision, 1, ft_strlen(flags.precision)));
	else if (ft_strlen(flags.precision) == 1)
		width = -2;
	else
		width = -1;
	if (width > -1)
	{
		if (ft_strchr("diuoxX%", flags.specifier))
		{
			if (is_neg == 1)
				result = ft_strjoin("-", ft_format(origine + 1, 1, width, '0'));
			else
				result = ft_format(origine, 1, width, '0');
		}
		else if (flags.specifier == 's')
		{
			if (width < ft_strlen(origine))
				result = ft_substr(origine, 0, width);
			else
				result = ft_strdup(origine);
		}
	}
	else if (width == -1)
		result = ft_strdup(origine);
	else
		result = ft_strdup("");
	return (result);
}

char	*read_length_and_flags(t_flags flags, char *origine, int star_width, int is_neg)
{
	char	*result;

	if (star_width == -1)
		star_width = ft_atoi(flags.width);
	if (ft_strchr(flags.flags, '-'))
		result = ft_format(origine, 0, star_width, ' ');
	else if (ft_strchr(flags.flags, '0') && ft_strlen(flags.precision) <= 1 &&
			ft_strchr("sdiuoxX%", flags.specifier))
	{
		if (is_neg == 1)
			result = ft_strjoin("-", ft_format(origine + 1, 1, star_width - 1, '0'));
		else	
			result = ft_format(origine, 1, star_width, '0');
	}
	else if (ft_strlen(flags.flags) == 0)
		result = ft_format(origine, 1, star_width, ' ');
	else
		result = ft_strdup(origine);
	return (result);
}
