/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_expr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguinin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/02 14:13:03 by mguinin           #+#    #+#             */
/*   Updated: 2013/08/08 17:48:58 by ybouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"
#include "eval_op.h"

int			eval_expr(char *base, char *oper, char *str)
{
	long	res;
	int		i;

	i = 0;
	init_test_tab(&base, &oper);
	while (g_tab_test[str[i]] != -1)
	{
		i++;
	}
	if (i != ft_strlen(str))
	{
		ft_putstr(SYNTAXE_ERROR_MSG, 2);
	}
	res = eval_op(eval(&str, &base), &str, '\0', &oper);
}
