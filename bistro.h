/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bistro.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguinin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/07 12:48:11 by mguinin           #+#    #+#             */
/*   Updated: 2013/08/07 17:20:51 by mguinin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BISTRO_H
# define BISTRO_H
# define RET_BITS 0x8080808080808080
# define MIN_BITS 0x0101010101010101
typedef	struct	s_big_char
{
	char		*data;
	int			len;
	int			sgn;
	int			not_prepared;
}				t_big_char;
typedef	struct	s_div_mod
{
	char		digit;
	char		ret;
}				t_div_mod;
t_big_char		*prepare_for_add(t_big_char a);
t_big_char		*prepare_for_sub(t_big_char a);
t_big_char		*add_big_char(t_big_char a, t_big_char b, int offset);
t_big_char		*char_mult(char c, t_big_char x, t_big_char *res);
t_big_char		*mult_big_char(t_big_char a, t_big_char b, t_big_char dest);
int				cmp_for_div(t_big_char num, t_big_char denum);
t_big_char		*divmod_big_char(t_big_char a, t_big_char b, int wanna_div);
#endif /* BISTRO_H */
