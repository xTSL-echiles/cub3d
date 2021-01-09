/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echiles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 13:25:24 by echiles           #+#    #+#             */
/*   Updated: 2020/11/20 13:25:25 by echiles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_flag_print4(char *s, int n, t_list *heheboy)
{
	int	i;

	i = 0;
	while (i < n)
	{
		s[i] = ' ';
		i++;
		heheboy->bytes++;
	}
	s[i] = '\0';
	return (s);
}

void	ft_check_flag_again4(t_list *heheboy, char *str1)
{
	if (heheboy->flmin == 1)
	{
		ft_putchar_fd(heheboy->d, 1);
		ft_putstr_fd(str1, 1);
		return ;
	}
	if (str1)
	{
		ft_putstr_fd(str1, 1);
		ft_putchar_fd(heheboy->d, 1);
		return ;
	}
	ft_putchar_fd(heheboy->d, 1);
}

void	ft_print_c(t_list *heheboy)
{
	char *str;

	heheboy->d = va_arg(heheboy->ap, int);
	heheboy->bytes++;
	str = malloc(sizeof(char*) * heheboy->width);
	if (str)
		ft_flag_print4(str, heheboy->width - 1, heheboy);
	ft_check_flag_again4(heheboy, str);
}
