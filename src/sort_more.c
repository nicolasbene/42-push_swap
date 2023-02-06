/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:21:21 by nibenoit          #+#    #+#             */
/*   Updated: 2023/02/06 18:59:09 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_big(t_list **a, t_list **b)
{
	int	next_greater_chunk;

	while ((*a)->next && (*a)->next->next)
	{
		next_greater_chunk = def_median(*a, ft_lstsize(*a));
		push_median_b(find_min_value(*a), next_greater_chunk, a, b);
	}
	// push(b, a, "pa");
	while (*b)
		insert_fastest_a(a, b);
}

void	sort_small(t_list **a, t_list **b)
{
	while ((*a)->next)
		push(a, b, "pb");
	while ((*b))
		insert_fastest_a(a, b);
}
