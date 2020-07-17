/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treatment.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybesbes <ybesbes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 12:23:41 by ybesbes           #+#    #+#             */
/*   Updated: 2020/07/17 11:43:44 by ybesbes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_format(char *origine, int align, int width, char flag)
{
	char	*result;
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	result = NULL;
	if (ft_strlen(origine) < width)
	{
		j = width - ft_strlen(origine);
		if ((tmp = malloc(sizeof(char) * (j + 1))))
		{
			while (i < j)
				tmp[i++] = flag;
			tmp[i] = '\0';
			if (align == 1)
				result = ft_strjoin(tmp, origine);
			else
				result = ft_strjoin(origine, tmp);
			free(tmp);
		}
	}
	else
		result = ft_strdup(origine);
	return (result);
}

int		ft_read_precision_length_and_flag(t_flags *flags,
		char *precision, int is_neg, int star_width_arg)
{
	int		compteur;
	char	*result;

	compteur = 0;
	result = read_length_and_flags(*flags, precision, star_width_arg, is_neg);
	free(precision);
	if (result != NULL)
	{
		ft_putstr(result);
		compteur += ft_strlen(result);
		free(result);
		return (compteur);
	}
	else
		return (-1);
}

int		ft_parse_read_and_put(const char *format,
		t_flags *flags, int *i, va_list list)
{
	int		is_neg;
	int		star_width_arg;
	int		star_precision_arg;
	char	*specifier;
	char	*precision;

	*flags = ft_parse(format, i);
	if (flags->specifier != 0)
	{
		star_width_arg = ft_read_star_parameter(flags, flags->width, list);
		star_precision_arg = ft_read_star_parameter(flags, flags->precision, list);
		specifier = read_specifier(*flags, list);
		if (specifier != NULL)
		{
			is_neg = (specifier[0] == '-' && ft_strchr("di", flags->specifier) &&
					(ft_strlen(flags->precision) > 1 ||(!ft_strchr(flags->flags, '-') &&
					ft_strchr(flags->flags, '0')))) ? 1 : 0;
			precision = read_precision(*flags, specifier, star_precision_arg, is_neg);
			free(specifier);
			if (precision != NULL)
			{
				*i = *i + 1;
				return (ft_read_precision_length_and_flag(flags, precision,
								is_neg, star_width_arg));
			}
		}
	}
	else
		return (0);
	return (-1);
}
