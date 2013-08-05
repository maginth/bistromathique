/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguinin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/02 14:24:30 by mguinin           #+#    #+#             */
/*   Updated: 2013/08/02 18:08:35 by mguinin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int			str_len(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

void		put_str(char *str, int fd)
{
	write(fd, str, str_len(str));
}

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

void		ft_putnbr(long nbr)
{
	int		nbr_len;
	long	nbr_flip;

	nbr_len = nbr ? 0 : 1;
	nbr_flip = 0;
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr = -nbr;
	}
	while (nbr)
	{
		nbr_flip = nbr_flip * 10 + (nbr % 10);
		nbr /= 10;
		nbr_len++;
	}
	while (nbr_len)
	{
		ft_putchar('0' + (nbr_flip % 10));
		nbr_flip /= 10;
		nbr_len--;
	}
}

