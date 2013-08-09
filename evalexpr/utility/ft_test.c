/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouvet <yann.bouvet@voila.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/06 17:08:57 by ybouvet           #+#    #+#             */
/*   Updated: 2013/08/09 12:17:33 by ybouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bistromathique.h"
#include "../../includes/const.h"
#include <unistd.h>

void		ft_putstr(char *str, int output)
{
	while (*str)
	{
		write (output, str, 1);
		str++;
	}
}

int			ft_length_nbr(char *str)
{
	int		i;

	i = 0;
	while (g_tab_test[str[i]] >= 0)
	{
		i++;
	}
	return (i);
}

int			init_test_tab(char *base, char *oper)
{
	int		i;

	i = 256;
	while (i--)
	{
		g_tab_test[i] = -1;
	}
	while (*base)
	{
		g_tab_test[*base] = i++;
		base++;
	}
	i = -2;
	while (*oper)
	{
		if (g_tab_test[*oper] != -1)
		{
			ft_putstr(SYNTAXE_ERROR_MSG, 2);
			return (0);
		}
		g_tab_test[*oper] = i--;
		oper++;
	}
	return (0);
}

t_fbig		*init_fptr(char *oper)
{
	t_fbig	*op;

	op[oper[2]] = &add_big;
	op[oper[3]] = &add_big;
	op[oper[4]] = &mult_big;
	op[oper[5]] = &div_big;
	op[oper[6]] = &mod_big;

	return (op);
}

void		ft_putconvert(char *base, t_big a)
{
	int		i;

	i = a->len;
	while (i--)
	{
		write(1, &base[a->data[i]], 1);
	}
}
