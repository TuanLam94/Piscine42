/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:01:07 by tlam              #+#    #+#             */
/*   Updated: 2023/09/27 18:04:35 by tlam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <tools.h>

void	add(int value1, int value2)
{
	int	res;

	res = value1 + value2;
	ft_putnbr(res);
}

void	sub(int value1, int value2)
{
	int	res;

	res = value1 - value2;
	ft_putnbr(res);
}

void	multiply(int value1, int value2)
{
	int	res;

	res = value1 * value2;
	ft_putnbr(res);
}

void	divide(int value1, int value2)
{
	int	res;

	if (value2 == 0)
	{
		ft_putstr("Stop : division by zero");
		return ;
	}
	res = value1 / value2;
	ft_putnbr(res);
}

void	modulo(int value1, int value2)
{
	int	res;

	if (value2 == 0)
	{
		ft_putstr("Stop : modulo by zero");
		return ;
	}
	res = value1 % value2;
	ft_putnbr(res);
}
