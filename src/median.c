/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 18:01:17 by nibenoit          #+#    #+#             */
/*   Updated: 2023/02/07 14:23:31 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	def_median(t_list *a, int len)
{
	int	next_greater;
	int med;

	med = len / 2;
	next_greater = find_min_value(a);
	while (med--)
		next_greater = get_next_greater_value(a, next_greater);
	return (next_greater);
}

void	push_best(t_list *first, t_list *last, t_list **a, t_list **b)
{
	if (!first || !last)
		return ;
	if (ft_abs(count_move_on_top(*a, first->content))
		< ft_abs(count_move_on_top(*a, last->content)))
		move_nb_top_a(a, first->content);
	else
		move_nb_top_a(a, last->content);
	push(a, b, "pb");
}

void	push_median_b(int min, int max, t_list **a, t_list **b)
{
	t_list	*tmp;
	t_list	*first;
	t_list	*last;

	first = *a;
	last = NULL;
	while (first)
	{
		tmp = *a;
		first = NULL;
		while (tmp)
		{
			if (tmp->content >= min && tmp->content <= max)
			{
				if (!first)
					first = tmp;
				last = tmp;
			}
			tmp = tmp->next;
		}
		push_best(first, last, a, b);
	}
}
