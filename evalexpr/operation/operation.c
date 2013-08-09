/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouvet <yann.bouvet@voila.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/09 10:43:15 by ybouvet           #+#    #+#             */
/*   Updated: 2013/08/09 11:12:35 by ybouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bistromathique.h"
#include "../../includes/const.h"

t_big_char		*add_big_char(t_big_char a, t_big_char b, int offset)
{
	long		*la;
	long		*lb;
	long		ret;
	
	la = (long*)(a->data + offset);
	lb = (long*)b->data;
	end = lb + (b->len >> 3);
	if (!b->ready_to_add)
	{
		prepare_to_add(b);
	}
	ret
	while (lb != end)
	{
		res = *la + *lb + ret;
		ret = res >> 63;
		*la = res - ((res & RET_BITS)>>7) * g_compl;
		la++;
		lb++;
	}
	return (a);
}
/*
	coupl = tab + *a + *b + ret;
	res = coupl->digit;
	ret = coupl->ret;
	a++;
	b++;
*/
