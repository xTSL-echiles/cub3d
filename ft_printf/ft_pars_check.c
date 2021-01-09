/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echiles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 13:16:43 by echiles           #+#    #+#             */
/*   Updated: 2020/11/20 13:17:01 by echiles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_pars_check(t_list *heheboy)
{
	if (heheboy->fmtt[heheboy->count] == 'i' ||
			heheboy->fmtt[heheboy->count] == 'd')
		ft_print_di(heheboy);
	if (heheboy->fmtt[heheboy->count] == 's')
		ft_print_s(heheboy);
	if (heheboy->fmtt[heheboy->count] == 'u')
		ft_print_u(heheboy);
	if (heheboy->fmtt[heheboy->count] == 'p')
		ft_print_p(heheboy);
	if (heheboy->fmtt[heheboy->count] == 'x')
		ft_print_x(heheboy);
	if (heheboy->fmtt[heheboy->count] == 'X')
		ft_print_xx(heheboy);
	if (heheboy->fmtt[heheboy->count] == 'c')
		ft_print_c(heheboy);
	if (heheboy->fmtt[heheboy->count] == '%')
		ft_print_perc(heheboy);
	return (0);
}
