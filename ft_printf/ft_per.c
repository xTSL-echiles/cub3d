/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_per.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echiles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 13:20:08 by echiles           #+#    #+#             */
/*   Updated: 2020/11/20 13:22:33 by echiles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_per(t_list *heheboy)
{
	if (heheboy->fmtt[heheboy->count])
	{
		heheboy->per = -1;
		if (heheboy->fmtt[heheboy->count] == '.')
		{
			heheboy->count++;
			heheboy->per = ft_atoi(&heheboy->fmtt[heheboy->count]);
			while (heheboy->fmtt[heheboy->count] >= '0' &&
					heheboy->fmtt[heheboy->count] <= '9')
				heheboy->count++;
			if (heheboy->fmtt[heheboy->count] == '*')
			{
				heheboy->per = va_arg(heheboy->ap, int);
				if (heheboy->per < 0)
					heheboy->per = -1;
				heheboy->count++;
			}
		}
	}
}
