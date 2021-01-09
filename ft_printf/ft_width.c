/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echiles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 14:08:41 by echiles           #+#    #+#             */
/*   Updated: 2020/11/20 14:08:42 by echiles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_width(t_list *heheboy)
{
	if (heheboy->fmtt[heheboy->count])
	{
		heheboy->width = ft_atoi(&heheboy->fmtt[heheboy->count]);
		while (heheboy->fmtt[heheboy->count] >= '0'
		&& heheboy->fmtt[heheboy->count] <= '9')
			heheboy->count++;
		if (heheboy->fmtt[heheboy->count] == '*')
		{
			heheboy->width = va_arg(heheboy->ap, int);
			if (heheboy->width < 0)
			{
				heheboy->width = heheboy->width * -1;
				heheboy->flmin = 1;
			}
			heheboy->count++;
		}
	}
}
