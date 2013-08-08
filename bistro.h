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
# define EXTRA_BUF 256
typedef	struct	s_big_char
{
	char		*data;
	int			len;
	int			buf_len;
	int			sgn;
}				t_big_char;

typedef	*t_big_char	t_big;
typedef unsigned long	ulong;
typedef unsigned char	uchar;

t_big		add_big(t_big a, t_big b);
t_big		*create_table(t_big x);
t_big		mult_big(t_big a, t_big b);
int				cmp_big(t_big a, t_big b);
t_big		divmod_big(t_big a, t_big b, int wanna_div);
#endif /* BISTRO_H */
