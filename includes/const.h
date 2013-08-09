/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   const.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguinin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/08 19:54:21 by mguinin           #+#    #+#             */
/*   Updated: 2013/08/09 10:45:15 by ybouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

const ulong	g_1ul = 1UL;
const int	g_little_endian = *(char*)&g_1ul;
uchar		g_comp;
ulong		g_comp_8;
t_big		g_zero_big;

/*
** defining a table of integer that will be used for the tests
** it won't vary
*/

char		g_tab_test[256];
