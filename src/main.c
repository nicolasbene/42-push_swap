/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 18:20:30 by nibenoit          #+#    #+#             */
/*   Updated: 2023/01/24 19:10:19 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(char *str, int *stacka)
{
	int				i;
	long long int	res;
	int				neg;

	i = 0;
	neg = 1;
	res = 0;
	if (str[i] == '-')
		neg = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - 48);
		i++;
	}
	if (res * neg > INT_MAX || res * neg < INT_MIN)
		ft_exit(stacka);
	return (res * neg);
}

void	ft_free(int *stack)
{
		free(stack);
		stack = NULL;
}

int	main(int ac, char **av)
{
	int	*stacka;
	int	total;
	int	n;

	if (ac < 3)
		ft_exit(stacka);
	stacka = malloc(sizeof(int) * ac - 1);
	if (!stacka)
		return (-1);
	n = 0;
	while (n < ac - 1)
	{
		stacka[n] = ft_atoi(av[n + 1], stacka);
		n++;
	}
	ft_check_errors(stacka, ac, av);
	ft_free(stacka);
	return (n);
}