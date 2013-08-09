/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguinin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/02 14:14:33 by mguinin           #+#    #+#             */
/*   Updated: 2013/08/09 21:48:14 by mguinin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/bistromathique.h"
#include "../includes/const.h"

t_elem		parse(char **str)
{
	t_elem		res;
	int			sgn;

	sgn = read_sgn(str);
	if (**str == g_bra)
	{
		(*str)++;
		res = parse_op(parse(str), str, g_ket);
	}
	else
	{
		res = parse_digit(str);
	}
	if (res)
	{
		res->sgn = sgn;
	}
	return (res);
}

t_elem		parse_prio(t_elem a, char **str, char close)
{
	t_fbig			op;
	t_elem			b;

	op = g_op[(int)(**str)];
	if (op)
	{
		if (op == add_big)
		{
			return (a);
		}
		(*str)++;
		b = parse(str);
		if (b)
		{
			return (parse_prio(create_elem(a, b, op), str, close));
		}
	}
	return (**str == close ? a : NULL);
}

t_elem		parse_op(t_elem a, char **str, char close)
{
	t_elem			b;
	t_fbig			op;

	if (**str == close)
	{
		(*str)++;
		return (a);
	}
	op = g_op[(int)**str];
	if (op)
	{
		(*str) += op != add_big;
		b = parse(str);
		if (b)
		{
			b = (op == add_big) ? parse_prio(b, str, close) : b;
			return (b ? parse_op(create_elem(a, b, op), str, close) : NULL);
		}
	}
	return (NULL);
}
