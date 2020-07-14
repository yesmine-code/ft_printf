/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybesbes <ybesbes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 22:35:15 by ybesbes           #+#    #+#             */
/*   Updated: 2020/07/14 13:16:59 by ybesbes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_free_struct(t_flags flags, int ret)
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

int		ft_printf(const char *format, ...)
{
	int		i;
	int		compteur;
	t_flags	flags;
	va_list	list;
	int		star_width_arg;
	int		star_precision_arg;
	char	*specifier;
	char	*precision;
	char	*result;

	i = 0;
	compteur = 0;
	va_start(list, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '%')
			{
				write(1, "%", 1);
				i++;
				compteur++;
			}
			else
			{
				flags = ft_parse(format, &i);
				star_width_arg = ft_read_star_parameter(flags.width, list);
				star_precision_arg = ft_read_star_parameter(flags.precision, list);
				specifier = read_specifier(flags, list);
				if (specifier != NULL)
				{
					precision = read_precision(flags, specifier, star_precision_arg);
					if (precision != NULL)
					{
						result = read_length_and_flags(flags, precision, star_width_arg);
						if (result != NULL)
						{
							ft_putstr(result);
							compteur += ft_strlen(result);
							free(result);
						}
						else
							return (ft_free_struct(flags, -1));
						i++;
						free(precision);
					}
					else
						return (ft_free_struct(flags, -1));
					free(specifier);
				}
				else
					return (ft_free_struct(flags, -1));
			}
		}
		else
		{
			write(1, &format[i], 1);
			i++;
			compteur++;
		}
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
