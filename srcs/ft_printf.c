/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybesbes <ybesbes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 22:35:15 by ybesbes           #+#    #+#             */
/*   Updated: 2020/07/15 18:23:29 by ybesbes          ###   ########.fr       */
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

void	ft_write(char car, int *i, int *compteur)
{
	write(1, &car, 1);
	*i = *i + 1;
	*compteur = *compteur + 1;
}

void	ft_init(int *i, int *compteur)
{
	*i = 0;
	*compteur = 0;
}

int		ft_printf(const char *format, ...)
{
	int		i;
	int		compteur;
	t_flags	flags;
	va_list	list;
	int		ret;

	ft_init(&i, &compteur);
	va_start(list, format);
	while (format[i] != '\0' && compteur >= 0)
	{
		if (format[i] == '%')
		{
			if (format[++i] == '%')
				ft_write('%', &i, &compteur);
			else
			{
				ret = ft_parse_read_and_put(format, &flags, &i, list);
				compteur = (ret == -1 ? ret : ret + compteur);
			}
		}
		else
			ft_write(format[i], &i, &compteur);
	}
	va_end(list);
	return (ft_free_struct(flags, compteur));
}
