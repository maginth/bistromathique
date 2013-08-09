/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_expr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguinin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/02 14:13:03 by mguinin           #+#    #+#             */
/*   Updated: 2013/08/09 14:50:00 by mguinin          ###   ########.fr       */
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

void			init_global(char *base, char *oper)
{
	t_ulong		ul1;
   
	ul1= 1UL;
	g_base = ft_strlen2(base);
	g_compl = 256 - g_base;
	g_compl_8 = g_compl * 0x0101010101010101;
	g_zero_big = create_big(0, 0);
	g_little_endian = *(char*)&ul1;
	g_oper = oper;
	g_bra = oper[0];
	g_ket = oper[1];
	g_plus = oper[2];
	g_minus = oper[3];
	g_mult = oper[4];
	g_div = oper[5];
	g_mod = oper[6];
}

int				eval_expr(char *base, char *oper, char *str)
{
	t_big		res;
	int			i;

	i = 0;
	if (!init_test_tab(base, oper))
	{
		return (1);
	}
	init_global(base, oper);
	g_op = init_fptr();
	while (g_tab_test[(int)str[i]] != -1)
	{
		i++;
	}
	if (str[i] != '\0')
	{
		printf("error unvalid char %d\n", str[i]);
		ft_putstr(SYNTAXE_ERROR_MSG, 2);
		return (1);
	}
	res = eval_op(eval(&str), &str, '\0');
	ft_putconvert(base, res);
	return (0);
}
