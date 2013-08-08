/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguinin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/02 14:19:39 by mguinin           #+#    #+#             */
/*   Updated: 2013/08/08 22:46:46 by ybouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_big				read_struct(char **str, char **oper)
{
	t_big			res;
	int				n;
	int				i;
	int				sign;

	sign = 1;
	i = 0;
	while (**str == *oper[3] || **str == *oper[2] || g_tab_test[**str] == 0)
	{
		if (**str == *oper[3])
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
		res->data[i] == (*str)[n];
		i++;
	}
	*str = (*str) + i;
	return (res);
}
