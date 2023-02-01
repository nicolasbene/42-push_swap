/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 12:07:12 by nibenoit          #+#    #+#             */
/*   Updated: 2023/02/01 18:03:23 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_greater_to_bottom(t_list **a)
{
	if ((*a)->content > (*a)->next->content
		&& (*a)->content > (*a)->next->next->content)
		rotate(a, NULL, "ra");
	else if ((*a)->content < (*a)->next->content
		&& (*a)->next->content > (*a)->next->next->content)
		rev_rotate(a, NULL, "rra");
}

void	sort_five(t_list **a, t_list **b, size_t len)
{
	if (len > 3)
		push(a, b, "pb");
	if (len > 4)
		push(a, b, "pb");
	move_greater_to_bottom(a);
	if ((*a)->content > (*a)->next->content)
		swap((*a), NULL, "sa");
	if (len > 3)
	{
		move_stack_a(a, get_greater_value(*a, (*b)->content));
		push(b, a, "pa");
	}
}