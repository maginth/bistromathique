/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouvet <yann.bouvet@voila.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/05 15:26:52 by ybouvet           #+#    #+#             */
/*   Updated: 2013/08/09 11:11:32 by ybouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "includes/bistromathique.h"

static size_t		ft_strlen(char *strlen)
{
	size_t			i;

	i = 0;
	while (strlen[i] != 0)
	{
		i = i + 1;
	}
	return (i);
}

static unsigned	int	ft_uatoi(char *nbr)
{
	unsigned int	res;

	res = 0;
	while (*nbr)
	{
		res = *nbr - '0' + res * 10;
		nbr = nbr + 1;
	}
	return (res);
}

static int			ft_fill_buff(char* buf, size_t size)
{
	size_t			size_read;
	size_t			ret;

	size_read = 0;
	ret = read(0, buf, size);
	if (ret == -1)
	{
		write(2, SYNTAXE_ERROR_MSG, ft_strlen(SYNTAXE_ERROR_MSG));
		return (1);
	}
	while (ret != 0)
	{
		size_read = size_read + ret;
		ret = read(0, buf, size - size_read);
		if (ret == -1)
		{
			write(2, SYNTAXE_ERROR_MSG, ft_strlen(SYNTAXE_ERROR_MSG));
			return (1);
		}
	}
	buf[size_read] = 0;
	return (0);
}

static int			ft_check_args_n_malloc_buf(int argc, char **argv, char **buf)
{
	size_t			size;

	if (argc != 4)
	{
		write(2, SYNTAXE_ERROR_MSG, ft_strlen(SYNTAXE_ERROR_MSG));
		return (1);
	}
	size = ft_uatoi(argv[3]);
	*buf = malloc(sizeof(**buf) * (size + 1));
	if (*buf == 0)
	{
		write(2, SYNTAXE_ERROR_MSG, ft_strlen(SYNTAXE_ERROR_MSG));
		return (1);
	}
	return (ft_fill_buff(*buf, size));
}

int					main(int argc, char **argv)
{
	char			*buf;

	if (ft_check_args_n_malloc_buf(argc, argv, &buf))
	{
		return (1);
	}
	return (eval_expr(argv[1], argv[2], buf));
}
