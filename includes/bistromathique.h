/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bistro.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguinin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/07 12:48:11 by mguinin           #+#    #+#             */
/*   Updated: 2013/08/09 11:26:23 by mguinin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BISTRO_H
# define BISTRO_H
# define RET_BITS 0x8080808080808080
# define EXTRA_BUF 256
# define L_END(x) (((long*)x->data) + (((x)->len + 7) >> 3)) 
# define SYNTAXE_ERROR_MSG "syntar error"

typedef	struct			s_big_char
{
	char		*data;
	int			len;
	int			buf_len;
	int			sgn;
}						t_big_char;

typedef t_big_char		*t_big;
typedef unsigned long	t_ulong;
typedef unsigned char	t_uchar;
typedef t_big			(*t_fbig)(t_big, t_big);

t_big		add_big(t_big a, t_big b);
t_big		*create_table(t_big x);
t_big		mult_big(t_big a, t_big b);
int			cmp_big(t_big a, t_big b);
t_big		divmod_big(t_big a, t_big b, int wanna_div);
int			eval_expr(char *base, char *oper, char *str);
t_big		eval(char **str, char *oper, t_fbig op);
t_big		eval_op(t_big a, char **str, char close, t_fbig op);
t_big		eval_prio(t_big a, char **str, t_fbig op);
t_big		read_struct(char **str, char *oper);
void		ft_putstr(char *str, int output);
int			ft_length_nbr(char *str);
int			init_test_tab(char *base, char *oper);
t_big		init_fptr(char *oper);
int			ft_strlen(char *str);

#endif /* BISTRO_H */
