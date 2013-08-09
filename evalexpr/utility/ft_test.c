/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouvet <yann.bouvet@voila.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/06 17:08:57 by ybouvet           #+#    #+#             */
/*   Updated: 2013/08/09 22:28:03 by mguinin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bistromathique.h"
#include "../../includes/const.h"
#include <unistd.h>
#include <stdlib.h>

void		ft_putstr(char *str, int output)
{
	while (*str)
	{
		write(output, str, 1);
		str++;
	}
}

int			ft_length_nbr(char *str)
{
	int		i;

	i = 0;
	while (g_tab_test[(int)str[i]] >= 0)
	{
		i++;
	}
	return (i);
}

int			init_test_tab(char *base, char *oper)
{
	int		i;

	i = 256;
	while (i)
	{
		g_tab_test[--i] = -1;
	}
	while (*base)
	{
		g_tab_test[(int)*base] = i++;
		base++;
	}
	i = -2;
	while (*oper)
	{
		if (g_tab_test[(int)*oper] != -1)
		{
			ft_putstr(SYNTAXE_ERROR_MSG, 2);
			return (0);
		}
		g_tab_test[(int)*oper] = i--;
		oper++;
	}
	return (1);
}

t_fbig		*init_fptr()
{
	t_fbig	*op;
	int		i;

	op = malloc(sizeof(*op) * 256);
	i = 0;
	while (i < 256)
	{
		op[i++] = NULL;
	}
	op[(int)g_plus] = &add_big;
	op[(int)g_minus] = &add_big;
	op[(int)g_mult] = &mult_big;
	op[(int)g_div] = &div_big;
	op[(int)g_mod] = &mod_big;

	return (op);
}

void		ft_putconvert(char *base, t_big a)
{
	int		i;

	i = a->len;
	if (a->len == 0)
	{
		write(1, base, 1);
	}
	else if (a->sgn == -1)
	{
		write(1, "-", 1);
	}
	while (i--)
	{
		write(1, &base[(int)(a->data[i])], 1);
	}
	write(1, "\n", 1);
}
