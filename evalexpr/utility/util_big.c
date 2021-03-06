/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguinin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/07 18:01:57 by mguinin           #+#    #+#             */
/*   Updated: 2013/08/09 23:26:19 by mguinin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bistromathique.h"
#include "../../includes/const.h"
#include <stdlib.h>

t_big			create_big(int len, int fill_zero)
{
	t_big			res;
	t_ulong		*i;
	t_ulong		*end;

	res = malloc(sizeof(*res));
	res->buf_len = ((len + EXTRA_BUF) | 7) + 1;
	res->data = malloc(res->buf_len + 16) + 8;
	res->len = len;
	res->sgn = 1;
	*(t_ulong*)(res->data - 8) = 0;
	i = (t_ulong*)res->data + (fill_zero ? 0 : (res->len >> 3) - 1);
	end = (t_ulong*)res->data + (res->buf_len >> 3) + 1;
	while (i != end)
	{
		*i = 0;
		i++;
	}
	return (res);
}

t_big			cp_big(t_big x)
{
	int			i;
	t_big		res;
	t_ulong		*xdata;
	t_ulong		*resdata;

	res = create_big(x->len, 0);
	res->sgn = x->sgn;
	i = (x->len >> 3) + 1;
	resdata = (t_ulong*)res->data;
	xdata = (t_ulong*)x->data;
	while (i--) 
	{
		resdata[i] = xdata[i];
	}
	return (res);
}

void		extend_buf(t_big *x)
{
	t_big		tmp;

	tmp = cp_big(*x);
	destruct_big(*x);
	*x = tmp;
}

void			destruct_big(t_big x)
{
	if (x && x != g_zero_big)
	{
		free(x->data - 8);
		free(x);
	}
}

void			adjust_length(t_big x)
{
	while (x->data[x->len])
	{
		x->len++;
	}
	while (x->len && !x->data[x->len - 1])
	{
		x->len--;
	}
}
