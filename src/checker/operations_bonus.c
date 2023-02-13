/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 09:41:36 by nibenoit          #+#    #+#             */
/*   Updated: 2023/02/13 13:00:14 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list *s1, t_list *s2, char *msg)
{
	int	tmp;

	if (s1 && s1->next)
	{
		tmp = s1->content;
		s1->content = s1->next->content;
		s1->next->content = tmp;
	}
	if (s2)
		swap(s2, NULL, msg);
	if (!s2 && msg)
		return ;
}

void	push(t_list **from, t_list **to, char *msg)
{
	t_list	*tmp;

	tmp = (*from)->next;
	ft_lstadd_front(to, *from);
	*from = tmp;
	if (msg)
		return ;
}

void	rotate(t_list **s1, t_list **s2, char *msg)
{
	t_list	*last;
	t_list	*first;

	if (s1 && *s1 && (*s1)->next)
	{
		first = *s1;
		*s1 = first->next;
		last = ft_lstlast(first);
		last->next = first;
		first->next = NULL;
	}
	if (s2)
		rotate(s2, NULL, msg);
	if (!s2 && msg)
		return ;
}

void	rev_rotate(t_list **s1, t_list **s2, char *msg)
{
	t_list	*prev;
	t_list	*curr;

	if (s1 && *s1 && (*s1)->next)
	{
		prev = *s1;
		curr = (*s1)->next;
		while (curr->next)
		{
			prev = curr;
			curr = curr->next;
		}
		curr->next = *s1;
		prev->next = NULL;
		*s1 = curr;
	}
	if (s2)
		rev_rotate(s2, NULL, msg);
	if (!s2 && msg)
		return ;
}
