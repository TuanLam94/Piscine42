/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 16:19:38 by tlam              #+#    #+#             */
/*   Updated: 2023/09/12 10:07:42 by tlam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s2[i] && (i + 1 < n) && s1[i] == s2[i])
	{
		i++;
	}
	return (s1[i] - s2[i]);
}
/*#include <stdio.h>

int main()
{
	char s1[] = "Test1";
	char s2[] = "Test2";
	int nb = ft_strncmp(s1, s2, 5);
	printf("%d\n", nb);
	return 0;
}
*/
