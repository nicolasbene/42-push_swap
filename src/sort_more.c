/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:21:21 by nibenoit          #+#    #+#             */
/*   Updated: 2023/02/03 18:39:26 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//calcule la position actuelle d'un élément dans la liste et détermine combien de rotations sont nécessaires pour le mettre en haut de la liste

int	nb_rot(t_rotbuf buffer)
{
	int	count;

	if (buffer.r_from > buffer.r_to)
		count = buffer.r_from;
	else
		count = buffer.r_to;
	if (buffer.rr_from > buffer.rr_to)
		count += buffer.rr_from;
	else
		count += buffer.rr_to;
	return (count);
}

int	count_move_on_top(t_list **s, int n)
{
	int		ind;
	int		len;
	int		mid;
	t_list	*tmp;

	ind = 1;
	tmp = *s;
	while (tmp->content != n)
	{
		tmp = tmp->next;
		ind++;
	}
	len = ft_lstsize(*s);
	mid = (len / 2) + (len % 2);
	if (ind <= mid)
		return (ind - 1);
	else
		return (ind - len);
}

//calcule le nombre de rotations nécessaires pour insérer un élément dans une autre liste et le classer.
t_rotbuf	insert_move_count(t_list **from, t_list **to, int val)
{
	t_rotbuf	buffer;
	int			count_from;
	int			count_to;

	buffer = (t_rotbuf){0, 0, 0, 0};
	count_from = count_move_on_top(from, val);
	count_to = count_move_on_top(to, get_next_greater_value(*to, val));
	
	if (count_from > 0)
		buffer.r_from = count_from;
	else
		buffer.rr_from = -count_from;
	if (count_to > 0)
		buffer.r_to = count_to;
	else
		buffer.rr_to = -count_to;
	return (buffer);
}

//trouve le moyen le plus rapide de Push A
void	insert_fastest_a(t_list **a, t_list **b)
{
	t_list		*tmp;
	t_rotbuf	buffer;
	t_rotbuf	tmp_buffer;
	int			min;

	tmp = *b;
	buffer = insert_move_count(b, a, tmp->content);
	min = nb_rot(buffer);
	while (tmp)
	{
		tmp_buffer = insert_move_count(b, a, tmp->content);
		if (nb_rot(tmp_buffer) < min)
		{
			min = nb_rot(tmp_buffer);
			buffer = tmp_buffer;
		}
		tmp = tmp->next;
	}
	printf("\n------buffer----\n");
	printf("r_from : %d\n", buffer.r_from);
	printf("r_to : %d\n", buffer.r_to);
	printf("rr_from : %d\n", buffer.rr_from);
	printf("rr_to : %d\n", buffer.r_to);
	

	push(b, a, "pa");
}

void	sort_small(t_list **a, t_list **b)
{
	while ((*a)->next)
		push(a, b, "pb");
	while ((*b))
		insert_fastest_a(a, b);
}
