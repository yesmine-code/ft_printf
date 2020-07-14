/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybesbes <ybesbes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 22:35:15 by ybesbes           #+#    #+#             */
/*   Updated: 2020/07/14 15:05:22 by ybesbes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_free_struct(t_flags flags, int ret)
{
	if (flags.flags != NULL)
		free(flags.flags);
	if (flags.width != NULL)
		free(flags.width);
	if (flags.precision != NULL)
		free(flags.precision);
	if (flags.length != NULL)
		free(flags.length);
	return (ret);
}

int		ft_parse_read_and_put(const char *format, t_flags *flags, int *i, va_list list)
{
	int     star_width_arg;
	int     star_precision_arg;
	char    *specifier;
	char    *precision;
	char    *result;
	int		compteur;

	compteur = 0;
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
		else
			return (-1);
	}
	else
		return (-1);
}

void	ft_write(char car, int *i, int *compteur)
{
	write(1, &car,1);
	*i = *i + 1;
	*compteur = *compteur + 1;
}

int		ft_printf(const char *format, ...)
{
	int		i;
	int		compteur;
	t_flags	flags;
	va_list	list;
	int		ret;

	i = 0;
	compteur = 0;
	va_start(list, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			if (format[++i] == '%')
				ft_write('%', &i, &compteur);
			else
			{
				ret = ft_parse_read_and_put(format, &flags, &i, list);
				if (ret == -1)
					return (ft_free_struct(flags, -1));
				compteur = ret + compteur;
			}
		}
		else
			ft_write(format[i], &i, &compteur);
	}
	va_end(list);
	return (ft_free_struct(flags, compteur));
}

int main()
{
	int a;
	int	*ptr;

	a = 10;
	//printf("\n%o , %u, %#x, %X\n", -200, -200, -200, -200);
	//ft_printf("\n%o , %u, %#x, %X\n", -200, -200, -200, -200);
	//printf("\n%%yesmine\n");
//	ft_printf("\n%%yesmine\n");
	//ft_printf("yesmine %*dbesbes %xyyyy%X",3, 5, -15, -200);
	int length1 = printf("%*d.\n", 10, 250);
	int length2 = ft_printf("%*d.\n", 10, 250);
	printf("length 1 = %d\t, length 2 = %d\n", length1, length2);
	length1 = printf("%010d\t -%10s-\t -%-10s-\n", 23, "medos", "medos");
	length2 = ft_printf("%010d\t -%10s-\t -%-10s-\n", 23, "medos", "medos");
	printf("length 1 = %d\t, length 2 = %d\n", length1, length2);
	return (0);
}
