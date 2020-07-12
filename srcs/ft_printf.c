/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybesbes <ybesbes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 22:35:15 by ybesbes           #+#    #+#             */
/*   Updated: 2020/07/12 19:13:28 by ybesbes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_free_struct(t_flags flags)
{
	if (flags.flags != NULL)
		free(flags.flags);
	if (flags.width != NULL)
		free(flags.width);
	if (flags.precision != NULL)
		free(flags.precision);
	if (flags.length != NULL)
		free(flags.length);
}

int		ft_read_star_parameter(char *flags, va_list list)
{
	int	i;
	int	star_arg;

	i = 0;
	star_arg = -1;
	while (flags[i] != '\0')
	{
		if (flags[i] == '*')
		{
			star_arg = va_arg(list, int);
			break;
		}
		i++;
	}
	return (star_arg);
}

char	*read_specifier(t_flags flags, va_list list)
{
	if (flags.specifier == 'd' || flags.specifier == 'i')
		return (ft_itoa(va_arg(list, int), "0123456789"));
	if (flags.specifier == 'u')
		return (ft_itoa(va_arg(list, unsigned int), "0123456789"));
	if (flags.specifier == 'x')
		return (ft_itoa(va_arg(list, unsigned int), "0123456789abcdef"));
	if (flags.specifier == 'X')
		return (ft_itoa(va_arg(list, unsigned int), "0123456789ABCDEF"));
	if (flags.specifier == 'o')
		return (ft_itoa(va_arg(list, unsigned int), "01234567"));
	if (flags.specifier == 'p')
	{
		char	*tmp_specifier;
		char	*tmp_specifier2;
		int	*ptr;

		ptr = va_arg(list, void *);
		tmp_specifier = ft_itoa((long long)ptr, "0123456789abcdef");
		tmp_specifier2 = ft_strjoin("0x", tmp_specifier);
		free(tmp_specifier);
		return (tmp_specifier2);
	}
	if (flags.specifier == 'c')
	{
		char	*tmp_specifier;
		
		tmp_specifier = malloc(sizeof(char) * 2);
		tmp_specifier[0] = va_arg(list, int);
		tmp_specifier[1] = '\0';
		return (tmp_specifier);
	}
	if (flags.specifier == 's')
	{
		return (ft_strdup(va_arg(list, char *)));
	}
	return (ft_strdup(""));
}

char		*read_precision(t_flags flags, char *origine, int star_value)
{
	char	*result;
	int	width;

	if (star_value != -1)
		width = star_value;
	else if (flags.precision != NULL)
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

int		ft_printf(const char *format, ...)
{
	int		i;
	t_flags	flags;
	va_list	list;
	int		star_width_arg;
	int		star_precision_arg;
	char	*specifier;
	char	*precision;

	i = 0;
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
			}
			else
			{
				flags = ft_parse(format, &i);
				star_width_arg = ft_read_star_parameter(flags.width, list);
				star_precision_arg = ft_read_star_parameter(flags.precision, list);
				specifier = read_specifier(flags, list);
				precision = read_precision(flags, specifier, star_precision_arg);
				ft_putstr(precision);
				i++;
				free(specifier);
				free(precision);
				ft_free_struct(flags);
			}
		}
		else
		{
			write(1, &format[i], 1);
			i++;
		}
	}
	va_end(list);
	return (0);
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
	printf("%%d:%d.\t .5s:%.5s.\t .10o:%.10o.\t %%d:%d\n", 1, "yesmine", 30, 1);
	ft_printf("%%d:%d.\t .5s:%.5s.\t .10o:%.10o.\t %%d:%d\n", 1, "yesmine", 30, 1);
	return (0);
}
