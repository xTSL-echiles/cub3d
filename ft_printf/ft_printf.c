/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echiles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 14:04:52 by echiles           #+#    #+#             */
/*   Updated: 2020/11/20 14:04:54 by echiles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char *fmt, ...)
{
	t_list *heheboy;

	heheboy = (t_list*)malloc(sizeof(t_list));
	heheboy->fmtt = fmt;
	heheboy->count = 0;
	heheboy->bytes = 0;
	va_start(heheboy->ap, fmt);
	ft_print_other(heheboy);
	va_end(heheboy->ap);
	free(heheboy);
	return (heheboy->bytes);
}

int	main()
{
	while(1)
	ft_printf("%0-10.4d, %10s", 10, "Hello");
}