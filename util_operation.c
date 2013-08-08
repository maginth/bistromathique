t_big			*create_table(t_big x)
{
	t_big		*res;
	int			i;

	res = malloc(sizeof(*res) * g_base);
	i = g_base;
	while (i--)
	{
		res[i] = NULL;
	}
	res[1] = x;
	return (res);
}

void			destruct_table(t_big *table)
{
	int			i;

	i = g_base;
	while (--i)
	{
		destruct_big(mult_a[i]);
	}
}

t_big	   	  get_mult(char c, t_big *table)
{
	if (!table[c])
	{
		table[c] = offset_add(cp_big(get_mult((c >> 1) + (c & 1), table),
								get_mult(c >> 1, table)), 0);
	}
	return (table[c]);
}

/*
**	a must be same size or greater than b
*/
long			cmp_big(t_big a, t_big b, int offset)
{
	long		*ia;
	long		*ib;
	long		*end;
	long		res;

	res = a->len - b->len - offset;
	if (res == 0)
	{
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
	return (res);
}
