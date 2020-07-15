/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybesbes <ybesbes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 10:46:11 by ybesbes           #+#    #+#             */
/*   Updated: 2020/07/15 18:19:39 by ybesbes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <string.h>
# include <stdlib.h>
# include <wchar.h>
# include <stdio.h>

typedef struct  s_flags
{
	char *flags;
	char *width;
	char *precision;
	char *length;
	char specifier;
}				t_flags;


void	ft_putstr(char *s);
int		ft_strlen(const char *str);
char    *ft_strdup(const char *s);
char    *ft_substr(char const *s, unsigned int start, int len);
int     ft_isdigit(int c);
char    *ft_strchr(char const *s, int c);
int		ft_count(int n);
char	*ft_itoa(int n);




char	get_specifier(const char *format, int *i);
char	*get_length(const char *format, int *i);
char	*get_width(const char *format, int *i);
char    *get_flags(const char *format, int *i);

t_flags	ft_parse(const char *format, int *i);

int		ft_read_star_parameter(char *flags, va_list list);
char	*read_specifier(t_flags flags, va_list list);
void	ft_free_struct(t_flags flags);

int		ft_printf(const char *format, ...);

#endif
