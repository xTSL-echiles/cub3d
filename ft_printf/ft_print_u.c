/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echiles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 13:55:52 by echiles           #+#    #+#             */
/*   Updated: 2020/11/20 13:55:53 by echiles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_toch3(t_list *heheboy)
{
	char	*perr;
	int		i;
	int		n;

	i = 0;
	if (heheboy->per > heheboy->itoa)
	{
		perr = malloc(sizeof(char*) * (heheboy->per - heheboy->itoa));
		n = heheboy->per - heheboy->itoa;
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

void	*ft_flag_print3(char *s, int n, t_list *heheboy)
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

void	ft_check_flag_again3(t_list *heheboy, char *str1)
{
	if (heheboy->flmin == 1)
	{
		ft_check_toch3(heheboy);
		ft_putstr_fd(heheboy->s1, 1);
		ft_putstr_fd(str1, 1);
		return ;
	}
	if ((heheboy->width > heheboy->per && heheboy->zero == 0)
	|| heheboy->zero == 1)
	{
		ft_putstr_fd(str1, 1);
		ft_check_toch3(heheboy);
		ft_putstr_fd(heheboy->s1, 1);
		return ;
	}
	ft_putstr_fd(str1, 1);
	ft_check_toch3(heheboy);
	ft_putstr_fd(heheboy->s1, 1);
}

int		ft_null_happened3(t_list *heheboy)
{
	int j;

	j = 0;
	if (heheboy->per == 0 && heheboy->u == 0)
	{
		while (j < heheboy->width)
		{
			ft_putchar_fd(' ', 1);
			j++;
			heheboy->bytes++;
		}
		return (1);
	}
	return (0);
}

void	ft_print_u(t_list *heheboy)
{
	char	*str;
	int		i;

	heheboy->u = va_arg(heheboy->ap, unsigned int);
	if (ft_null_happened3(heheboy))
		return ;
	heheboy->s1 = ft_itoa(heheboy->u);
	heheboy->itoa = ft_strlen(heheboy->s1);
	heheboy->bytes = heheboy->bytes + heheboy->itoa;
	i = ((heheboy->per < heheboy->itoa) ? heheboy->itoa : heheboy->per);
	str = malloc(sizeof(char*) * (heheboy->width - i + 1));
	if (heheboy->per > heheboy->itoa && heheboy->d < 0)
		i++;
	if (str)
		ft_flag_print3(str, heheboy->width - i, heheboy);
	ft_check_flag_again3(heheboy, str);
	free(str);
	free(heheboy->s1);
}
