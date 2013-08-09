/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguinin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/02 14:14:33 by mguinin           #+#    #+#             */
/*   Updated: 2013/08/09 12:20:57 by ybouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/bistromathique.h"
#include "../includes/const.h"

t_big               eval(char **str, t_fbig *op)
{
	(*str)++;
	return (**str == g_oper[0] ? eval_op(eval(str, op), str, g_oper[1], op) \
			: read_struct(str));
}

t_big				eval_prio(t_big a, char **str, t_fbig *op)
{
	char			ops;
	t_big			b;

	if (!a)
	{
		return (NULL);
	}
	ops = **str;
	(*str)++;
	b = eval(str, op);
	return (eval_prio(op[(int)ops](a, b), str, op));
}

t_big				eval_op(t_big a, char **str, char close, \
							t_fbig *op)
{
	t_big			b;
	char			ops;
	t_big			tmp;

	if (!a || **str == close)
	{
		(*str)++;
		return (a);
	}
	ops = **str;
	(*str) += (g_tab_test[(int)**str] != -5);
	b = eval (str, op);
	if (g_tab_test[(int)**str] == MINUS || g_tab_test[(int)**str] == PLUS)
	{
		tmp = eval_prio(b, str, op);
		if (!tmp)
		{
			return (NULL);
		}
		return (eval_op(op[(int)ops](a, tmp), str, close, op));
	}
	return (eval_op(op[(int)ops](a, b), str, close, op));
}
