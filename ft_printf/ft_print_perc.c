/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_perc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echiles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 13:46:49 by echiles           #+#    #+#             */
/*   Updated: 2020/11/20 13:46:50 by echiles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_flag_print7(char *s, int n, t_list *heheboy)
{
	int	i;

	i = 0;
	if (heheboy->zero == 1 && heheboy->flmin == 0)
	{
		while (i < n)
		{
			s[i] = '0';
			i++;
		}
	}
	else
	{
		while (i < n)
		{
			s[i] = ' ';
			i++;
		}
	}
	heheboy->bytes = heheboy->bytes + i;
	s[i] = '\0';
	return (s);
}

void	ft_check_flag_again7(t_list *heheboy, char *str1)
{
	if (heheboy->flmin == 1)
	{
		ft_putchar_fd('%', 1);
		ft_putstr_fd(str1, 1);
		return ;
	}
	ft_putstr_fd(str1, 1);
	ft_putchar_fd('%', 1);
}

void	ft_print_perc(t_list *heheboy)
{
	char *str;

	heheboy->bytes++;
	str = malloc(sizeof(char*) * (heheboy->width - 1));
	if (str)
		ft_flag_print7(str, heheboy->width - 1, heheboy);
	ft_check_flag_again7(heheboy, str);
	free(str);
}
