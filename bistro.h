/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bistro.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguinin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/07 12:48:11 by mguinin           #+#    #+#             */
/*   Updated: 2013/08/07 17:55:59 by ybouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BISTRO_H
# define BISTRO_H
# define RET_BITS 0x8080808080808080
# define SYNTAXE_ERROR_MSG "syntax error\n"

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
t_big_char		*add_big_char(t_big_char a, t_big_char b, int offset);
t_big_char		*char_mult(char c, t_big_char x, t_big_char *res);
t_big_char		*mult_big_char(t_big_char a, t_big_char b, t_big_char dest);
int				cmp_for_div(t_big_char num, t_big_char denum);
t_big_char		*divmod_big_char(t_big_char a, t_big_char b, int wanna_div);
int				eval_expr(char *base, char *ops, char *expr);
int				ft_test_base(char c);
int				ft_test_op(char c);
int				ft_length_nbr(char *str);
t_big_char		*read_struct(char **str);
void			init_tab_test(char *base, char *oper);

/*
** defining a global table of integer that won't vary
** and will be used for the tests
*/

int				g_tab_test[256];

#endif /* BISTRO_H */
