/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bistro.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguinin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/07 12:48:11 by mguinin           #+#    #+#             */
/*   Updated: 2013/08/09 23:34:35 by mguinin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BISTRO_H
# define BISTRO_H
# define RET_BITS 0x8080808080808080
# define EXTRA_BUF 256
# define L_END(x) (((long*)x->data) + (((x)->len + 7) >> 3)) 
# define SYNTAXE_ERROR_MSG "syntax error\n"
# define MINUS -5
# define PLUS -4
# define ZERO 0

typedef unsigned long	t_ulong;
typedef unsigned char	t_uchar;
typedef	struct			s_big_char
{
	t_uchar		*data;
	int			len;
	int			buf_len;
	int			sgn;
}						t_big_char;
typedef t_big_char		*t_big;
typedef t_big			(*t_fbig)(t_big, t_big);
typedef struct			s_element
{
	int					sgn;
	struct s_element	*a;
	struct s_element	*b;
	t_fbig				op;
	char				*start;
	int					len;
}						t_element;
typedef t_element		*t_elem;

t_elem				parse(char **str);
t_elem				parse_prio(t_elem a, char **str, char close);
t_elem				parse_op(t_elem a, char **str, char close);
t_elem				create_elem(t_elem a, t_elem b, t_fbig op);
int					read_sgn(char **res);
t_elem				parse_digit(char **s);
t_big				create_big(int len, int init_zero);
t_big				add_big(t_big a, t_big b);
t_big				*create_table(t_big x);
t_big				mult_big(t_big a, t_big b);
long				cmp_big(t_big a, t_big b, int offset);
t_big				divmod_big(t_big a, t_big b);
int					eval_expr(char *base, char *oper, char *str);
t_big				eval(t_elem elem);
t_big				read_struct(t_elem elem);
void				ft_putstr(char *str, int output);
int					ft_length_nbr(char *str);
int					init_test_tab(char *base, char *oper);
t_fbig				*init_fptr();
int					ft_strlen2(char *str);
void				ft_putconvert(char *base, t_big a);
void				extend_buf(t_big *x);
void				offset_add(t_big a, t_big b, int offset);
void				offset_sub(t_big a, t_big b, int offset);
void				destruct_big(t_big x);
void				adjust_length(t_big x);
void				add_data(long *la, long *lb, long *lb_end);
void				sub_data(long *la, long *lb, long *lb_end);
t_big				div_big(t_big a, t_big b);
t_big				mod_big(t_big a, t_big b);
void				divmod_data(t_big a, t_big *mult_b, t_big res);
void				destruct_table(t_big *table);
t_big				get_mult(t_uchar c, t_big *table);
void				mult_data(t_big *mult_a, t_big b, t_big res);
t_big				cp_big(t_big x);

#endif /* BISTRO_H */
