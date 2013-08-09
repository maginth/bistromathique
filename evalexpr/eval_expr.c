/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_expr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguinin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/02 14:13:03 by mguinin           #+#    #+#             */
/*   Updated: 2013/08/09 11:23:42 by ybouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bistromathique.h"
#include "../includes/const.h"

void			init_global(char *base)
{
	g_base = ft_strlen(base);
	g_compl = 256 - g_base;
	g_compl_8 = g_compl * 0x0101010101010101;
	g_zero_big = create_big(0, 0);
	g_little_endian = *(char*)&g_1ul;
}

int				eval_expr(char *base, char *oper, char *str)
{
	t_big	res;
	int		i;
	t_fbig	op;

	i = 0;
	init_test_tab(base, oper);
	init_global(base);
	op = initfptr(oper);
	while (g_tab_test[str[i]] != -1)
	{
		i++;
	}
	if (i != ft_strlen(str))
	{
		ft_putstr(SYNTAXE_ERROR_MSG, 2);
		return (0);
	}
	res = eval_op(eval(&str, oper, op), &str, '\0', op);
	ft_putconvert(res->data, 1);
	return (1);
}
