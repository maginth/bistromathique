/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguinin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/07 18:01:57 by mguinin           #+#    #+#             */
/*   Updated: 2013/08/07 18:17:58 by mguinin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_big_char		*create_big_char(int len)
{
	t_big_char		*res;

	res = malloc(sizeof(*res));
	res->data = 8 + malloc(len + 16);
	*(long*)(res->data - 8) = 0;
	*(long*)(res->data + len) = 0;
	res->len = len;
	res->sgn = 1;
	res->not_prepared = 1;
	return (res);
}
