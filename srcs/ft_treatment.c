/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treatment.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybesbes <ybesbes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 12:23:41 by ybesbes           #+#    #+#             */
/*   Updated: 2020/07/14 22:10:46 by ybesbes          ###   ########.fr       */
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
	if (ft_strlen(origine) < width)
	{
		j = width - ft_strlen(origine);
		tmp = malloc(sizeof(char) * (j + 1));
		if (tmp != NULL)
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
		char *precision, int *i, int star_width_arg)
{
	int		compteur;
	char	*result;

	compteur = 0;
	result = read_length_and_flags(*flags, precision, star_width_arg);
	*i = *i + 1;
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
	int		star_width_arg;
	int		star_precision_arg;
	char	*specifier;
	char	*precision;

	*flags = ft_parse(format, i);
	star_width_arg = ft_read_star_parameter(flags->width, list);
	star_precision_arg = ft_read_star_parameter(flags->precision, list);
	specifier = read_specifier(*flags, list);
	if (specifier != NULL)
	{
		precision = read_precision(*flags, specifier, star_precision_arg);
		free(specifier);
		if (precision != NULL)
		{
			return (ft_read_precision_length_and_flag(flags,
					precision, i, star_width_arg));
		}
		else
			return (-1);
	}
	else
		return (-1);
}
