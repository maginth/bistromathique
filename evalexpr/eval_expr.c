/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_expr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguinin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/02 14:13:03 by mguinin           #+#    #+#             */
/*   Updated: 2013/08/09 11:46:55 by mguinin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bistromathique.h"
#include "../includes/const.h"

int				ft_strlen2(char *strlen)
{
	int			i;

	i = 0;
	while (strlen[i] != 0)
	{
		i = i + 1;
	}
	return (i);
}

void			init_global(char *base)
{
	t_ulong		ul1;
   
	ul1= 1UL;
	g_base = ft_strlen2(base);
	g_compl = 256 - g_base;
	g_compl_8 = g_compl * 0x0101010101010101;
	g_zero_big = create_big(0, 0);
	g_little_endian = *(char*)&ul1;
}

int				eval_expr(char *base, char *oper, char *str)
{
	t_big		res;
	int			i;
	t_fbig		op;

	i = 0;
	init_test_tab(base, oper);
	init_global(base);
	op = init_fptr(oper);
	while (g_tab_test[(int)str[i]] != -1)
	{
		i++;
	}
	if (i != ft_strlen2(str))
	{
		ft_putstr(SYNTAXE_ERROR_MSG, 2);
		return (0);
	}
	res = eval_op(eval(&str, oper, op), &str, '\0', op);
	ft_putconvert(base, res);
	return (1);
}
