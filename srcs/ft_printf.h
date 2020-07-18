/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybesbes <ybesbes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 10:46:11 by ybesbes           #+#    #+#             */
/*   Updated: 2020/07/18 11:49:33 by ybesbes          ###   ########.fr       */
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

typedef struct	s_flags
{
	char *flags;
	char *width;
	char *precision;
	char *length;
	char specifier;
	char c_origine;
}				t_flags;

void			ft_putstr(char *s);
int				ft_strlen(const char *str);
char			*ft_strdup(const char *s);
char			*ft_substr(char const *s, unsigned int start, int len);
int				ft_isdigit(int c);
char			*ft_strchr(char const *s, int c);
int				check_base(char *base);
char			*ft_itoa(long long n, char *base);
int				ft_atoi(const char *nptr);
char			*ft_strjoin(char const *s1, char const *s2);
char			get_specifier(const char *format, int *i);
char			*get_length(const char *format, int *i);
char			*get_width(const char *format, int *i);
char			*get_flags(const char *format, int *i);
t_flags			ft_parse(const char *format, int *i);
int				ft_read_star_parameter(t_flags *flags, char *str, va_list list);
char			*read_specifier(t_flags *flags, va_list list);
char			*read_precision(t_flags flags, char *origine, int star_value, int is_neg);
char			*read_length_and_flags(t_flags flags,
		char *origine, int star_width, int is_neg);
int				ft_parse_read_and_put(const char *format,
		t_flags *flags, int *i, va_list list);
int				ft_read_precision_length_and_flag(t_flags *flags,
		char *precision, int is_neg, int star_width_arg);
char			*ft_format(char *origine, int align, int width, char flag);
int				printf(const char *format, ...);

#endif
