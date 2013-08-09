/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mult.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguinin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/08 20:37:21 by mguinin           #+#    #+#             */
/*   Updated: 2013/08/09 12:14:43 by mguinin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bistromathique.h"

t_big			mult_big(t_big a, t_big b)
{
	t_big		*mult_a;
	t_big		res;

	if (b->len > a->len)
	{
		mult_big(b, a, dest);
	}
	if (b->len == 0)
	{
		return (g_zero_big);
	}
	mult_a = create_table(a);
	res = create_big(a->len + b->len + 1, 1);
	res->sgn = a->sgn * b->sgn;
	mult_data(mult_a, b, res);
	destruct_table(mult_a);
	destruct_big(b);
	adjust_length(res);
	return (res);
}

void			mult_data(t_big *mult_a, t_big b, t_big res)
{
	t_uchar			*ib;
	t_uchar			*end;
	int				offset;

	offset = 0;
	ib = dest->data;
	end = ib->end;
	while (ib != end)
	{
		if (*ib)
		{
			offset_add(res, get_mult(*ib, a_mult), offset);
		}
		ib++;
		offset++;
	}
}
