/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:21:25 by tlam              #+#    #+#             */
/*   Updated: 2023/09/21 16:11:02 by tlam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	count_words(char *str, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (!is_charset(str[i], charset))
		{
			count++;
			while (!is_charset(str[i], charset) && str[i])
				i++;
		}
		while (is_charset(str[i], charset) && str[i])
			i++;
	}
	return (count);
}

int	allocate_memory(char *str, char *charset, char ***dest, int words)
{
	int	len;
	int	i;
	int	k;

	k = 0;
	i = 0;
	*dest = malloc(sizeof(char *) * (words + 1));
	if (!(*dest))
		return (0);
	while (str[i])
	{
		len = 0;
		while (str[i] && is_charset(str[i], charset))
			i++;
		while (str[i] && !is_charset(str[i], charset))
		{
			i++;
			len++;
		}
		(*dest)[k] = malloc(sizeof(char) * (len + 1));
		if (!(*dest)[k])
			return (0);
		k++;
	}
	return (1);
}

char	**allocate_to_dest(char *str, char *charset, char **dest)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (str[i])
	{
		j = 0;
		while (str[i] && is_charset(str[i], charset))
			i++;
		while (str[i] && !is_charset(str[i], charset))
		{
			dest[k][j++] = str[i++];
		}
		dest[k][j] = '\0';
		k++;
	}
	if (k > 0 && !dest[k - 1][0])
		dest[k - 1] = 0;
	return (dest);
}

char	**ft_split(char *str, char *charset)
{
	char	**dest;
	int		words;

	words = count_words(str, charset);
	if (!(allocate_memory(str, charset, &dest, words)))
		return (0);
	dest = allocate_to_dest(str, charset, dest);
	return (dest);
}
/*
#include <stdio.h>

int main()
{
	char *str = "  ,,, bon,jour ,, a , ,tous ,, a";
	char *charset = " ,";
	char **dest = ft_split(str, charset);
	int	i = 0;
	while (dest[i])
	{
		printf("%s\n", dest[i]);
		free(dest[i]);
		i++;
	}
	free(dest);
	return 0;
}
*/
