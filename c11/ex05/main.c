/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:42:57 by tlam              #+#    #+#             */
/*   Updated: 2023/09/27 18:03:23 by tlam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <tools.h>

typedef void	(*t_f)(int, int);

int	doop(char c)
{
	if (c == '+')
		return (1);
	if (c == '-')
		return (2);
	if (c == '*')
		return (3);
	if (c == '/')
		return (4);
	if (c == '%')
		return (5);
	else
		return (0);
}

void	voidfn(int value1, int value2)
{
	(void)value1;
	(void)value2;
	ft_putchar('0');
}

int	main(int argc, char **argv)
{	
	int	value1;
	int	value2;
	t_f	func[6];

	if (argc != 4)
		return (1);
	if (ft_strlen(argv[2]) != 1)
	{
		ft_putstr("0\n");
		return (1);
	}
	value1 = ft_atoi(argv[1]);
	value2 = ft_atoi(argv[3]);
	func[0] = &voidfn;
	func[1] = &add;
	func[2] = &sub;
	func[3] = &multiply;
	func[4] = &divide;
	func[5] = &modulo;
	func[doop(argv[2][0])](value1, value2);
	ft_putchar('\n');
	return (0);
}
