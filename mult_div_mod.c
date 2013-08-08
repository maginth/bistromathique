t_big			mult_big(t_big a, t_big b)
{
	t_big		*mult_a;
	t_big		res;

	if (b->len > a->len)
	{
		mult_big(b, a, dest);
	}
	mult_a = create_table(a);
	res = create_big(a->size + b->size + 1, EXTRA_BUF, 1);
	res->sgn = a->sgn * b->sgn;
	mult_data(mult_a, b, res);
	destruct_table(mult_a);
	destruct_big(b);
	adjust_length(res);
	return (res);
}

void			mult_data(t_big *mult_a, t_big b, t_big res)
{
	char			*ib;
	char			*end;
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

t_big      divmod_big(t_big a, t_big b, int wanna_div)
{
	t_big		*mult_b;
	t_big		res;

	res = g_zero_big;
	mult_b = create_table(b);
	if (a->len >= b->len)
	{
		res = create_big(a->len - b->len + 1, 0);
		res->sgn = a->sgn * b->sgn;
		divmod_data(a, mult_b, res);
	}
	destruct_table(mult_b);
	if (!wanna_div)
	{
		destruct_big(res);
		adjust_length(a);
		return (NULL);
	}
	destruct(a);
	adjust_length(res);
	return (res);
}

void      divmod_data(t_big a, t_big *mult_b, t_big res)
{
	t_big		m;
	t_big		b;
	char			*ib;
	char			*end;
	char			quo;
	int					offset;

	b = mult_b[1];
	offset = res->len;
	while (a->len >= b->len)
	{
		quo = a->data[a->len - 1] / mult_b[i]->data[b->len - 1];
		m = get_mult(quo, mult_b); 
		quo -= m && cmp_big(m, a) > 0;
		m = get_mult(quo, mult_b);
		if (m)
		{
			offset_sub(a, m, offset);
		}
		res->data[offset] = quo;
		offset--;
	}
}
