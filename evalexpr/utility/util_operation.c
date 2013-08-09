/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguinin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/08 19:56:31 by mguinin           #+#    #+#             */
/*   Updated: 2013/08/09 13:20:51 by mguinin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bistromathique.h"
#include "../../includes/const.h"
#include <stdlib.h>

t_big			*create_table(t_big x)
{
	t_big		*res;
	int			i;

	res = malloc(sizeof(*res) * g_base);
	i = g_base;
	while (i--)
	{
		res[i] = NULL;
	}
	res[1] = x;
	return (res);
}

void			destruct_table(t_big *table)
{
	int			i;

	i = g_base;
	while (--i)
	{
		destruct_big(table[i]);
	}
}

t_big	   	  get_mult(t_uchar c, t_big *table)
{
	t_big		half;

	half = cp_big(get_mult((c >> 1) + (c & 1), table)); 
	if (!table[c])
	{
		offset_add(half, get_mult(c >> 1, table), 0);
		table[c] = half; 
	}
	return (half);
}

int				cmp_big(t_big a, t_big b, int offset)
{
	t_ulong		*ia;
	t_ulong		*ib;
	t_ulong		*end;
	t_ulong		res;

	res = a->len - b->len - offset;
	if (res == 0)
	{
		ia = (t_ulong*)(a->data + a->len) - 1;
		ib = (t_ulong*)(b->data + b->len) - 1;
		end = ib - ((b->len + 7) >> 3);
		while (ib != end && *ia == *ib)
		{
			ia--;
			ib--;
		}
		return (*ia - *ib);
	}
	return (res);
}
