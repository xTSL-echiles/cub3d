/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echiles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 13:44:26 by echiles           #+#    #+#             */
/*   Updated: 2020/11/20 13:44:28 by echiles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_toch6(t_list *heheboy)
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

void	*ft_flag_print6(char *s, int n, t_list *heheboy)
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

void	ft_check_flag_again6(t_list *heheboy, char *str1)
{
	if (heheboy->flmin == 1)
	{
		ft_putstr_fd("0x", 1);
		ft_check_toch6(heheboy);
		ft_putstr_fd(heheboy->s1, 1);
		ft_putstr_fd(str1, 1);
		return ;
	}
	if (str1)
	{
		ft_putstr_fd(str1, 1);
		ft_putstr_fd("0x", 1);
		ft_check_toch6(heheboy);
		ft_putstr_fd(heheboy->s1, 1);
		return ;
	}
	ft_putstr_fd("0x", 1);
	ft_check_toch6(heheboy);
	ft_putstr_fd(heheboy->s1, 1);
}

int		ft_null_happened6(t_list *heheboy)
{
	int j;

	j = 0;
	if (heheboy->per == 0 && heheboy->d == 0)
	{
		heheboy->bytes = heheboy->bytes + 2;
		while (j < heheboy->width - 2)
		{
			ft_putchar_fd(' ', 1);
			heheboy->bytes++;
			j++;
		}
		ft_putstr_fd("0x", 1);
		return (1);
	}
	return (0);
}

void	ft_print_p(t_list *heheboy)
{
	char	*str;
	int		i;

	heheboy->p = va_arg(heheboy->ap, unsigned long long int);
	if (ft_null_happened6(heheboy))
		return ;
	heheboy->s1 = ft_itoa_base_p(heheboy->p, 16);
	heheboy->itoa = ft_strlen(heheboy->s1);
	heheboy->bytes = heheboy->bytes + heheboy->itoa + 2;
	i = (heheboy->per < heheboy->itoa ? heheboy->itoa + 2 : heheboy->per);
	str = malloc(sizeof(char*) * (heheboy->width - i));
	if (str)
		ft_flag_print6(str, (heheboy->width - i), heheboy);
	ft_check_flag_again6(heheboy, str);
	free(str);
	free(heheboy->s1);
}
