/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:29:14 by tlam              #+#    #+#             */
/*   Updated: 2023/09/18 14:04:07 by tlam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	long	i;
	long	square;

	square = 0;
	i = 1;
	while (nb > 0)
	{
		nb = nb - i;
		square++;
		i += 2;
	}
	if (nb == 0)
		return (square);
	else
		return (0);
}
/*
#include <stdio.h>

int main()
{
	int nb = ft_sqrt(0);
	printf("%d\n", nb);
	return 0;
}
*/
