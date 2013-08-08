/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   div_mod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguinin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/08 19:51:37 by mguinin           #+#    #+#             */
/*   Updated: 2013/08/08 22:45:28 by mguinin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistro.h"
#include <stdlib.h>

t_big		div_big(t_big a, t_big b)
{
	t_big		res;

	if (b->len == 0)
	{
		return (NULL);
	}
	res = divmod_big(a, b);
	adjust_length(res);
	destruct_big(a);
	return (res);
}

t_big		mod_big(t_big a, t_big b)
{
	if (b->len == 0)
	{
		return (NULL);
	}
	destruct_big(divmod_big(a, b));
	adjust_length(a);
	return (a);
}

t_big		divmod_big(t_big a, t_big b)
{
	t_big		*mult_b;
	t_big		res;

	if (a->len >= b->len)
	{
		mult_b = create_table(b);
		res = create_big(a->len - b->len + 1, 0);
		res->sgn = a->sgn * b->sgn;
		divmod_data(a, mult_b, res);
		destruct_table(mult_b);
		return (res);
	}
	return (g_zero_big);
}

void      divmod_data(t_big a, t_big *mult_b, t_big res)
{
	t_big		m;
	uchar		digit;
	int			offset;
	int			*lead_a;
	int			inv_lead_b;

	inv_lead_b = 0x10000 / mult_b[1]->data[mult_b[1]->len - 1];
	offset = res->len;
	lead_a = (int*)(a->data + a->len - 1);
	while (offset--)
	{
		digit = (*lead_a * inv_lead_b) >> 16;
		if (digit)
		{
			m = get_mult(digit, mult_b); 
			digit -= cmp_big(m, a) > 0;
			if (digit)
			{
				m = get_mult(digit, mult_b);
				offset_sub(a, m, offset);
			}
		}
		res->data[offset] = digit;
		lead_a--;
	}
}
