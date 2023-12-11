/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 15:41:47 by tlam              #+#    #+#             */
/*   Updated: 2023/09/18 14:00:27 by tlam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	res;
	int	i;

	res = nb;
	i = power;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	while (i > 1)
	{
		res = res * nb;
		i--;
	}
	return (res);
}
/*
#include <stdio.h>

int main ()
{
	int nb = ft_iterative_power(9,2);
	printf("%d\n", nb);
	return 0;
}
*/
