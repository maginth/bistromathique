/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguinin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/07 18:01:57 by mguinin           #+#    #+#             */
/*   Updated: 2013/08/09 12:23:42 by mguinin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bistromatique.h"
#include <unistd.h>

t_big		create_big(int len, int fill_zero)
{
	t_big			res;
	long			*i;
	long			*end;

	res = malloc(sizeof(*res));
	res->buf_len = ((len + EXTRA_BUF) | 7) + 1;
	res->data = 8 + malloc(res->buf_len + 16);
	res->len = len;
	res->sgn = 1;
	*(long*)(res->data - 8) = 0;
	i = (long*)res->data + (fill_zero ? 0 : (res->len >> 3) - 1);
	end = (long*)res->data + res->buf_len + 1;
	while (i != end)
	{
		*i = 0;
		i++;
	}
	return (res);
}

void		extend_buf(t_big *x)
{
	int			*i;
	t_big		res;
	t_ulong		*xdata;
	t_ulong		*resdata;

	res = create_big((*x)->len, 0);
	res->sgn = (*x)->sgn;
	i = ((*x)->len >> 3) + 1;
	resdata = (t_ulong*)res->data;
	xdata = (t_ulong*)(*x)->data;
	while (i--) 
	{
		resdata[i] = xdata[i];
	}
	destruct_big(*x);
	return (res)
}
	
void			destruct_big(t_big *x)
{
	if (x && x != g_zero_big)
	{
		free(x->data - 8);
		free(x);
	}
}

void			ajust_length(t_big x)
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
