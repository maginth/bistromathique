/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguinin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/02 14:19:39 by mguinin           #+#    #+#             */
/*   Updated: 2013/08/09 19:56:47 by mguinin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bistromathique.h"
#include "../includes/const.h"

t_big				read_struct(t_elem elem)
{
	t_big			res;
	char			*digit;
	int				n;
	t_uchar			*data;

	res = create_big(elem->len, 0);
	data = res->data;
	res->sgn = elem->sgn;
	n = elem->len;
	digit = elem->start + n - 1;
	while (n--)
	{
		*data = *digit;
		digit--;
		data++;
	}
	return (res);
}
