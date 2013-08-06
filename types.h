/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguinin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/05 19:46:15 by mguinin           #+#    #+#             */
/*   Updated: 2013/08/06 14:59:06 by mguinin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H
typedef		unsigned long	ulong;
typedef		unsigned int	uint;
typedef		struct		s_big_long
{
	int					sgn;
	long				*data;
	int					len;
}						t_big_long

typedef		struct		s_big_char
{
	int					sgn;
	char				*data;
	int					len;
}						t_big_char
#endif /* TYPES_H */

