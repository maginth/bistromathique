/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_sub.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguinin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/07 12:49:24 by mguinin           #+#    #+#             */
/*   Updated: 2013/08/09 23:33:42 by mguinin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bistromathique.h"
#include "../../includes/const.h"

t_big		add_big(t_big a, t_big b)
{
	if (a->len < b->len 
		|| (a->len == b->len 
			&& a->sgn != b->sgn
			&& cmp_big(a, b, 0) < 0))
	{
		return (add_big(b, a));
	}
	if (a->sgn == b->sgn && a->buf_len <= a->len)
	{
		extend_buf(&a);
	}
	(a->sgn == b->sgn ? offset_add : offset_sub)(a, b, 0);
	destruct_big(b);
	adjust_length(a);
	return (a);
}		

void			offset_add(t_big a, t_big b, int offset)
{
	add_data((t_ulong*)(a->data + offset), (t_ulong*)b->data, L_END(b));
}

void			offset_sub(t_big a, t_big b, int offset)
{
	sub_data((t_ulong*)(a->data + offset), (t_ulong*)b->data, L_END(b));
}

void			add_data(t_ulong *la, t_ulong *lb, t_ulong *lb_end)
{
	t_ulong		ret;
	t_ulong		res;
	
	ret = 0;
	while (lb != lb_end)
	{
		res = *la + *lb + g_compl_8 + ret;
		ret = ~res >> 63;
		*la = res - ((res & RET_BITS)>>7) * g_compl;
		la++;
		lb++;
	}
	while (ret)
	{
		res = *la + g_compl_8 + ret;
		ret = ~res >> 63;
		*la = res - ((res & RET_BITS)>>7) * g_compl;
		la++;
	}
}

void			sub_data(t_ulong *la, t_ulong *lb, t_ulong *lb_end)
{
	t_ulong		ret;
	t_ulong		res;
	
	ret = 1;
	while (lb != lb_end)
	{
		res = *la + ~*lb + ret;
		ret = ~res >> 63;
		*la = res - ((res & RET_BITS)>>7) * g_compl;
		la++;
		lb++;
	}
	while (!ret)
	{
		res = *la - 1;
		ret = ~res >> 63;
		*la = res - ((res & RET_BITS)>>7) * g_compl;
		la++;
	}
}
