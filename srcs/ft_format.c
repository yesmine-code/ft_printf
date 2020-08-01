/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybesbes <ybesbes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 21:11:32 by ybesbes           #+#    #+#             */
/*   Updated: 2020/08/01 10:46:17 by ybesbes          ###   ########.fr       */
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

char	*ft_free(char *str)
{
	free(str);
	return (ft_strdup(""));
}
