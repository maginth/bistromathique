/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguinin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/09 16:37:30 by mguinin           #+#    #+#             */
/*   Updated: 2013/08/09 17:44:31 by mguinin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromathique.h"
#define NEXT(x) &(++(*str))

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

char		*read_digit(t_parse_big x, char *str)
{
	int			len;
	t_uchar		digit;

	digit = g_tab_test[(int)*str];
	x->start = str;
	while (digit >= 0)
	{
		*str = digit;
		*str++;
		digit = g_tab_test[(int)*str];
	}
	if (x->start == str)
	{
		return (NULL);
	}
	while (*x->start == 0)
	{
		x->start++;
	}
	x->len = *str - x->start;
	return (str);
}

t_elem		*parse_operation(t_elem elem, char *str, int level)
{
	read_sgn(*str);
	
	


