/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 12:28:35 by tlam              #+#    #+#             */
/*   Updated: 2023/09/10 17:00:42 by tlam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	str_lowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	cap;

	i = 0;
	cap = 1;
	str_lowcase(str);
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			if (cap == 1)
			{
				str[i] -= 32;
				cap = 0;
			}
		}
		else if (str[i] >= '0' && str[i] <= '9')
			cap = 0;
		else
			cap = 1;
		i++;
	}
	return (str);
}
