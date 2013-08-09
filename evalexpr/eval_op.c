/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguinin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/02 14:14:33 by mguinin           #+#    #+#             */
/*   Updated: 2013/08/09 14:32:11 by mguinin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/bistromathique.h"
#include "../includes/const.h"

t_big               eval(char **str)
{
	return (**str == g_bra ? \
			eval_op(eval(str), str, g_ket) \
			: read_struct(str));
}

t_big				eval_prio(t_big a, char **str)
{
	char			ops;
	t_big			b;

	if (!a)
	{
		return (NULL);
	}
	ops = **str;
	(*str)++;
	b = eval(str);
	return (eval_prio(g_op[(int)ops](a, b), str));
}

t_big				eval_op(t_big a, char **str, char close)
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
	(*str) += (**str != g_minus);
	b = eval (str);
	if (**str == g_minus || **str == g_plus)
	{
		tmp = eval_prio(b, str);
		if (!tmp)
		{
			return (NULL);
		}
		return (eval_op(g_op[(int)ops](a, tmp), str, close));
	}
	return (eval_op(g_op[(int)ops](a, b), str, close));
}
