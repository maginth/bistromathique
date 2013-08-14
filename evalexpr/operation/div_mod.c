/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   div_mod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguinin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/08 19:51:37 by mguinin           #+#    #+#             */
/*   Updated: 2013/08/09 12:46:20 by mguinin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bistromathique.h"
#include "../../includes/const.h"
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

t_uchar		calc_digit(t_uchar *lead_a, int lead_b)
{
	int	digit;

	digit = ((lead_a[2] * g_base + lead_a[1]) * g_base
		+ *lead_a + 1) / lead_b;
	return (digit >= g_base ? digit - 1 : digit);
}


void		divmod_data(t_big a, t_big *mult_b, t_big res)
{
	t_big		m;
	t_uchar		digit;
	int			offset;
	t_uchar		*lead_a;
	int			lead_b;

	lead_a = mult_b[1]->data + mult_b[1]->len - 2;
	lead_b = lead_a[1] * g_base + lead_a[0];
	offset = res->len;
	lead_a = (t_uchar*)(a->data + a->len - 2);
	while (offset--)
	{
		if ((digit = calc_digit(lead_a--, lead_b)))
		{
			m = get_mult(digit, mult_b);
			digit -= cmp_big(a, m, offset) < 0;
			if (digit)
			{
				m = get_mult(digit, mult_b);
				offset_sub(a, m, offset);
				adjust_length(a);
			}
		}
		res->data[offset] = digit;
	}
}
