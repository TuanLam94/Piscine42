/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 10:02:21 by tlam              #+#    #+#             */
/*   Updated: 2023/09/20 15:05:49 by tlam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;

	i = 2;
	if (nb < 2)
		return (0);
	if (nb == 2)
		return (1);
	while (i * i <= nb && i <= 46341)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	int	res;

	res = nb;
	while (!ft_is_prime(res))
		res++;
	return (res);
}
/*
#include <stdio.h>

int main ()
{
	printf("%d\n", ft_find_next_prime(2147483647));
	return 0;
}
*/
