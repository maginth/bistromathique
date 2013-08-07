/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguinin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/07 12:49:24 by mguinin           #+#    #+#             */
/*   Updated: 2013/08/07 14:58:15 by mguinin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
/*
	coupl = tab + *a + *b + ret;
	res = coupl->digit;
	ret = coupl->ret;
	a++;
	b++;
*/
/*
t_big_char      *char_mult_big_char(char c, t_big_char x)
{
	char			*ix;
	t_big_char		*res;
	char			*ires;
	char			*end;
	t_div_mod		*coupl;
	char			*tab;
	char			ret;
	
	res = create_big_char(x->len + 1);
	ires = res->data;
	ires[x->len] = 0;
	ix = x->data;
	tab = x->sgn == 1 ? g_mult_tab : g_div_tab;
	while (res != end)
	{
		coupl = tab[*ix * c + coupl->ret];
		*ires = coupl->digit;
		ires++;
		data++;
	}
	return (res);
}
*/

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
			if (!res_mult[*ib])
			{
				res_mult[*ib] = char_mult_big_char(*ib, a);
			}
			add_big_char(dest, res_mult[*ib], offset);
		}
		ib++;
		offset++;
	}
}

int				cmp_for_div(t_big_char num, t_big_char denum)
{
	long		*ia;
	long		*ib;
	long		*end;

	ia = (long*)(a->data + a->len - 9);
	ib = (long*)(b->data + b->len - 9);
	end = (
	while 

t_big_char      *divmod_big_char(t_big_char a, t_big_char b, int wanna_div)
{
	
