/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguinin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/07 12:49:24 by mguinin           #+#    #+#             */
/*   Updated: 2013/08/07 18:00:47 by mguinin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_big_char      *prepare_for_add(t_big_char a)
{
	long		*la;
	long		*end;

	la = (long*)a->data;
	end = la + (a->len >> 3) + 1;
	while (la != end)
	{
		*la += g_comp_8;
		la++;
	}
	return (a);
}

t_big_char      *prepare_for_sub(t_big_char a)
{
	long		*la;
	long		*end;

	la = (long*)a->data;
	end = la + (a->len >> 3) + 1;
	while (la != end)
	{
		*la = ~(*la) + MIN_BITS;
		la++;
	}
	return (a);
}

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
	ret = 0;
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

t_big_char	   	  *char_mult(char c, t_big_char x, t_big_char *res)
{
	if (!res[c])
	{
		res[c] = add_big_char(cp_big_char(char_mult((c >> 1) + (c & 1), x, res),
								char_mult(c, x, res)), 0);
	}
	return (res[c]);
}

void			*mult_big_char(t_big_char a, t_big_char b, t_big_char dest)
{
	t_big_char		res_mult[128];
	char			*ib;
	char			*end;
	int				offset;

	if (b->len > a->len)
	{
		mult_big_char(b, a, dest);
	}
	offset = 0;
	ib = dest->data;
	end = ib->end;
	res_mult[1] = a;
	while (ib != end)
	{
		if (*ib)
		{
			add_big_char(dest, char_mult_big_char(*ib, a, res_mult), offset);
		}
		ib++;
		offset++;
	}
}
/*
**	a must be same size or greater than b
*/
long			cmp_for_div(t_big_char a, t_big_char b)
{
	long		*ia;
	long		*ib;
	long		*end;

	ia = (long*)(a->data + a->len - 9);
	ib = (long*)(b->data + b->len - 9);
	end = ib - (b->len >> 3) - 1;
	while (ib != end && *ia == *ib)
	{
		ia--;
		ib--;
	}
	return (*ia - *ib);
}

t_big_char      *divmod_big_char(t_big_char a, t_big_char b, int wanna_div)
{
	t_big_char		res_mult[128];
	t_big_char		m;
	t_big_char		res;
	char			*ib;
	char			*end;
	int				quo;
	int				sgn;

	sgn = a->sgn * b->sgn;
	a->sgn = b->sgn = 1;
	res_mult[1] = b;
	if (wanna_div)
	{
		res = create_big_char(a->len - b->len);
		res->data += res->len;
		res->len = 0;
	}
	while (a->len >= b->len)
	{
		quo = a->data[a->len - 1] / b->data[b->len - 1];
		m = char_mult(quo); 
		quo -= m && cmp_for_div(m, a) > 0;
		m = char_mult(quo);
		if (m)
		{
			add_big_char(a, m, offset);
		}
		if (wanna_div)
		{
			*(--res->data) = quo;
			res->len++;
		}
		a->len--;
		offset--;
	}
}
