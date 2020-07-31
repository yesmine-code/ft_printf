/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybesbes <ybesbes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 13:10:29 by ybesbes           #+#    #+#             */
/*   Updated: 2020/07/31 20:32:00 by ybesbes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*read_precision_case(t_flags flags, char *origine,
		int width, int is_neg)
{
	char	*hex;
	char	*result;

	result = NULL;
	if (ft_strchr("diuoxXp%", flags.specifier))
	{
		if (width == 0 && ft_strlen(origine) == 1 && origine[0] == '0')
			origine = ft_strdup("");
		hex = (flags.specifier == 'p') ? ft_strdup("0x") : ft_strdup("");
		if (is_neg == 1)
			result = ft_strjoin("-", ft_strjoin(hex,
						ft_format(origine + 1, 1, width, '0')));
		else
			result = ft_strjoin(hex, ft_format(origine, 1, width, '0'));
	}
	else if (ft_strchr("s", flags.specifier))
	{
		if (width < ft_strlen(origine))
			result = ft_substr(origine, 0, width);
		else
			result = ft_strdup(origine);
	}
	return (result);
}

char	*read_precision(t_flags flags, char *origine,
		int star_value, int is_neg)
{
	char	*result;
	int		width;

	result = NULL;
	if (star_value != -1)
		width = star_value;
	else if (ft_strlen(flags.precision) > 1)
		width = ft_atoi(ft_substr(flags.precision,
					1, ft_strlen(flags.precision)));
	else if (ft_strlen(flags.precision) == 1)
		width = -2;
	else
		width = -1;
	if (width > 1 && flags.specifier == 'p' && //ft_strlen(origine) == 1 &&
			origine[0] == '0' && ft_strchr(flags.flags, '-'))
		width = 1;
	if (width >= 0)
		result = read_precision_case(flags, origine, width, is_neg);
	else if (width == -1)
		result = ft_strdup(origine);
	else if (width == -2 && flags.specifier == 'p')
		result = ft_strdup("0x");
	else
		result = ft_strdup("");
	return (result);
}

char	*ft_case_of_p(t_flags flags, char *origine, int star_width)
{
	char	*result;

	result = NULL;
	if (flags.specifier == 'p' && ft_strlen(flags.precision) < 1)
		result = ft_format(ft_strjoin("0x", origine), 0, star_width, ' ');
	else
		result = ft_format(origine, 0, star_width, ' ');
	return (result);
}

char	*read_length_and_flags(t_flags flags, char *origine,
		int star_width, int is_neg)
{
	char	*result;

	if (star_width == -1)
		star_width = ft_atoi(flags.width);
	if (flags.specifier == 'c' && flags.c_origine == '\0')
		star_width--;
	if (ft_strchr(flags.flags, '-'))
		result = ft_case_of_p(flags, origine, star_width);
	else if (ft_strchr(flags.flags, '0') &&
		   	(ft_strlen(flags.precision) <= 1 ||	ft_atoi(flags.precision + 1) < 0) &&
			ft_strchr("sdiuoxX%", flags.specifier))
	{
		if (is_neg == 1)
			result = ft_strjoin("-", ft_format(origine + 1, 1,
						star_width - 1, '0'));
		else
			result = ft_format(origine, 1, star_width, '0');
	}
	else if (flags.specifier == 'p' && ft_strlen(flags.precision) < 1)
		result = ft_format(ft_strjoin("0x", origine), 1, star_width, ' ');
	else
		result = ft_format(origine, 1, star_width, ' ');
	return (result);
}
