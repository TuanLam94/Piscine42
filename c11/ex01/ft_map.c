/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 11:55:53 by tlam              #+#    #+#             */
/*   Updated: 2023/09/27 14:37:34 by tlam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	i;
	int	*dest;

	i = 0;
	dest = malloc(sizeof(int) * length);
	if (!dest)
		return (0);
	while (i < length)
	{
		dest[i] = (f)(tab[i]);
		i++;
	}
	return (dest);
}

/*
#include <stdio.h>

int	ft_plus(int i)
{
	i = i + 4;
	return i;
}


int main()
{
	int tab[4];
	tab[0] = 1;
	tab[1] = 2;
	tab[2] = 6;
	tab[3] = 13;

	int *dest = ft_map(tab, 4, &ft_plus);
	int i = 0;
	while (i < 4)
	{
		printf("%d\n", dest[i]);
		i++;
	}
	return (0);
}
*/
