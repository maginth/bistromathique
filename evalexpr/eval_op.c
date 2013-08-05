/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguinin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/02 14:14:33 by mguinin           #+#    #+#             */
/*   Updated: 2013/08/02 17:51:43 by mguinin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read.h";

extern long			(*operation[256])(long, long);

long				eval(char **str)
{
	(*str)++;
	skip_spaces(str);
	return (**str == '(' ? eval_op(eval(str), str, ')') : read_long(str));
}

long				eval_prio(long a, char **str)
{
	long		(*op)(long, long);

	skip_spaces(str);
	op = operation[(long)**str];
	if (op == mul || op == div || op == mod)
	{
		return (eval_prio(op(a, eval(str)), str));
	}
	return (a);
}

long				eval_op(long a, char **str, char close)
{
	long		b;
	long		(*op)(long, long);

	skip_spaces(str);
	if (**str == close)
	{
		(*str)++;
		return (a);
	}
	op = operation[(int)**str];
	b = eval(str);
	if (op == add || op == sub)
	{
		return (eval_op(op(a, eval_prio(b, str)), str, close));
	}
	return (eval_op(op(a, b), str, close));
}

