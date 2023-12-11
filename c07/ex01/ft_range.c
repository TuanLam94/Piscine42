/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 14:03:36 by tlam              #+#    #+#             */
/*   Updated: 2023/09/21 16:14:40 by tlam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*dest;

	i = 0;
	if (min >= max)
		return (0);
	dest = malloc(sizeof(int) * (max - min + 1));
	if (!dest)
		return (0);
	while (min < max)
	{
		dest[i] = min;
		i++;
		min++;
	}
	return (dest);
}
/*
#include <stdio.h>

int main ()
{
	int *dest; 
	dest = ft_range(-2, -12);
//	int i = 0;
//	while (i < 10)
//	{
//		printf("%d\n", dest[i]);
//		i++;
//	}
	return 0;
}
*/
