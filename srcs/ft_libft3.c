/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybesbes <ybesbes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 21:57:15 by ybesbes           #+#    #+#             */
/*   Updated: 2020/07/16 11:41:02 by ybesbes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_count(long long n, char *base)
{
	int	i;

	i = 0;
	if (n < 0)
		i++;
	while (n / ft_strlen(base) != 0)
	{
		i++;
		n = n / ft_strlen(base);
	}
	return (i + 1);
}

int		check_base(char *base)
{
	int	i;
	int j;

	i = 0;
	j = i + 1;
	if (ft_strlen(base) == 0 || ft_strlen(base) == 1)
		return (-1);
	while (base[i] != '\0')
	{
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (-1);
			j++;
		}
		if (base[i] == '+' || base[i] == '-')
			return (-1);
		i++;
	}
	return (1);
}

char	*ft_itoa(long long nbr, char *base)
{
	char	*str;
	int		length;
	int		tmp;

	length = ft_count(nbr, base);
	tmp = length;
	str = malloc(sizeof(char) * (length + 1));
	if (str != NULL && check_base(base) == 1)
	{
		if (nbr < 0)
		{
			str[0] = '-';
			nbr = nbr * -1;
		}
		while (nbr / ft_strlen(base) != 0 && length >= 0)
		{
			str[length - 1] = base[nbr % ft_strlen(base)];
			nbr = nbr / ft_strlen(base);
			length--;
		}
		str[length - 1] = base[nbr];
		str[tmp] = '\0';
	}
	return (str);
}

int		ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\f' ||
	c == '\v' || c == '\n' || c == '\r')
		return (1);
	return (0);
}

int		ft_atoi(const char *nptr)
{
	int				sign;
	long long int	result;
	int				index;

	sign = 1;
	result = 0;
	index = 0;
	while (ft_isspace(nptr[index]) == 1)
		index++;
	if (nptr[index] == '-' || nptr[index] == '+')
	{
		if (nptr[index] == '-')
			sign = sign * -1;
		index++;
	}
	while (nptr[index] >= '0' && nptr[index] <= '9')
	{
		result = result * 10 + (nptr[index] - '0');
		index++;
		if (result > 2147483648 && sign == 1)
			return (-1);
		else if (result > 2147483648 && sign == -1)
			return (0);
	}
	return (sign * result);
}
