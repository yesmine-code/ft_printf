/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treatment.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybesbes <ybesbes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 12:23:41 by ybesbes           #+#    #+#             */
/*   Updated: 2020/07/14 12:40:33 by ybesbes          ###   ########.fr       */
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
