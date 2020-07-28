/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treatment.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybesbes <ybesbes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 12:23:41 by ybesbes           #+#    #+#             */
/*   Updated: 2020/07/28 20:05:30 by ybesbes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_case_of_null_result(char **result, int compteur)
{
	ft_putstr(*result);
	compteur += ft_strlen(*result);
	free(*result);
	return (compteur);
}

int		ft_read_precision_length_and_flag(t_flags *flags,
		char *precision, int is_neg, int star_width_arg)
{
	int		compteur;
	char	*result;

	compteur = 0;
	result = read_length_and_flags(*flags, precision, star_width_arg, is_neg);
	free(precision);
	if (flags->specifier == 'c' && flags->c_origine == '\0')
	{
		if (!ft_strchr(flags->flags, '-'))
		{
			ft_putstr(result);
			write(1, "\0", 1);
		}
		else
		{
			write(1, "\0", 1);
			ft_putstr(result);
		}
		compteur += ft_strlen(result) + 1;
		return (compteur);
	}
	else if (result != NULL)
		return (ft_case_of_null_result(&result, compteur));
	else
		return (-1);
}

char	*ft_init_specifier(t_flags *flags, va_list list,
		int *star_width_arg, int *star_precision_arg)
{
	*star_width_arg = ft_read_star_parameter(flags, flags->width, list);
	*star_precision_arg = ft_read_star_parameter(flags, flags->precision, list);
	return (read_specifier(flags, list));
}

char	*calcul_precision(t_flags *flags, char *specifier,
		int star_precision_arg, int *is_neg)
{
	char	*precision;

	*is_neg = (specifier[0] == '-' && ft_strchr("di", flags->specifier) &&
	(ft_strlen(flags->precision) > 1 || (!ft_strchr(flags->flags, '-') &&
	ft_strchr(flags->flags, '0')))) ? 1 : 0;
	precision = read_precision(*flags, specifier, star_precision_arg, *is_neg);
	return (precision);
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
		specifier = ft_init_specifier(flags, list,
					&star_width_arg, &star_precision_arg);
		if (specifier != NULL)
		{
			precision = calcul_precision(flags, specifier,
					star_precision_arg, &is_neg);
			free(specifier);
			if (precision != NULL && (*i = *i + 1))
				return (ft_read_precision_length_and_flag(flags, precision,
								is_neg, star_width_arg));
		}
	}
	else
		return (0);
	return (-1);
}
