/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguinin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/02 14:19:39 by mguinin           #+#    #+#             */
/*   Updated: 2013/08/09 14:44:50 by mguinin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bistromathique.h"
#include "../includes/const.h"

t_big				read_struct(char **str)
{
	t_big			res;
	int				n;
	int				i;
	int				sign;

	sign = 1;
	i = 0;
	while (g_tab_test[(int)**str] <= ZERO)
	{
		if (**str == g_minus)
		{
			sign = -sign;
		}
		(*str)++;
	}
	res = create_big(ft_length_nbr(*str), 0);
	res->sgn = sign;
	n = res->len;
	while (n--)
	{
		res->data[i] = g_tab_test[(int)(*str)[n]];
		i++;
	}
	*str = (*str) + i;
	return (res);
}
