/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_di.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echiles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 14:42:06 by echiles           #+#    #+#             */
/*   Updated: 2020/11/20 14:42:08 by echiles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_toch(t_list *heheboy)
{
	char	*perr;
	int		i;
	int		n;

	i = 0;
	if (heheboy->per > heheboy->itoa)
	{
		perr = malloc(sizeof(char*) *
		(heheboy->per - heheboy->itoa + (heheboy->d < 0 ? 1 : 0)));
		n = heheboy->per - heheboy->itoa + (heheboy->d < 0 ? 1 : 0);
		while (i < n)
		{
			perr[i] = '0';
			ft_putchar_fd(perr[i], 1);
			i++;
			heheboy->bytes++;
		}
		free(perr);
	}
}

void	*ft_flag_print(char *s, int n, t_list *heheboy)
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
	heheboy->bytes = heheboy->bytes + i;
	s[i] = '\0';
	return (s);
}

void	ft_check_flag_again(t_list *heheboy, char *str1)
{
	if (heheboy->flmin == 1)
	{
		heheboy->d < 0 ? ft_putchar_fd('-', 1) : 0;
		ft_check_toch(heheboy);
		ft_putnbr_fd(heheboy->d, 1);
		ft_putstr_fd(str1, 1);
		return ;
	}
	if (heheboy->width > heheboy->per)
	{
		if (heheboy->zero == 1 && heheboy->per == -1 && heheboy->flmin == 0)
			heheboy->d < 0 ? ft_putchar_fd('-', 1) : 0;
		ft_putstr_fd(str1, 1);
		if (heheboy->zero != 1 || heheboy->per != -1 || heheboy->flmin != 0)
			heheboy->d < 0 ? ft_putchar_fd('-', 1) : 0;
		ft_check_toch(heheboy);
		ft_putnbr_fd(heheboy->d, 1);
		return ;
	}
	heheboy->d < 0 ? ft_putchar_fd('-', 1) : 0;
	ft_putstr_fd(str1, 1);
	ft_check_toch(heheboy);
	ft_putnbr_fd(heheboy->d, 1);
}

int		ft_null_happened(t_list *heheboy)
{
	int j;

	j = 0;
	if (heheboy->per == 0 && heheboy->d == 0)
	{
		while (j < heheboy->width)
		{
			ft_putchar_fd(' ', 1);
			heheboy->bytes++;
			j++;
		}
		return (1);
	}
	return (0);
}

void	ft_print_di(t_list *heheboy)
{
	char	*str;
	int		i;

	heheboy->d = va_arg(heheboy->ap, int);
	if (ft_null_happened(heheboy))
		return ;
	heheboy->s1 = ft_itoa(heheboy->d);
	heheboy->itoa = ft_strlen(heheboy->s1);
	heheboy->bytes = heheboy->bytes + heheboy->itoa;
	i = (heheboy->per < heheboy->itoa ? heheboy->itoa : heheboy->per);
	str = malloc(sizeof(char*) * (heheboy->width - i));
	if (heheboy->per > heheboy->itoa && heheboy->d < 0)
		i++;
	if (str)
		ft_flag_print(str, heheboy->width - i, heheboy);
	ft_check_flag_again(heheboy, str);
	free(str);
	free(heheboy->s1);
}
