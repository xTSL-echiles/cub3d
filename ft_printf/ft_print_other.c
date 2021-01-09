/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_other.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echiles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 13:36:44 by echiles           #+#    #+#             */
/*   Updated: 2020/11/20 13:36:45 by echiles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_other(t_list *heheboy)
{
	while (heheboy->fmtt[heheboy->count] != '\0')
	{
		if (heheboy->fmtt[heheboy->count] == '%')
		{
			heheboy->count++;
			ft_flag_check(heheboy);
			ft_width(heheboy);
			ft_per(heheboy);
			if (!(ft_pars_check(heheboy)) && !(heheboy->fmtt[heheboy->count]))
				return ;
		}
		else
		{
			ft_putchar_fd(heheboy->fmtt[heheboy->count], 1);
			heheboy->bytes++;
		}
		heheboy->count++;
	}
}
