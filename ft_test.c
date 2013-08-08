/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouvet <yann.bouvet@voila.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/06 17:08:57 by ybouvet           #+#    #+#             */
/*   Updated: 2013/08/08 17:52:21 by ybouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromathique.h"

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
	while (g_tab_test[str[i]])
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
	while (*oper)
	{
		if (g_tab_test[*oper] != -1)
		{
			ft_putstr(SYNTAXE_ERROR_MSG, 2);
			return (0);
		}
		g_tab_test[*oper] = -2;
		oper++;
	}
	return (0);
}
