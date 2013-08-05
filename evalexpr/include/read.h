/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguinin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/02 14:22:10 by mguinin           #+#    #+#             */
/*   Updated: 2013/08/02 17:47:48 by mguinin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_H
# define READ_H
long			eval_op(long a, char **str, char close);
void			skip_spaces(char **str);
long			read_long(char **str);
long			add(long a, long b);
long			sub(long a, long b);
long			mul(long a, long b);
long			div(long a, long b);
long			mod(long a, long b);
#endif /* READ_H */
