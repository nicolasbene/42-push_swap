/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:07:31 by nibenoit          #+#    #+#             */
/*   Updated: 2023/01/24 19:33:36 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_atoi(int ac, char **av)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = 1;
	while (i < ac - 1)
	{
		y = 0;
		while (av[x][y] != 0 && i < ac - 1)
		{
			if (y == 0 && (av[x][y] == '+' || av[x][y] == '-'))
				y++;
			if (av[x][y] == '+' || av[x][y] == '-')
				return (-1);
			y++;
		}
		x++;
		i++;
	}
	if (y > 12)
		return (-1);
	return (0);
}

int	ft_check_ascii(int argc, char **argv)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = 1;
	while (i < argc - 1)
	{
		y = 0;
		while (argv[x][y] != 0 && i < argc - 1)
		{
			if ((argv[x][y] >= '0' && argv[x][y] <= '9') ||
				(argv[x][y] == '-') || (argv[x][y] == '+'))
				y++;
			else
				return (-1);
		}
		x++;
		i++;
	}
	return (0);
}

int	ft_check_doublons(int *stacka, int argc)
{
	int	j;
	int	i;

	i = 0;
	while (i < argc - 1)
	{
		j = i + 1;
		while (j < argc - 1)
		{
			if (stacka[i] == stacka[j])
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_check_unsorted(int *stacka, int ac)
{
	int	j;
	int	i;

	i = 0;
	while (i < ac - 1)
	{
		j = i + 1;
		while (j < ac - 1)
		{
			if (stacka[i] > stacka[j])
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_check_errors(int *stacka, int ac, char **av)
{
	if (ft_check_atoi(ac, av) == -1)
		ft_exit(stacka);
	if (ft_check_ascii(ac, av) == -1)
		ft_exit(stacka);
	if (ft_check_doublons(stacka, ac) == -1)
		ft_exit(stacka);
	if (ft_check_unsorted(stacka, ac) == -1)
	{
		ft_free(stacka);
		exit(0);
	}
	return (0);
}