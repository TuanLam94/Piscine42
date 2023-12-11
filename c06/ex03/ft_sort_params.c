/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 13:36:25 by tlam              #+#    #+#             */
/*   Updated: 2023/09/15 10:45:17 by tlam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

void	ft_swaparg(char **argv1, char **argv2)
{
	char	*swap;

	swap = *argv1;
	*argv1 = *argv2;
	*argv2 = swap;
}

int	main(int argc, char **argv)
{
	int		i;
	int		j;

	i = 1;
	if (argc)
	{
		while (i < argc)
		{
			j = i + 1;
			while (j < argc)
			{
				if (ft_strcmp(argv[i], argv[j]) > 0)
					ft_swaparg(&argv[i], &argv[j]);
				j++;
			}
			i++;
		}
		i = 0;
		while (i++ < argc - 1)
		{
			ft_putstr(argv[i]);
			write(1, "\n", 1);
		}
	}
	return (0);
}
