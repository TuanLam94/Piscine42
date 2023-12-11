/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 17:42:26 by tlam              #+#    #+#             */
/*   Updated: 2023/09/21 16:09:45 by tlam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	memory(int size, char **strs, char *sep)
{
	int	i;
	int	j;
	int	mem;
	int	seplen;

	i = 0;
	mem = 0;
	seplen = ft_strlen(sep);
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			j++;
			mem++;
		}
		if (i < size - 1)
			mem += seplen;
		i++;
	}
	return (mem);
}

void	concatenate_strings(int size, char **strs, char *sep, char *dest)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			dest[k] = strs[i][j];
			k++;
			j++;
		}
		j = 0;
		while (sep[j] && i < size - 1)
		{
			dest[k] = sep[j];
			k++;
			j++;
		}
		i++;
	}
	dest[k] = '\0';
}	

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*dest;
	int		mem;

	mem = memory(size, strs, sep);
	dest = malloc(sizeof(char) * (mem + 1));
	if (!dest)
		return (0);
	if (size == 0)
	{
		*dest = '\0';
		return (dest);
	}
	concatenate_strings(size, strs, sep, dest);
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>

int	main(int argc, char **argv)
{
	printf("./a.out___said___this___is___a___string :\n");
	printf("%s\n",  ft_strjoin(argc, argv, "___"));

}
*/
