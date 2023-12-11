/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 14:44:21 by tlam              #+#    #+#             */
/*   Updated: 2023/09/28 18:47:42 by tlam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int    ft_is_as(int *tab, int length, int (*f)(int, int));
int    ft_is_des(int *tab, int length, int (*f)(int, int));
int    ft_is_sort(int *tab, int length, int (*f)(int, int));

int    ft_is_sort(int *tab, int length, int (*f)(int, int))
{
    return (ft_is_as(tab, length, f) || ft_is_des(tab, length, f));
}

int    ft_is_as(int *tab, int length, int (*f)(int, int))
{
    int    i;

    i = 0;
    while (i + 1 < length)
    {
        if (f(tab[i], tab[i + 1]) < 0)
            return (0);
        i++;
    }
    return (1);
}

int    ft_is_des(int *tab, int length, int (*f)(int, int))
{
    int    i;

    i = 0;
    while (i + 1 < length)
    {
        if (f(tab[i], tab[i + 1]) > 0)
            return (0);
        i++;
    }
    return (1);
}
