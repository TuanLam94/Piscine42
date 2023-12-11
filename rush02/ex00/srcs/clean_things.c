/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_things.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flboulea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 18:29:41 by flboulea          #+#    #+#             */
/*   Updated: 2023/09/24 00:31:27 by flboulea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "tools.h"

// OK
char	*check_for_useless_zero(char *str)
{
	int		i;
	int		useless_zero_counter;
	char	*dest;

	if (str[0] != '0' || !str[1])
		return (str);
	i = 0;
	useless_zero_counter = 0;
	while (str[i + 1])
	{
		if (str[i] == '0')
			useless_zero_counter++;
		else
			break ;
		i++;
	}	
	dest = malloc(ft_strlen(str) - useless_zero_counter + 1);
	if (!dest)
		return (0);
	i = -1;
	while (str[useless_zero_counter + ++i])
		dest[i] = str[useless_zero_counter + i];
	dest[ft_strlen(str) - useless_zero_counter] = '\0';
	return (dest);
}

// OK
char	*clean_number(char *str, int need_free)
{
	int		i;
	int		len;
	char	*dest;

	i = 0;
	while (ft_char_is_whitespace(str[i]))
		i++;
	if (str[i] == '-')
		return (0);
	if (str[i] == '+')
		i++;
	len = 0;
	while (ft_char_is_numeric(str[i + len]))
		len++;
	if (!len)
		return (0);
	dest = malloc(len + 1);
	if (!dest)
		return (0);
	len = 0;
	while (ft_char_is_numeric(str[i]))
		dest[len++] = str[i++];
	if (need_free)
		free(str);
	return (dest[len] = '\0', check_for_useless_zero(dest));
}

// OK
int	set_start_end(char *str, int *start, int *end)
{
	*start = 0;
	*end = ft_strlen(str) - 1;
	while (ft_char_is_whitespace(str[*start]))
		(*start)++;
	if (!str[*start])
		return (0);
	while (ft_char_is_whitespace(str[*end]))
		(*end)--;
	return (1);
}

// OK
int	get_clean_writing_length(char *str)
{
	int	start;
	int	end;
	int	len;

	len = 0;
	if (!set_start_end(str, &start, &end))
		return (0);
	while (start <= end)
	{
		while (start <= end && !ft_char_is_whitespace(str[start]))
		{
			start++;
			len++;
		}
		if (start <= end && ft_char_is_whitespace(str[start]))
		{
			len++;
			while (start <= end && ft_char_is_whitespace(str[start]))
				start++;
		}
	}
	return (len);
}

// OK
char	*clean_writing(char *str)
{
	char	*dest;
	int		len;
	int		start;
	int		end;
	int		i;

	len = get_clean_writing_length(str);
	if (!len)
		return (0);
	dest = malloc(len + 1);
	if (!dest || !set_start_end(str, &start, &end))
		return (0);
	i = 0;
	while (i < len)
	{
		while (start <= end && !ft_char_is_whitespace(str[start]))
			dest[i++] = str[start++];
		if (start <= end && ft_char_is_whitespace(str[start]))
		{
			dest[i++] = str[start++];
			while (start <= end && ft_char_is_whitespace(str[start]))
				start++;
		}
	}
	return (free(str), dest);
}
