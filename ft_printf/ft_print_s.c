/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echiles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 13:52:03 by echiles           #+#    #+#             */
/*   Updated: 2020/11/20 13:52:05 by echiles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_flag_print5(char *s, int n, t_list *heheboy)
{
	int	i;

	i = 0;
	if (heheboy->zero == 1 && heheboy->flmin == 0
			&& heheboy->per == -1)
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
	s[i] = '\0';
	return (s);
}

char	*ft_per_cut(t_list *heheboy)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc(sizeof(char*) * (heheboy->per + 1));
	while (i < (heheboy->per))
	{
		str[i] = heheboy->s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

void	ft_print_all(t_list *heheboy, char *str)
{
	if (heheboy->flmin == 1)
	{
		heheboy->bytes = heheboy->bytes + ft_putstr_fd(heheboy->s, 1);
		heheboy->bytes = heheboy->bytes + ft_putstr_fd(str, 1);
	}
	else
	{
		heheboy->bytes = heheboy->bytes + ft_putstr_fd(str, 1);
		heheboy->bytes = heheboy->bytes + ft_putstr_fd(heheboy->s, 1);
	}
}

int		ft_null_hap(t_list *heheboy)
{
	int i;

	i = 0;
	if (heheboy->per == 0)
	{
		while (i < heheboy->width)
		{
			ft_putchar_fd(' ', 1);
			i++;
		}
		heheboy->bytes = heheboy->bytes + i;
		return (1);
	}
	return (0);
}

void	ft_print_s(t_list *heheboy)
{
	char *str;

	if (ft_null_hap(heheboy))
		return ;
	heheboy->s = va_arg(heheboy->ap, char*);
	if (heheboy->s == NULL)
		heheboy->s = "(null)";
	heheboy->itoa = ft_strlen(heheboy->s);
	if (heheboy->itoa > heheboy->per && heheboy->per != -1)
	{
		heheboy->s = ft_per_cut(heheboy);
		heheboy->itoa = ft_strlen(heheboy->s);
	}
	str = malloc(sizeof(char*) * (heheboy->width - heheboy->itoa + 1));
	if (str)
		ft_flag_print5(str, heheboy->width - heheboy->itoa, heheboy);
	ft_print_all(heheboy, str);
	free(str);
}
