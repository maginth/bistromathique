/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguinin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/05 19:46:15 by mguinin           #+#    #+#             */
/*   Updated: 2013/08/05 20:14:18 by mguinin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_H
# define TYPE_H
typedef		unsigned long	ulong;
typedef		unsigned int	uint;
typedef		struct		s_big_long
{
	long				*data;
	int					len;
}						t_big_long

typedef		struct		s_big_char
{
	long				*data;
	int					len;
}						t_big_char
#endif /* TYPE_H */

