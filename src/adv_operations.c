/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adv_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:12:32 by nibenoit          #+#    #+#             */
/*   Updated: 2023/02/02 15:10:55 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max_value(t_list *s)
{
	int	max;

	max = s->content;
	while (s)
	{
		if (s->content > max)
			max = s->content;
		s = s->next;
	}
	return (max);
}

int	find_min_value(t_list *s)
{
	int	min;

	min = s->content;
	while (s)
	{
		if (s->content < min)
			min = s->content;
		s = s->next;
	}
	return (min);
}

int	get_next_greater_value(t_list *s, int n)
{
	int	min;
	int	max;
	int	next_greater;

	min = find_min_value(s);
	max = find_max_value(s);

	if (n > max || n < min)
		return (min);
	next_greater = max;
	while(s)
	{
		if (s->content > n && s->content < next_greater)
			next_greater = s->content;
		s = s->next;
	}
	return (next_greater);
}

void	move_nb_top_a(t_list **s, int n)
{
	int		ind;
	int		len;
	t_list	*tmp;

	ind = 1;
	tmp = *s;
	while (tmp->content != n)
	{
		tmp = tmp->next;
		ind++;
	}
	len = ft_lstsize(*s);
	if (ind <= (len / 2) + (len % 2))
		while ((*s)->content != n)
			rotate(s, NULL, "ra");
	else
		while ((*s)->content != n)
			rev_rotate(s, NULL, "rra");
}
