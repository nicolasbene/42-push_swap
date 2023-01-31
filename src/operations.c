/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:52:13 by nibenoit          #+#    #+#             */
/*   Updated: 2023/01/31 19:26:04 by nibenoit         ###   ########.fr       */
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
	if (msg && !s2)
		ft_printf("%s\n", msg);
}

void	push(t_list **from, t_list **to, char *msg)
{
	t_list	*tmp;
	tmp = (*from)->next;
	ft_lstadd_front(to, *from);
	*from = tmp;
	if (msg)
		ft_printf("%s\n", msg);
}

void	rotate(t_list **s1, t_list **s2, char *msg)
{
	t_list	*last;

	if (s1 && *s1 && (*s1)->next)
	{
		last = ft_lstlast(*s1);
		last->next = *s1;
		*s1 = (*s1)->next;
		last->next->next = NULL;
	}
	if (s2)
		rotate(s2, NULL, msg);
	if (!s2 && msg)
		ft_printf("%s\n", msg);
}
