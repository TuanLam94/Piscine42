/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 16:32:17 by tlam              #+#    #+#             */
/*   Updated: 2023/09/21 09:43:32 by tlam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	size;

	size = max - min;
	i = 0;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	*range = malloc(sizeof(int) * (max - min + 1));
	if (!range)
		return (-1);
	while (min < max)
	{
		range[0][i] = min;
		i++;
		min++;
	}
	return (size);
}
/*
#include <stdio.h>

int main ()
{
	int *range;
	printf("0:%d\n", ft_ultimate_range(&range, 3, 3));
	printf("2:%d\n", ft_ultimate_range(&range, -1, 1));
	printf("5:%d\n", ft_ultimate_range(&range, 0, 5));
	int	i = 0;
	while (i < 5)
	{
		printf("%d\n", range[i]);
		i++;
	}

	return 0;
}
*/
