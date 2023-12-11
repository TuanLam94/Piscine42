/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 14:07:38 by tlam              #+#    #+#             */
/*   Updated: 2023/09/21 15:01:15 by tlam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	check_base(char *base)
{
	int	len;
	int	i;
	int	j;

	i = 0;
	len = ft_strlen(base);
	if (len <= 1)
		return (0);
	while (base[i])
	{
		j = i + 1;
		if (base[i] == '+' || base[i] == '-' || base[i] == ' '
			|| base[i] == '\n' || base[i] == '\t'
			|| base[i] == '\r' || base[i] == '\f'
			|| base[i] == '\v')
			return (0);
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

long	is_base(char c, char *base)
{
	long	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (1);
		i++;
	}
	return (0);
}

long	basenum(char c, char *base)
{
	long	i;

	i = 0;
	while (c != base[i])
		i++;
	return (i);
}

long	ft_atoi_base(char *str, char *base)
{
	long int	negative;
	long int	atoi;

	negative = 1;
	atoi = 0;
	if (!check_base(base))
		return (0);
	else
	{
		while (*str == ' ' || *str == '\n' || *str == '\t'
			|| *str == '\r' || *str == '\f' || *str == '\v')
			str++;
		while (*str == '+' || *str == '-')
		{
			if (*str == '-')
				negative = -negative;
			str++;
		}
		while (is_base(*str, base))
		{
			atoi = atoi * ft_strlen(base) + basenum(*str, base);
			str++;
		}
	}
	return (atoi * negative);
}
