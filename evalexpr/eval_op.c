/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguinin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/02 14:14:33 by mguinin           #+#    #+#             */
/*   Updated: 2013/08/08 17:55:20 by ybouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read.h";

t_big_char			*eval(char **str, char **oper)
{
	(*str)++;
	return (**str == *oper[0] ? eval_op(eval(str), str, *oper[1], oper) \
			: read_struct(str, oper));
}

t_big_char			*eval_prio(t_big_char *a, char **str, char **oper)
{
	char			ops;

	ops = **str;
	(*str)++;
	if (ops == *oper[4] || ops == *oper[5] || ops == *oper[6])
	{
		return (eval_prio(mult_big_char(a, eval(str)), str, oper);
	}
	return (a);
}

t_big_char			*eval_op(t_big_char *a, char **str, char close, \
							char **oper)
{
	t_big_char		*b;
	char			ops;

	if (**str == close)
	{
		(*str)++;
		return (a);
	}
	ops = **str;
	if (ops != *oper[3])
	{
		(*str)++;
	}
	b = eval(str);
	if (ops == *oper[2] || ops == *oper[3])
	{
		return (eval_op(add_big_char(a, eval_prio(b, str, oper)),	\
						str, close, oper));
	}
	return (eval_op(mult_big_char(a, b), str, close, oper));
}
