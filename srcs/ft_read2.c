/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybesbes <ybesbes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 13:10:29 by ybesbes           #+#    #+#             */
/*   Updated: 2020/07/15 18:17:03 by ybesbes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*read_precision(t_flags flags, char *origine, int star_value)
{
	char	*result;
	int		width;

	result = NULL;
	if (star_value != -1)
		width = star_value;
	else if (ft_strlen(flags.precision) != 0)
		width = ft_atoi(flags.precision);
	else
		width = -1;
	if (width != -1)
	{
		if (ft_strchr("diuoxX", flags.specifier))
			result = ft_format(origine, 1, width, '0');
		else if (flags.specifier == 's')
		{
			if (width < ft_strlen(origine))
				result = ft_substr(origine, 0, width);
			else
				result = ft_strdup(origine);
		}
	}
	else
		result = ft_strdup(origine);
	return (result);
}

char	*read_length_and_flags(t_flags flags, char *origine, int star_width)
{
	char	*result;

	if (star_width == -1 && ft_strlen(flags.precision) == 0)
		star_width = ft_atoi(flags.width);
	if (ft_strchr(flags.flags, '-'))
		result = ft_format(origine, 0, star_width, ' ');
	else if (ft_strchr(flags.flags, '0') && ft_strlen(flags.precision) == 0 &&
			ft_strchr("diuoxX", flags.specifier))
		result = ft_format(origine, 1, star_width, '0');
	else if (ft_strlen(flags.flags) == 0)
		result = ft_format(origine, 1, star_width, ' ');
	else
		result = ft_strdup(origine);
	return (result);
}
