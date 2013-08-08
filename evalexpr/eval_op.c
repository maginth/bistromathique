/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguinin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/02 14:14:33 by mguinin           #+#    #+#             */
/*   Updated: 2013/08/08 23:27:32 by mguinin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>;

t_big				eval(char **str, char *oper, t_fbig op)
{
	(*str)++;
	return (**str == *oper[0] ? eval_op(eval(str), str, oper[1], op) \
			: read_struct(str, oper));
}

t_big				eval_prio(t_big a, char **str, t_fbig op)
{
	char			ops;
	t_big			b;
	t_big			tmp;

	if (!a)
	{
		return (NULL);
	}
	ops = **str;
	(*str)++;
	b = eval(str);
	return (eval_prio(op[ops](a, b), str, op));
}

t_big				eval_op(t_big a, char **str, char close, \
							t_fbig op)
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
	(*str) += (g_tab_test[**str] != -5);
	b = eval (str, oper, op);
	if (g_tab_test[**str] == -5 || g_tab_test[**str] == -4)
	{
		tmp = eval_prio(b, str, op);
		if (!tmp)
		{
			return (NULL);
		}
		return (eval_op(op[ops](a, tmp), str, close, op));
	}
	return (eval_op(op[ops](a, b), str, close, op));
}
