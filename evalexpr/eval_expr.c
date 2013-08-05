/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_expr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguinin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/02 14:13:03 by mguinin           #+#    #+#             */
/*   Updated: 2013/08/02 18:06:56 by mguinin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"
#include "eval_op.h"

long		(*operation[256])(long, long);

char		*error = 0;

void		set_error(char *err)
{
	if (!error)
	{
		error = err;
	}
}

long		add(long a, long b)
{
	return (a + b);
}

long		sub(long a, long b)
{
	return (a - b);
}

long		mul(long a, long b)
{
	return (a * b);
}

long		div(long a, long b)
{
	if (b == 0)
	{
		set_error("Error Division by 0\n");
		return (0);
	}
	return (a / b);
}

long		mod(long a, long b)
{
	if (b == 0)
	{
		set_error("Error modulo 0\n");
		return (0);
	}
	return (a % b);
}

long		err(long a, long b)
{
	set_error("Syntax error : verify your expression\n");
	return (a * b * 0);
}

void		init(void)
{
	long		i;

	i = 256;
	while (--i)
	{
		operation[i] = &err;
	}
	operation['+'] = &add;
	operation['-'] = &sub;
	operation['*'] = &mul;
	operation['/'] = &div;
	operation['%'] = &mod;
}

int			eval_expr(char *str)
{
	long	res;

	init();
	str--;
	res = eval_op(eval(&str), &str, '\0');
	if (error)
	{
		put_str(error, 2);
	}
	return (res);
}

int			main(int ac, char **av)
{
	if (ac > 1)
	{
		ft_putnbr(eval_expr(av[1]));
		ft_putchar('\n');
	}
	return (0);
}
