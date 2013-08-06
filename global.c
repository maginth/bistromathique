/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguinin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/05 16:01:00 by mguinin           #+#    #+#             */
/*   Updated: 2013/08/05 20:04:36 by mguinin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "types.h"

uint				g_base;
uint				g_base_n;
ulong				*g_base_n_table;

void				calc_n(ulong base)
{
	ulong			b;

	b = base;
	g_base_n = 0;
	while (!(b * (b >> 32) >> 32))
	{
		b *= base;
		g_base_n++;
	}
}


void				init(ulong base)
{
	uint			i;
	uint			j;
	ulong			b;
	ulong			x;
	ulong			*res;

	g_base = base;
	calc_n(base);
	g_char_to_nbase_table = res = malloc(sizeof(long) * base_size * base_size);
	i = x = 0;
	b = 1;
	while (i++ < g_base_n)
	{
		j = 0;
		while (j++ < base_size)
		{
			*res = x;
			x += b;
			res++;
		}
		b = x;
	}
}
