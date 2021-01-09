/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echiles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 13:13:01 by echiles           #+#    #+#             */
/*   Updated: 2020/11/20 13:13:54 by echiles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flag_check(t_list *heheboy)
{
	if (heheboy->fmtt[heheboy->count])
	{
		while (heheboy->fmtt[heheboy->count] == '-' ||
				heheboy->fmtt[heheboy->count] == '0')
		{
			if (heheboy->fmtt[heheboy->count] == '-')
				heheboy->flmin = 1;
			if (heheboy->fmtt[heheboy->count] == '0')
				heheboy->zero = 1;
			heheboy->count++;
		}
	}
}
