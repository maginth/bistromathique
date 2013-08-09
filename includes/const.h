/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   const.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguinin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/08 19:54:21 by mguinin           #+#    #+#             */
/*   Updated: 2013/08/09 14:25:29 by mguinin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			g_little_endian;
t_uchar		g_compl;
t_ulong		g_compl_8;
t_big		g_zero_big;
t_uchar		g_base;
char		*g_oper;
char		g_bra;
char		g_ket;
char		g_plus;
char		g_minus;
char		g_mult;
char		g_div;
char		g_mod;
t_fbig		*g_op;

/*
** defining a table of integer that will be used for the tests
** it won't vary
*/

int			g_tab_test[256];
