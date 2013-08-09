/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguinin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/09 16:37:30 by mguinin           #+#    #+#             */
/*   Updated: 2013/08/09 22:50:18 by mguinin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/bistromathique.h"
#include "../includes/const.h"

t_elem		create_elem(t_elem a, t_elem b, t_fbig op)
{
	t_elem		res;

	res = malloc(sizeof(*res));
	res->sgn = 1;
	res->a = a;
	res->b = b;
	res->op = op;
	return (res);
}

int			read_sgn(char **res)
{
	int		sign;
	char	*str;

	str = *res;
	sign = 1;
	while (*str == g_plus || *str == g_minus)
	{
		if (*str == g_minus)
		{
			sign = -sign;
		}
		str++;
	}
	*res = str;
	return (sign);
}

t_elem		parse_digit(char **s)
{
	char		digit;
	t_elem		x;
	char		*str;

	str = *s;
	x = create_elem(NULL, NULL, NULL);
	x->start = str;
	while ((digit = g_tab_test[(int)*str]) >= 0)
	{
		*str = digit;
		str++;
	}
	if (x->start == str)
	{
		return (NULL);
	}
	x->len = str - x->start;
	while (x->len && *x->start == 0)
	{
		x->start++;
		x->len--;
	}
	*s = str;
	return (x);
}
