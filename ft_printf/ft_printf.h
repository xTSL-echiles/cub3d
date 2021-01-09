/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echiles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 14:06:16 by echiles           #+#    #+#             */
/*   Updated: 2020/11/20 14:06:17 by echiles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef	struct				s_list
{
	char					*s;
	int						d;
	va_list					ap;
	unsigned int			u;
	unsigned long long int	p;
	int						width;
	int						per;
	const char				*fmtt;
	int						count;
	char					*s1;
	int						itoa;
	int						flmin;
	int						zero;
	int						bytes;

}							t_list;

int							ft_printf(char *fmt, ...);
char						*ft_itoa_base_p(unsigned long long int value,
							int base);
char						ft_tolower1(char *c);
char						*ft_itoa_base_x(unsigned int value, int base);
void						ft_print_other(t_list *heheboy);
void						ft_print_di(t_list *heheboy);
int							ft_pars_check(t_list *heheboy);
void						ft_print_s(t_list *heheboy);
void						ft_print_u(t_list *heheboy);
void						ft_print_p(t_list *heheboy);
void						ft_print_x(t_list *heheboy);
void						ft_print_xx(t_list *heheboy);
void						ft_print_c(t_list *heheboy);
void						ft_width(t_list *heheboy);
void						ft_flag_check(t_list *heheboy);
void						ft_per(t_list *heheboy);
void						ft_print_perc(t_list *heheboy);

#endif
