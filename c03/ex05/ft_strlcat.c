/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                i                +#+#+#+#+#+   +#+          */
/*   Created: 2023/09/09 17:39:25 by tlam              #+#    #+#             */
/*   Updated: 2023/09/13 14:54:28 by tlam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	destlen;
	unsigned int	srclen;

	i = 0;
	srclen = 0;
	destlen = 0;
	while (src[srclen])
		srclen++;
	while (dest[destlen])
		destlen++;
	if (destlen >= size)
		return (srclen + size);
	while (src[i])
	{
		if (destlen < size - 1)
			dest[destlen] = src[i];
		if (destlen == size - 1)
			dest[destlen] = '\0';
		destlen++;
		i++;
	}
	return (destlen);
}
/*
	
#include <bsd/string.h>
#include <stdio.h>

int	main(void)
{
	char source[50];
	char dest[50];
	int nb;
	strcpy(dest, "7654321");
	strcpy(source,"12345");
	nb = ft_strlcat(dest, source, 14);
	printf("%s","la valeur de retour est :");
	printf("%d\n", nb);
	printf("%s","la source est :");
	printf("%s\n", source);
	printf("%s","la destination est :");
	printf("%s\n", dest);
	return 0;
}
*/
