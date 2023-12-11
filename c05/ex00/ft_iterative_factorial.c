/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 13:58:39 by tlam              #+#    #+#             */
/*   Updated: 2023/09/14 17:46:25 by tlam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	res;

	res = 1;
	if (nb < 0)
		return (0);
	while (nb > 1)
	{
		res = res * nb;
		nb--;
	}
	return (res);
}
/*

#include <stdio.h>

int main()
{
	int nb = ft_iterative_factorial(5);
	printf("%d\n", nb);
	return 0;
}
*/
