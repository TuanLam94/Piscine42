/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 18:29:57 by tlam              #+#    #+#             */
/*   Updated: 2023/09/21 16:10:02 by tlam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str);
int	check_base(char *base);
int	ft_atoi_base(char *str, char *base);

long	memory(long nbr, char *base_to)
{
	long	mem;

	mem = 1;
	if (check_base(base_to))
	{
		while (nbr > 0)
		{
			mem++;
			nbr = nbr / ft_strlen(base_to);
		}
	}
	return (mem);
}

void	rev_string(char *str)
{
	int		i;
	int		j;
	char	swap;

	j = ft_strlen(str) - 1;
	i = 0;
	while (i < j)
	{
		swap = str[i];
		str[i] = str[j];
		str[j] = swap;
		j--;
		i++;
	}
}

void	allocate_to_dest(long nb, char *base_to, char *dest)
{
	long	len;
	long	sign;
	long	i;

	i = 0;
	sign = nb;
	len = ft_strlen(base_to);
	if (nb < 0)
		nb = -nb;
	while (nb > 0)
	{
		dest[i++] = base_to[nb % len];
		nb = nb / len;
	}
	if (sign < 0)
		dest[i++] = '-';
	rev_string(dest);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long	nb;
	char	*dest;
	long	mem;
	long	negative;

	if (!(check_base(base_from)) || !(check_base(base_to)))
		return (NULL);
	nb = ft_atoi_base(nbr, base_from);
	mem = memory(nb, base_to);
	if (nb == 0)
	{
		dest = malloc(sizeof(char) * 2);
		dest[0] = base_to[0];
		dest[1] = '\0';
		return (dest);
	}
	negative = 0;
	if (nb < 0)
		negative = 1;
	dest = malloc(sizeof(char) * (mem + 1 + negative));
	if (!dest)
		return (NULL);
	allocate_to_dest(nb, base_to, dest);
	return (dest);
}
/*
#include <stdio.h>

int main()
{
	char *nbr = "  -4385";
	char *base_from = "0123456789";
	char *base_to = "0123456789abcdef";
	char *dest = ft_convert_base(nbr, base_from, base_to);
	printf("%s\n", dest);
	return 0;
}
*/
