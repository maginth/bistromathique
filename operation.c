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
